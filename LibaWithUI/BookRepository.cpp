#include "BookRepository.h"
#include "GenreRepository.h"
using namespace Model;

namespace Repositories {
	BookRepository::BookRepository(sqlite3* dataBase)
	{
		db = dataBase;
	};
    Book BookRepository::getBookById(int id) {
        string bookQuery = "SELECT id, title, author, year, count, name, description FROM books " 
                           "left join book_genre as bg on bg.book_id = books.id " 
                           "left join genres on bg.genre_name = genres.name WHERE id = ?;";
        sqlite3_stmt* stmt;

        Book book;
        int rc = sqlite3_prepare_v2(db, bookQuery.c_str(), -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        sqlite3_bind_int(stmt, 1, id);

        while (true) {
            if (sqlite3_step(stmt) != SQLITE_ROW)break;
            if (book.id == 0) {
                book.id = sqlite3_column_int(stmt, 0);
                book.title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                book.author = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
                book.year = sqlite3_column_int(stmt, 3);
                book.count = sqlite3_column_int(stmt, 4);
            }
            if (sqlite3_column_text(stmt, 5)) {
                Genre genre{
                    reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)),
                    reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6))
                };
                book.genres.push_back(genre);
            }
        }

        if (book.id == 0) {
            sqlite3_finalize(stmt);
            throw BookNotFound(to_string(id));
        }


        sqlite3_finalize(stmt);
        return book;
    }
    void BookRepository::saveBook(Book* book) {
        const char* err;
        sqlite3_stmt* stmt;
        // Check if the book already exists in the database by checking its ID
        if (book->id == 0) {
            // If the book ID is 0, it means it's a new book and needs to be inserted
            string insertQuery = "INSERT INTO books (title, author, year, count) VALUES (?, ?, ?, ?) returning id;";
            int rc = sqlite3_prepare_v2(db, insertQuery.c_str(), -1, &stmt, NULL);

            if (rc != SQLITE_OK) {
                sqlite3_finalize(stmt);
                throw runtime_error(sqlite3_errmsg(db));
            }

            sqlite3_bind_text(stmt, 1, book->title.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, book->author.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 3, book->year);
            sqlite3_bind_int(stmt, 4, book->count);
            int result = sqlite3_step(stmt);
            if (result != SQLITE_ROW) {
                sqlite3_finalize(stmt);
                throw runtime_error(sqlite3_errmsg(db));
            }
            book->id = sqlite3_column_int(stmt, 0);

        }
        else {
            // If the book ID is not 0, it means it's an existing book and needs to be updated
            getBookById(book->id);
            string updateQuery = "UPDATE books SET title = ?, author = ?, year = ?, count = ? WHERE id = ?;";
            int rc = sqlite3_prepare_v2(db, updateQuery.c_str(), -1, &stmt, NULL);
            if (rc != SQLITE_OK) {
                sqlite3_finalize(stmt);
                throw runtime_error(sqlite3_errmsg(db));
            }

            sqlite3_bind_text(stmt, 1, book->title.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, book->author.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 3, book->year);
            sqlite3_bind_int(stmt, 4, book->count);
            sqlite3_bind_int(stmt, 5, book->id);
        }

        int result = sqlite3_step(stmt);
        if (result != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        sqlite3_finalize(stmt);

        saveGenres(book);
    }
    void BookRepository::saveGenres(const Book* book) {
        sqlite3_stmt* dstm;
        const char* err;
        string deleteQuery = "delete from book_genre where book_id = " + to_string(book->id) + ";";
        int rc = sqlite3_prepare_v2(db, deleteQuery.c_str(), -1, &dstm, NULL);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(dstm);
            throw runtime_error(sqlite3_errmsg(db));
        }

        int result = sqlite3_step(dstm);
        if (result != SQLITE_DONE) {
            sqlite3_finalize(dstm);
            throw runtime_error(sqlite3_errmsg(db));
        }

        sqlite3_finalize(dstm);



        if (book->genres.size()) {
            sqlite3_stmt* stmt;

            GenreRepository genreRepo(db);

            string insertQuery = "insert into book_genre values ";
            char divider = ',';
            size_t genresSize = book->genres.size();
            for (int i = 0; i < genresSize; i++) {
                Genre genre = book->genres[i];
                Genre* genrePtr = &genre;
                genreRepo.saveGenre(genrePtr);
                if (i == genresSize - 1) {
                    divider = ';';
                }
                insertQuery = insertQuery + "(" + to_string(book->id) + "," + '"' + genre.name + '"' + ")" + divider;
            }
            rc = sqlite3_prepare_v2(db, insertQuery.c_str(), -1, &stmt, NULL);
            if (rc != SQLITE_OK) {
                sqlite3_finalize(stmt);
                throw runtime_error(sqlite3_errmsg(db));
            }

            result = sqlite3_step(stmt);
            if (result != SQLITE_DONE) {
                sqlite3_finalize(stmt);
                throw runtime_error(sqlite3_errmsg(db));
            }

            sqlite3_finalize(stmt);
        }
        
    }
    vector<Book> BookRepository::getAllBooks() {
        string bookQuery = "SELECT id, title, author, year, count, name, description FROM books "
            "LEFT JOIN book_genre AS bg ON bg.book_id = books.id "
            "LEFT JOIN genres ON bg.genre_name = genres.name;";
        sqlite3_stmt* stmt;

        vector<Book> books;

        int rc = sqlite3_prepare_v2(db, bookQuery.c_str(), -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int bookId = sqlite3_column_int(stmt, 0);
            if (books.size() && (books.back().id == bookId)) {
                if (sqlite3_column_text(stmt, 5)) {
                    Genre genre{
                        reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)),
                        reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6))
                    };
                    books.back().genres.push_back(genre);
                }
                continue;
            }


            Book book;
            book.id = bookId;
            book.title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            book.author = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            book.year = sqlite3_column_int(stmt, 3);
            book.count = sqlite3_column_int(stmt, 4);

            if (sqlite3_column_text(stmt, 5)) {
                Genre genre{
                    reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)),
                    reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6))
                };
                book.genres.push_back(genre);
            }
            books.push_back(book);
        }

        sqlite3_finalize(stmt);
        return books;
    }
    void BookRepository::deleteBook(int id) {
        // Check if the book exists
        getBookById(id);

        // If the book exists, proceed with deletion
        string deleteQuery = "DELETE FROM books WHERE id = ?;";
        sqlite3_stmt* stmt;

        int rc = sqlite3_prepare_v2(db, deleteQuery.c_str(), -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        sqlite3_bind_int(stmt, 1, id);

        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            throw runtime_error("Failed to delete book.");
        }

        sqlite3_finalize(stmt);
    }

    BookNotFound::BookNotFound(string a):runtime_error(a) {}

}



