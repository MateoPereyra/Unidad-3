#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Texture tNegra, tBlanca;
Sprite tablero[8][8];
int main() {

    if (!tNegra.loadFromFile("C:\\Users\\mateo\\source\\repos\\Ajedrez\\Ajedrez\\chessb.png")) {
        std::cerr << "No se pudo cargar el archivo chessb.png" << std::endl;
        return -1;
    }
    if (!tBlanca.loadFromFile("C:\\Users\\mateo\\source\\repos\\Ajedrez\\Ajedrez\\chessw.png")) {
        std::cerr << "No se pudo cargar el archivo chessw.png" << std::endl;
        return -1;
    }

    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Tablero de Ajedrez");

    float scaleX = 800.0f / (8 * 128.0f);
    float scaleY = 600.0f / (8 * 128.0f);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {

            if ((i + j) % 2 == 0) {
                tablero[i][j].setTexture(tBlanca);
            }
            else {
                tablero[i][j].setTexture(tNegra);
            }

            tablero[i][j].setPosition(i * 128 * scaleX, j * 128 * scaleY);

            tablero[i][j].setScale(scaleX, scaleY);
        }
    }

    while (App.isOpen())
    {
        sf::Event event;
        while (App.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                App.close();
        }

        App.clear();

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                App.draw(tablero[i][j]);
            }
        }

        App.display();
    }

    return 0;
}
