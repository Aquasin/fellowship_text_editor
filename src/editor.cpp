#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include "editor.hpp"

Editor::Editor(Document& document, sf::Text& text) {
    std::string tmp_string;
    cursor.set_offsets(text.getLocalBounds().width, (float)(text.getCharacterSize()));
    std::vector<char> line;

    int line_no = 0;

    while (document.file_ptr) {
        getline(document.file_ptr, tmp_string);

        lines.push_back(line);
        for (auto ch : tmp_string) {
            lines[line_no].push_back(ch);
        }
        ++line_no;
    }
    document.file_ptr.close();
}

// std::string Editor::vector_to_string() {
//     std::string txt = "";
//     for (auto line : lines) {
//         for (auto ch : line) {
//             txt += ch;
//         }
//         txt += "\n";
//     }
//     return txt;
// }

void Editor::add_enter() {
    std::vector<char> temp_line;
    if (cursor.get_row() < lines.size()) {
        if (cursor.get_col() == lines[cursor.get_row()].size()) {
            lines.insert(lines.begin() + cursor.get_row() + 1, temp_line);
        }
        else if (cursor.get_col() < lines[cursor.get_row()].size()) {
            for (int i = cursor.get_col();i < lines[cursor.get_row()].size(); ++i) {
                temp_line.push_back(lines[cursor.get_row()][i]);
            }
            lines[cursor.get_row()].erase(lines[cursor.get_row()].begin() + cursor.get_col(), lines[cursor.get_row()].end());
            lines.insert(lines.begin() + cursor.get_row() + 1, temp_line);
        }
    }
    else {
        lines.push_back(temp_line);
    }
    printf("\nlines size - %d\n", lines.size());
}

void Editor::add_to_vector(char ch) {
    lines[cursor.get_row()].insert(lines[cursor.get_row()].begin() + cursor.get_col(), ch);
    cursor.move_cursor(cursor.get_col() + 1, cursor.get_row());
}


void Editor::handle_input(int key) {

    switch (key) {
    case UP_CURSOR:
        if (cursor.get_row() - 1 >= 0) {
            if (lines[cursor.get_row() - 1].size() < cursor.get_col()) {
                cursor.move_cursor(lines[cursor.get_row() - 1].size(), cursor.get_row() - 1);
            }
            else {
                cursor.move_cursor(cursor.get_col(), cursor.get_row() - 1);
            }
        }
        break;
    case DOWN_CURSOR:
        if (cursor.get_row() + 1 < lines.size()) {
            if (lines[cursor.get_row() + 1].size() < cursor.get_col()) {
                cursor.move_cursor(lines[cursor.get_row() + 1].size(), cursor.get_row() + 1);
            }
            else {
                cursor.move_cursor(cursor.get_col(), cursor.get_row() + 1);
            }

        }
        break;
    case LEFT_CURSOR:
        if (cursor.get_col() - 1 >= 0)
            cursor.move_cursor(cursor.get_col() - 1, cursor.get_row());
        break;
    case RIGHT_CURSOR:
        if (cursor.get_col() < lines[cursor.get_row()].size())
            cursor.move_cursor(cursor.get_col() + 1, cursor.get_row());
        break;
    }
}

void Editor::draw(sf::RenderWindow& window, sf::Text& text) {
    float offsetx = 0;

    // characters
    text.setFillColor(sf::Color(ONE_DARK_FOREGROUND));
    for (int i = 0; i < lines.size();++i) {
        offsetx = 0;
        for (int j = 0;j < lines[i].size();++j) {
            text.setString(lines[i][j]);
            text.setCharacterSize(16);
            text.setPosition(offsetx, i * 20);
            window.draw(text);
            offsetx += cursor.get_x_offset() + 1;
        }
        if (lines[i].size() == 0) {
            text.setString(" ");
            text.setCharacterSize(16);
            text.setPosition(offsetx, i * 20);
        }
    }

    // Sidebar
    text.setFillColor(sf::Color(ONE_DARK_MARGIN_FOREGROUND));
    for (int i = 0; i < lines.size();++i) {
        offsetx = 0;
        text.setString(std::to_string(i + 1));
        text.setCharacterSize(14);
        text.setPosition(-35.f, i * 20 + 3);
        window.draw(text);

        // sf::RectangleShape marginRect(sf::Vector2f(40, 20));
        // marginRect.setFillColor(sf::Color(ONE_DARK_MARGIN_BACKGROUND));
        // marginRect.setPosition(-45.f, i * 20);
        // window.draw(marginRect);
    }

    // Cursor
    sf::RectangleShape cursorRect(sf::Vector2f(2, cursor.get_y_offset() + 2));
    cursorRect.setFillColor(sf::Color::White);

    cursorRect.setPosition(
        (cursor.get_col()) * (cursor.get_x_offset() + 1) + 1.f,
        (cursor.get_row() * (cursor.get_y_offset() + 4)) + 1.f);

    window.draw(cursorRect);
}