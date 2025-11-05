#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;


/*=============================================================================================*/

							//QUADRADO ANDANDO NA TELA

constexpr int KeyTimeMax = 0;

static void seed()
{
	srand(time(NULL));
}

void Update(int& keyTime, RectangleShape& shape, RenderWindow& window);
void Draw(RenderWindow& window, RectangleShape& shape);

int main()
{
	int keyTime = 8;
	seed();

	RenderWindow window(VideoMode(480, 480), "Walking Square", sf::Style::Default);
	window.setFramerateLimit(60);
	RectangleShape shape(Vector2f(10.f, 20.f));
	shape.setPosition(Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f));
	shape.setFillColor(Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		Update(keyTime, shape, window);
		Draw(window, shape);
	}

	return 0;
}

void Update(int& keyTime, RectangleShape& shape, RenderWindow& window)
{
	if (keyTime < KeyTimeMax) // para eliminar o atraso, KeyTimeMax = 0;
		keyTime++;
	if (Keyboard::isKeyPressed(Keyboard::A) && keyTime >= KeyTimeMax && shape.getPosition().x > 0)
	{
		shape.move(-10.f, 0.f);
		keyTime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::D) && keyTime >= KeyTimeMax && shape.getPosition().x + shape.getSize().x < window.getSize().x)
	{
		shape.move(10.f, 0.f);
		keyTime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::W) && keyTime >= KeyTimeMax && shape.getPosition().y > 0)
	{
		shape.move(0.f, -10.f);
		keyTime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::S) && keyTime >= KeyTimeMax && shape.getPosition().y + shape.getSize().y < window.getSize().y)
	{
		shape.move(0.f, 10.f);
		keyTime = 0;
	}
}

void Draw(RenderWindow& window, RectangleShape& shape)
{
	window.clear();
	window.draw(shape);
	window.display();
}