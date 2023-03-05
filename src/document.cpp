#include <iostream>
#include "document.hpp"

void Document::init(std::string& file_name) {
    std::string line;
    this->file_name = file_name;
    this->file_ptr.open(this->file_name, std::ios::out | std::ios::in);
}

void Document::open_file() {
    this->file_ptr.open(this->file_name, std::ios::out | std::ios::in);
}