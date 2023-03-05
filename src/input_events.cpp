#include <stdio.h>
#include "constants.hpp"
#include "input_events.hpp"

Input_Events::Input_Events() {

}

void Input_Events::handle_inputs(Editor& editor, sf::RenderWindow& window, Document& document, sf::Event& event) {

    handle_key_pressed(editor, document, editor.cursor, event);
    handle_text_entered(editor, event);
}

void Input_Events::handle_key_pressed(Editor& editor, Document& document, Cursor& cursor, sf::Event& event) {
    bool cntr_pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            editor.handle_input(UP_CURSOR);
        }
        if (event.key.code == sf::Keyboard::Down) {
            editor.handle_input(DOWN_CURSOR);
        }
        if (event.key.code == sf::Keyboard::Left) {
            editor.handle_input(LEFT_CURSOR);
        }
        if (event.key.code == sf::Keyboard::Right) {
            editor.handle_input(RIGHT_CURSOR);
        }

        if (event.key.code == sf::Keyboard::BackSpace) {
            if (cursor.get_row() == 0 && cursor.get_col() == 0) {
                return;
            }
            if (cursor.get_col() == 0) {
                if (editor.lines[cursor.get_row()].size() == 0) {
                    editor.lines.erase(editor.lines.begin() + cursor.get_row(), editor.lines.begin() + cursor.get_row() + 1);
                    cursor.move_cursor(editor.lines[cursor.get_row() - 1].size(), cursor.get_row() - 1);
                }
                else {
                    int temp_loc = editor.lines[cursor.get_row() - 1].size();
                    for (int i = 0;i < editor.lines[cursor.get_row()].size();++i) {
                        editor.lines[cursor.get_row() - 1].push_back(editor.lines[cursor.get_row()][i]);
                    }
                    editor.lines.erase(editor.lines.begin() + cursor.get_row(), editor.lines.begin() + cursor.get_row() + 1);
                    cursor.move_cursor(temp_loc, cursor.get_row() - 1);
                }
            }
            else {
                editor.lines[cursor.get_row()].erase(editor.lines[cursor.get_row()].begin() + cursor.get_col() - 1, editor.lines[cursor.get_row()].begin() + cursor.get_col());
                cursor.move_cursor(cursor.get_col() - 1, cursor.get_row());
            }
        }

        if (event.key.code == sf::Keyboard::Delete) {
            if (cursor.get_col() == editor.lines[cursor.get_row()].size()) {
                if (cursor.get_row() + 1 < editor.lines.size()) {
                    for (int i = 0;i < editor.lines[cursor.get_row() + 1].size();++i) {
                        editor.lines[cursor.get_row()].push_back(editor.lines[cursor.get_row() + 1][i]);
                    }
                    editor.lines.erase(editor.lines.begin() + (cursor.get_row() + 1), editor.lines.begin() + (cursor.get_row() + 2));
                }
            }
            else {
                editor.lines[cursor.get_row()].erase(editor.lines[cursor.get_row()].begin() + cursor.get_col(), editor.lines[cursor.get_row()].begin() + cursor.get_col() + 1);
                cursor.move_cursor(cursor.get_col(), cursor.get_row());
            }
        }
        if (event.key.code == sf::Keyboard::Enter) {
            editor.add_enter();
            cursor.move_cursor(0, cursor.get_row() + 1);
            return;
        }
        if (cntr_pressed && event.key.code == sf::Keyboard::S) {
            std::ofstream output_file(document.file_name);
            for (int i = 0;i < editor.lines.size();++i) {
                for (int j = 0;j < editor.lines[i].size();++j) {
                    output_file << editor.lines[i][j];
                }
                output_file << std::endl;
            }
            output_file.close();
        }
    }
}

void Input_Events::handle_text_entered(Editor& editor, sf::Event& event) {
    bool enter_pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
    bool backspace_pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace);
    bool cntr_pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
    if (!cntr_pressed && !enter_pressed && !backspace_pressed && event.type == sf::Event::TextEntered) {
        editor.add_to_vector((char)event.text.unicode);
    }
}
