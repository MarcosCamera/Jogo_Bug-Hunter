#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace sf;
using namespace std;

static void seed()
{
	srand(time(NULL));
}

class Ant
{
private:
	bool direcao; //se 1, está se movendo para direita, 0 esquerda
	bool ground; // 1 se toca no chao, 0 se nao
	float gravidade;
	float velocidadeY;
	Texture antTex;
	Sprite ant;
public:
	void inicializar(){}
	Ant():direcao(true), gravidade(0.01), velocidadeY(0.0), ground(false)
	{
		if (!antTex.loadFromFile("Textures/ant2.png"))
			throw "nao abriu imagem";
		ant.setTexture(antTex);
		ant.setScale(0.03, 0.03);
	}
	~Ant(){}
	Sprite* getSprite() { return &ant; }
	float getVelocidadeY()
	{
		if (ground)
			return 0.0;
		else
			velocidadeY += gravidade;
		return velocidadeY;
	}
	void steped() 
	{ 
		ground = true;
		velocidadeY = 0;
	}
	void turned() { direcao = !direcao; }
	bool getGround()const { return ground; }
	bool getDirecao()const { return direcao; }
};

class Spider
{
private:
	bool direcao; // se 1, está se movendo para direita, 0 esquerda
	bool ground; // 1 se toca no chao, 0 se nao
	float gravidade;
	float velocidadeY;
	Texture spiderTex;
	Sprite spider;
public:
	void inicializar() {}
	Spider():direcao(true), gravidade(1.0), velocidadeY(0.0), ground(false)
	{
		if (!spiderTex.loadFromFile("Textures/spider.png"))
			throw "nao abriu imagem";
		spider.setTexture(spiderTex);
		spider.setScale(0.03, 0.03);
	}
	~Spider() {}
	Sprite* getSprite() { return &spider; }
	float getVelocidadeY()
	{
		if (ground)
			return 0.0;
		else
			velocidadeY += gravidade;
			return velocidadeY;
	}
	void steped() { ground = true; }
	bool getGround()const { return ground; }
	bool getDirecao()const { return direcao; }
};

int main()
{
	RenderWindow window(VideoMode(640, 480), "Spider Mini-Game", sf::Style::Default);
	window.setFramerateLimit(60);

	Spider player;
	Ant formiga;
	list<Ant> Ants;

	/*Texture spiderTex;
	Sprite spider;
	if(!spiderTex.loadFromFile("Textures/spider.png")) // testa se abre imagem e ja utiliza
		throw "nao abriu imagem"; //
	spider.setTexture(spiderTex);
	spider.setScale(Vector2f(0.03f, 0.03f));*/

	/*Texture antTex;
	Sprite ant;
	if (!antTex.loadFromFile("Textures/ant2.png"))
		throw "nao abriu imagem";
	ant.setTexture(antTex);
	ant.setScale(0.03f, 0.03f);*/

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		/*UPDATE*/
		
		/* player */
		player.getSprite()->setPosition(static_cast<float>(Mouse::getPosition(window).x), static_cast<float>(Mouse::getPosition(window).y));

		/* enemies */
		formiga.getSprite()->move(0.f, formiga.getVelocidadeY());
		if (formiga.getSprite()->getPosition().y + formiga.getSprite()->getGlobalBounds().height >= window.getSize().y)
			formiga.steped();
		
		if (formiga.getGround())
		{
			if (formiga.getSprite()->getPosition().x + formiga.getSprite()->getGlobalBounds().width >= window.getSize().x
				|| formiga.getSprite()->getPosition().x <= 0)
			{
				formiga.turned();
				formiga.getSprite()->move(static_cast<float>(formiga.getDirecao() ? 1.0f : -1.0f), 0.0f); // para nao travar nos cantos
			}

			if (formiga.getDirecao())
				formiga.getSprite()->move(10.0, 0.0);
			else
				formiga.getSprite()->move(-10.0, 0.0);
		}
		/* projectiles */


		/* obstacles */

		/* colisoes */



		/*DRAW*/
		window.clear(Color::White);
		window.draw(*player.getSprite());
		window.draw(*formiga.getSprite());
		window.display();
	}
	return 0;
}