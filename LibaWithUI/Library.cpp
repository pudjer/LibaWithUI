#include <iostream>
#include "GetDb.h"
#include "BookRepository.h"
#include "ClientRepository.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace Repositories;

[STAThreadAttribute]
int main() {

    sqlite3* db;
    
    db = DB::getDb();
    BookRepository bookRepo(db);


    Book book{ "meme", "down", 2022, 3};
    Genre genre{ "porno", "sex" };
    book.genres.push_back(genre);
    bookRepo.saveBook(&book);
    book = bookRepo.getBookById(book.id);
    cout << book.id << endl;
    cout << book.title << endl;
    cout << book.author << endl;
    cout << book.year << endl;
    cout << book.count << endl;
    for (auto genrea : book.genres) {
        cout << genrea.name << endl;
    }
    

    ClientRepository clientRepo(db);
    Client client{ "33300 4444", "Debilov", "Debil", "Debilovich", "Debilovo 1488", "22/22/22" };
    clientRepo.saveClient(&client);
    Client debil = clientRepo.getClientById(1);
    cout << debil.address;
    auto clients = clientRepo.getAllClients();
    for (auto cli : clients) {
        cout<< cli.lastName;
    }
    system("pause");
    return 0;

}
