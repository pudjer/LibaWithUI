#include "ClientRepository.h"

namespace Repositories {
    ClientRepository::ClientRepository(sqlite3* dataBase) : db(dataBase) {}

    Client ClientRepository::getClientById(int id) {
        // Prepare SQL statement
        sqlite3_stmt* stmt;
        const char* sql = "SELECT * FROM Clients WHERE id = ?";
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }
        // Bind parameters
        sqlite3_bind_int(stmt, 1, id);

        // Execute statement
        int result = sqlite3_step(stmt);

        // Check if a row is returned
        if (result == SQLITE_ROW) {
            Client client;
            client.id = sqlite3_column_int(stmt, 0);
            client.passportNumber = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            client.lastName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            client.firstName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            client.middleName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
            client.address = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
            client.dateOfBirth = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
            sqlite3_finalize(stmt);
            return client;
        }
        else {
            throw ClientNotFound(to_string(id));
        }

        // No client found with the given ID
        sqlite3_finalize(stmt);
        return Client(); // Return an empty client
    }

    void ClientRepository::saveClient(Client* client) {
        // Prepare SQL statement
        if (client->id == 0) {
            const char* sql = "INSERT INTO Clients (passportNumber, lastName, firstName, middleName, address, dateOfBirth) VALUES (?, ?, ?, ?, ?, ?) returning id;";
            sqlite3_stmt* stmt;
            int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
            if (rc != SQLITE_OK) {
                sqlite3_finalize(stmt);
                throw runtime_error(sqlite3_errmsg(db));
            }
            // Bind parameters
            sqlite3_bind_text(stmt, 1, client->passportNumber.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, client->lastName.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 3, client->firstName.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 4, client->middleName.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 5, client->address.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 6, client->dateOfBirth.c_str(), -1, SQLITE_STATIC);

            // Execute statement
            int result = sqlite3_step(stmt);
            if (result != SQLITE_ROW) {
                sqlite3_finalize(stmt);
                throw runtime_error(sqlite3_errmsg(db));
            }
            client->id = sqlite3_column_int(stmt, 0);
            sqlite3_finalize(stmt);
        }
        else {
            getClientById(client->id);
            const char* sql = "Update Clients set passportNumber = ?, lastName = ?, firstName = ?, middleName = ?, address = ?, dateOfBirth = ? where id = ?;";
            sqlite3_stmt* stmt;
            int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
            if (rc != SQLITE_OK) {
                sqlite3_finalize(stmt);
                throw runtime_error(sqlite3_errmsg(db));
            }
            // Bind parameters
            sqlite3_bind_text(stmt, 1, client->passportNumber.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, client->lastName.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 3, client->firstName.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 4, client->middleName.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 5, client->address.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 6, client->dateOfBirth.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 7, client->id);


            // Execute statement
            auto res = sqlite3_step(stmt);
            if (res != SQLITE_DONE) {
                sqlite3_finalize(stmt);
                throw runtime_error(sqlite3_errmsg(db));
            }
            sqlite3_finalize(stmt);
        }

    }

    vector<Client> ClientRepository::getAllClients() {
        vector<Client> clients;

        // Prepare SQL statement
        const char* sql = "SELECT * FROM Clients";
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }
        // Execute statement
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Client client;
            client.id = sqlite3_column_int(stmt, 0);
            client.passportNumber = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            client.lastName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            client.firstName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            client.middleName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
            client.address = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
            client.dateOfBirth = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
            clients.push_back(client);
        }

        sqlite3_finalize(stmt);
        return clients;
    }

    void ClientRepository::deleteClient(int id) {
        // Prepare SQL statement
        const char* sql = "DELETE FROM Clients WHERE id = ?";
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }
        // Bind parameters
        sqlite3_bind_int(stmt, 1, id);

        // Execute statement
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    vector<Client> ClientRepository::searchByFIO(char* fio) {
        vector<Client> clients;

        // Prepare SQL statement
        const char* sql = "SELECT * FROM Clients WHERE lastName || ' ' || firstName || ' ' || middleName LIKE ?";
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            throw runtime_error(sqlite3_errmsg(db));
        }
        // Bind parameters
        sqlite3_bind_text(stmt, 1, fio, -1, SQLITE_STATIC);

        // Execute statement
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Client client;
            client.id = sqlite3_column_int(stmt, 0);
            client.passportNumber = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            client.lastName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            client.firstName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            client.middleName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
            client.address = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
            client.dateOfBirth = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
            clients.push_back(client);
        }

        sqlite3_finalize(stmt);
        return clients;
    }


    ClientNotFound::ClientNotFound(string msg) : runtime_error(msg) {};
}

