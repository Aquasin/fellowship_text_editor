#ifndef INPUT_EVENTS_HPP
#define INPUT_EVENTS_HPP

#include <SFML/Graphics.hpp>
#include "editor.hpp"

class Input_Events {
private:

public:
    Input_Events();

    void handle_inputs(Editor& editor, sf::RenderWindow& window, Document& document, sf::Event& event);

    void handle_key_pressed(Editor& editor, Document& document, Cursor& cursor, sf::Event& event);
    void handle_text_entered(Editor& editor, sf::Event& event);
};

#endif /* INPUT_EVENTS_HPP */