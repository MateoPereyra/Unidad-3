#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Texture textura;
Sprite sprite1, sprite2, sprite3, sprite4;

int main() {

	textura.loadFromFile("C:\\Users\\mateo\\source\\repos\\Sniper\\Sniper\\circle.png");

	sprite1.setTexture(textura);
	sprite1.setPosition(0, 0);

	sprite2.setTexture(textura);
	sprite2.setPosition((800 - 128), 0);

	sprite3.setTexture(textura);
	sprite3.setPosition(0, (600 - 128));

	sprite4.setTexture(textura);
	sprite4.setPosition((800 - 128), (600 - 128));

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Sniper");

	while (App.isOpen())
	{
		App.clear();

		App.draw(sprite1);
		App.draw(sprite2);
		App.draw(sprite3);
		App.draw(sprite4);

		App.display();
	}

	return 0;
}
