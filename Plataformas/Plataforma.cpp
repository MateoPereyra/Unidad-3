#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;

Texture textura;
std::vector<Sprite> plataformas;

int main() {
    if (!textura.loadFromFile("C:\\Users\\mateo\\source\\repos\\Plataformas\\plataforma.jpg")) {
        std::cerr << "No se pudo cargar el archivo plataforma.jpg" << std::endl;
        return -1;
    }

    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Escenario de Plataformas");

    std::vector<float> heights = { 100, 150, 200, 250, 300 };
    float barWidth = 50.0f;
    float gap = 20.0f;

    for (size_t i = 0; i < heights.size(); ++i) {
        Sprite platform;
        platform.setTexture(textura);

        float scaleX = barWidth / textura.getSize().x;
        float scaleY = heights[i] / textura.getSize().y;
        platform.setScale(scaleX, scaleY);

        platform.setPosition(i * (barWidth + gap), 600 - heights[i]);

        plataformas.push_back(platform);
    }
    Sprite horizontalPlatform;
    horizontalPlatform.setTexture(textura);

    float horizontalScaleX = 600.0f / textura.getSize().x;
    float horizontalScaleY = 20.0f / textura.getSize().y;
    horizontalPlatform.setScale(horizontalScaleX, horizontalScaleY);

    horizontalPlatform.setPosition(400.0f, 300.0f);

    plataformas.push_back(horizontalPlatform);

    while (App.isOpen())
    {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                App.close();
        }

        App.clear();

        for (const auto& platform : plataformas) {
            App.draw(platform);
        }

        App.display();
    }

    return 0;
}
