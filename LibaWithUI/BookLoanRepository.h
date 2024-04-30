#pragma once
#include <sqlite3.h>
#include "BookLoan.h"
#include <iostream>
#include <vector>
#include "BookRepository.h"
#include "ClientRepository.h"


using namespace std;
using namespace Model;


namespace Repositories {
	class BookLoanRepository
	{
	private:
		sqlite3* db;
	public:
		BookLoanRepository(sqlite3* dataBase);
		BookLoan getBookLoanById(int id);
		void createBookLoan(BookLoan* bookLoan);
		vector<BookLoan> getAllBookLoans(bool openOnly = false);
		void closeBookLoan(int id);

	};
	class BookLoanNotFound : runtime_error {
	public:
		BookLoanNotFound(string);
	};
	class NotEnoughBook : runtime_error {
	public:
		NotEnoughBook(string);
	};
}

