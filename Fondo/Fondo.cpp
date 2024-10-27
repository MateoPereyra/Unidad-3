#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Texture texturaFondo;
Sprite spriteFondo;

int main() {
    if (!texturaFondo.loadFromFile("C:\\Users\\mateo\\source\\repos\\Fondo\\fondo.jpg")) {
        std::cerr << "No se pudo cargar el archivo fondo.jpg" << std::endl;
        return -1;
    }

    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Fondo del Videojuego");

    spriteFondo.setTexture(texturaFondo);

    float scaleX = 800.0f / texturaFondo.getSize().x;
    float scaleY = 600.0f / texturaFondo.getSize().y;

    spriteFondo.setScale(scaleX, scaleY);

    while (App.isOpen())
    {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                App.close();
        }

        App.clear();

        App.draw(spriteFondo);

        App.display();
    }

    return 0;
}
