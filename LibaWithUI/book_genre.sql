CREATE TABLE IF NOT EXISTS book_genre (
    book_id INTEGER NOT NULL,
    genre_name INTEGER NOT NULL,
    PRIMARY KEY (book_id, genre_name),
    FOREIGN KEY (book_id) REFERENCES books(id),
    FOREIGN KEY (genre_name) REFERENCES genres(name)
);