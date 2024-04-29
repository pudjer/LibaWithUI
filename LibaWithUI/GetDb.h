#pragma once
#pragma once
#include <vector>
#include <iostream>
#include <sqlite3.h>
#include "execSql.h"
using namespace std;


namespace DB {
    class ConnectionError : public runtime_error {
    public:
        ConnectionError(string);
    };
    sqlite3* getDb();
}