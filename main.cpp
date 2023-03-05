#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

// User headers
#include "src/input_events.hpp"
#include "src/document.hpp"
#include "src/constants.hpp"
#include "src/editor.hpp"

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Editor Window");

    sf::View view(sf::FloatRect(-45.f, 0.f, 800.f, 600.f));

    sf::Font roboto_font;
    // For Font
    if (!roboto_font.loadFromFile("fonts/Roboto_Mono/RobotoMono-Medium.ttf")) {
        std::cout << "Font not able to laod" << std::endl;
    }

    // Text
    sf::Text text;
    text.setFont(roboto_font);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color(ONE_DARK_FOREGROUND));
    // text.setPosition(10.0f, 5.0f);

    text.setString("M");

    // Document class
    std::string file_name = "file/text_file.txt";
    Document document;
    document.init(file_name);

    // Editor class
    Editor editor(document, text);

    // Input Events class
    Input_Events input_events;

    sf::Clock clock;
    // clock.restart();

    // float zoomVal = 1.f;

    // sf::RectangleShape rectangle(sf::Vector2f(50.f,600.f));

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {

            // "close requested" event
            if (event.type == sf::Event::Closed) {
                document.file_ptr.close();
                window.close();
            }

            input_events.handle_inputs(editor, window, document, event);
        }

        // clear the window with black color
        window.clear(sf::Color(ONE_DARK_BACKGROUND));

        window.setView(view);
        // draw everything here...
        // window.draw(...);
        // window.draw(shape);

        // text.setString(editor.vector_to_string());

        editor.draw(window, text);

        // end the current frame
        window.display();
    }

    return 0;
}