#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <iostream>
#include <fstream>

class Document {
private:

public:
    std::ifstream file_ptr;
    std::string file_name;

    // Document(std::string& file_name);

    void open_file();
    void init(std::string& file_name);

};

#endif /* DOCUMENT_HPP */