#include "GetDb.h"


namespace DB {

    ConnectionError::ConnectionError(string msg) : runtime_error(msg) {}
    sqlite3* getDb() {
        sqlite3* db;
        vector<string> paths{
            "book_genre.sql",
            "book_loans.sql",
            "clients.sql",
            "books.sql",
            "genres.sql",
        };
        int rc;
        rc = sqlite3_open("example.db", &db);
        if (rc) {
            throw ConnectionError(sqlite3_errmsg(db));
        }
        execManyFiles(paths, db);

        return db;
    }
}