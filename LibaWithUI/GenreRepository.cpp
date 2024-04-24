#include "GenreRepository.h"


namespace Repositories {
    GenreRepository::GenreRepository(sqlite3* dataBase)
    {
        db = dataBase;
    }

    Genre GenreRepository::getGenre(const char* name) {
        Genre genre;
        sqlite3_stmt* stmt;
        const char* query = "SELECT name, description FROM genres WHERE name = ?";

        int rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);

        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            genre.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            genre.description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        }
        else if (rc == SQLITE_DONE) {
            sqlite3_finalize(stmt);
            throw GenreNotFound(name);
        }
        else {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        sqlite3_finalize(stmt);

        return genre;
    }

    void GenreRepository::saveGenre(const Genre* genre) {
        sqlite3_stmt* stmt;
        const char* query = "INSERT OR REPLACE INTO genres (name, description) VALUES (?, ?)";

        int rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        sqlite3_bind_text(stmt, 1, genre->name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, genre->description.c_str(), -1, SQLITE_STATIC);

        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        sqlite3_finalize(stmt);
    }
    vector<Genre> GenreRepository::getAllGenres() {
        vector<Genre> genres;
        sqlite3_stmt* stmt;
        const char* query = "SELECT name, description FROM genres";

        int rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
            Genre genre;
            genre.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            genre.description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            genres.push_back(genre);
        }

        if (rc != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        sqlite3_finalize(stmt);

        return genres;
    }
    void GenreRepository::deleteGenre(const char* name) {
        const char* query = "DELETE FROM genres WHERE name = ?";
        sqlite3_stmt* stmt;

        int rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);

        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }

        sqlite3_finalize(stmt);
    }

    GenreNotFound::GenreNotFound(string msg) :runtime_error(msg) {};


}
