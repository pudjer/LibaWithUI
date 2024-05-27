CREATE TABLE IF NOT EXISTS book_loans (
    id           INTEGER       PRIMARY KEY AUTOINCREMENT,
    dateOfIssue  VARCHAR (255) NOT NULL,
    dateOfReturn VARCHAR (255) NOT NULL,
    book_id      INTEGER       NOT NULL,
    client_id    INTEGER       NOT NULL,
    canceled     INTEGER       NOT NULL,
    FOREIGN KEY (
        book_id
    )
    REFERENCES books (id) ON DELETE CASCADE,
    FOREIGN KEY (
        client_id
    )
    REFERENCES clients (id) ON DELETE CASCADE
);