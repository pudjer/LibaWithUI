#pragma once
#include <iostream>

class NotSelected : std::runtime_error {
public:
	NotSelected(std::string msg) :runtime_error(msg) {};
};
