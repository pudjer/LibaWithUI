#pragma once
#include <string>
#include <vector>
#include "Genre.h"

namespace Model {
    struct Book {
        std::string title;
        std::string author;
        int year;
        unsigned int count;
        std::vector<Genre> genres;
        int id = 0;
    };
}


