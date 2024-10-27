#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Texture textura;
Sprite sprite;

int main() {

    if (!textura.loadFromFile("C:\\Users\\mateo\\source\\repos\\Rotacion\\plataforma.jpg")) {
        std::cerr << "No se pudo cargar el archivo plataforma.jpg" << std::endl;
        return -1;
    }

    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Rotación del Sprite");

    sprite.setTexture(textura);
    sprite.setOrigin(textura.getSize().x / 2, textura.getSize().y / 2);
    sprite.setPosition(400, 300);

    while (App.isOpen())
    {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                App.close();
        }

        sprite.rotate(1.0f / 100);

        App.clear();

        App.draw(sprite);

        App.display();
    }

    return 0;
}
