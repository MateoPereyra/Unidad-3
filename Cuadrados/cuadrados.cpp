#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Texture texturaRoja, texturaAm, texturaAzul, texturaN;
Sprite spriteRojo, spriteAm, spriteAzul, spriteN;

int main() {
    if (!texturaRoja.loadFromFile("C:\\Users\\mateo\\source\\repos\\Cuadrados\\cuad_red.png") ||
        !texturaAm.loadFromFile("C:\\Users\\mateo\\source\\repos\\Cuadrados\\cuad_yellow.png") ||
        !texturaAzul.loadFromFile("C:\\Users\\mateo\\source\\repos\\Cuadrados\\cuad_blue.png") ||
        !texturaN.loadFromFile("C:\\Users\\mateo\\source\\repos\\Cuadrados\\chessb.png")) {
        std::cerr << "No se pudo cargar uno o más archivos de imagen" << std::endl;
        return -1;
    }

    sf::RenderWindow App(sf::VideoMode(800, 800, 32), "Cuadrado de Imagenes");

    spriteRojo.setTexture(texturaRoja);
    spriteAm.setTexture(texturaAm);
    spriteAzul.setTexture(texturaAzul);
    spriteN.setTexture(texturaN);

    float targetSize = 400.0f;

    spriteRojo.setScale(targetSize / texturaRoja.getSize().x, targetSize / texturaRoja.getSize().y);
    spriteAm.setScale(targetSize / texturaAm.getSize().x, targetSize / texturaAm.getSize().y);
    spriteAzul.setScale(targetSize / texturaAzul.getSize().x, targetSize / texturaAzul.getSize().y);
    spriteN.setScale(targetSize / texturaN.getSize().x, targetSize / texturaN.getSize().y);

    spriteRojo.setPosition(0, 0);
    spriteAm.setPosition(400, 0); /
        spriteBlue.setPosition(0, 400);
    spriteN.setPosition(400, 400);

    while (App.isOpen())
    {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                App.close();
        }

        App.clear();

        App.draw(spriteRojo);
        App.draw(spriteAm);
        App.draw(spriteAzul);
        App.draw(spriteN);

        App.display();
    }

    return 0;
}
