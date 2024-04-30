#pragma once
#include <iostream>
#include "Book.h"
#include "Client.h"
#include <regex>
#include <chrono>
#include "ConvertToDate.h"
using namespace std;
namespace Model {
    struct BookLoan {
        BookLoan();
        BookLoan(string dateOfReturn, Book book, Client client);
        string dateOfIssue;
        string dateOfReturn;
        Book book;
        Client client;
        bool canceled;
        int id = 0;
    };
    class BookLoanValidationError : public runtime_error{
    public:
        BookLoanValidationError(string);
    };
}

