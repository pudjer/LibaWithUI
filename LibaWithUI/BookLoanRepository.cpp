#include "BookLoanRepository.h"

namespace Repositories {
	BookLoanRepository::BookLoanRepository(sqlite3* dataBase){
		db = dataBase;
	}
	BookLoanNotFound::BookLoanNotFound(string msg):runtime_error(msg){}


	BookLoan BookLoanRepository::getBookLoanById(int id) {
        std::string sql = "SELECT (id, dateOfIssue, dateOfReturn, book_id, client_id, canceled) FROM book_loans WHERE id = ?;";
        sqlite3_stmt* stmt;
        int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
        if (result != SQLITE_OK) {
            throw std::runtime_error("Failed to prepare SQL statement.");
        }

        result = sqlite3_bind_int(stmt, 1, id);

        result = sqlite3_step(stmt);
        if (result == SQLITE_ROW) {
            BookLoan loan;
            loan.id = sqlite3_column_int(stmt, 0);
            loan.dateOfIssue = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            loan.dateOfReturn = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            int bookId = sqlite3_column_int(stmt, 3);
            int clientId = sqlite3_column_int(stmt, 4);
            loan.canceled = sqlite3_column_int(stmt, 5);
            sqlite3_finalize(stmt);

            // Retrieve book and client information
            BookRepository bookRepo(db);
            ClientRepository clientRepo(db);
            loan.book = bookRepo.getBookById(bookId);
            loan.client = clientRepo.getClientById(clientId);

            return loan;
        }
        else if (result == SQLITE_DONE) {
            sqlite3_finalize(stmt);
            throw BookLoanNotFound("Book loan with specified ID not found");
        }
        else {
            sqlite3_finalize(stmt);
            throw std::runtime_error("Error fetching book loan.");
        }
	}

    void BookLoanRepository::saveBookLoan(BookLoan* bookLoan) {
        BookRepository bookRepo(db);
        ClientRepository clientRepo(db);
        bookRepo.saveBook(&bookLoan->book);
        clientRepo.saveClient(&bookLoan->client);
        std::string sql;
        bool isInsert = false;
        if (bookLoan->id == 0) {
            // Insert a new book loan
            sql = "INSERT INTO book_loans (dateOfIssue, dateOfReturn, book_id, client_id, canceled) VALUES (?, ?, ?, ?, ?) returning id;;";
            isInsert = true;
        }
        else {
            // Update an existing book loan
            sql = "UPDATE book_loans SET dateOfIssue = ?, dateOfReturn = ?, book_id = ?, client_id = ?, canceled = ? WHERE id = ?;";
        }

        sqlite3_stmt* stmt;
        int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
        if (result != SQLITE_OK) {
            throw std::runtime_error("Failed to prepare SQL statement.");
        }


        // Bind parameters
        result = sqlite3_bind_text(stmt, 1, bookLoan->dateOfIssue.c_str(), -1, SQLITE_TRANSIENT);
        result = sqlite3_bind_text(stmt, 2, bookLoan->dateOfReturn.c_str(), -1, SQLITE_TRANSIENT);
        result = sqlite3_bind_int(stmt, 3, bookLoan->book.id);
        result = sqlite3_bind_int(stmt, 4, bookLoan->client.id);
        result = sqlite3_bind_int(stmt, 5, bookLoan->canceled);
        if (!isInsert) {
            result = sqlite3_bind_int(stmt, 6, bookLoan->id);
        }

        // Execute the SQL statement
        result = sqlite3_step(stmt);


        if (isInsert) {
            if (result != SQLITE_ROW) {
                sqlite3_finalize(stmt);
                throw runtime_error(sqlite3_errmsg(db));
            }
            bookLoan->id = sqlite3_column_int(stmt, 0);
        }
        else {
            if (result != SQLITE_DONE) {
                sqlite3_finalize(stmt);
                throw std::runtime_error("Failed to save book loan.");
            }
        }
        sqlite3_finalize(stmt);
    }
}