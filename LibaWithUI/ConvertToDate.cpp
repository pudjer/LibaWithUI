#include "ConvertToDate.h"

time_t convertToDate(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%d.%m.%Y");
    return mktime(&tm);
}