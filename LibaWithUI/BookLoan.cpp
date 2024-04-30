#include "BookLoan.h"

using namespace std;

using namespace Model;
BookLoanValidationError::BookLoanValidationError(string msg) :runtime_error(msg) {};
BookLoan::BookLoan(string dateOfReturn, Book book, Client client) : book(book), client(client), canceled(false) {
    // Validate date of return pattern (dd.mm.yyyy)
    regex datePattern("^\\d{2}\\.\\d{2}\\.\\d{4}$");
    if (!regex_match(dateOfReturn, datePattern)) {
        throw BookLoanValidationError("");
    }

    // Get current date
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm localTime = *localtime(&now_time);

    // Convert current date to dd.mm.yyyy format
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%d.%m.%Y", &localTime);
    string currentDate(buffer);
    dateOfIssue = currentDate;
    // Check if date of issue is today
    if (convertToDate(currentDate) > convertToDate(dateOfReturn)) {
        cout << currentDate << endl << dateOfReturn;
        throw BookLoanValidationError("do not pick past time");
    }

    // Check if book count is greater than 1
    if (book.count < 1) {
        throw BookLoanValidationError("there is not enough books");
    }

    // Set dateOfReturn
    this->dateOfReturn = dateOfReturn;
}
BookLoan::BookLoan() {};