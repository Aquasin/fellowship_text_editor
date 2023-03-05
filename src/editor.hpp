#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <string>
#include <vector>

#include "cursor.hpp"
#include "document.hpp"

class Editor {
private:

public:
    // int curr_line_no;
    std::vector<std::vector<char>> lines;
    Cursor cursor;

public:

    Editor();
    Editor(Document& document, sf::Text& text);

    // std::string vector_to_string();

    void add_to_vector(char ch);

    void add_enter();

    void draw(sf::RenderWindow& window, sf::Text& text);

    void handle_input(int key);
};

#endif /* EDITOR_HPP */