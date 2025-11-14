#pragma once

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

class Personagem
{
protected:
	int direcao; // se 1, está se movendo para direita, 0 esquerda
	bool ground; // 1 se toca no chao, 0 se nao
	float gravidade;
	float velocidadeX; // fazer efeito de inercia
	float velocidadeY; // fazer vely e velx como um vetor 2f.
	//Vector2f xy;
	Sprite persona;
public:
	void inicializar() {}
	Personagem(int d = 1, bool g = false, float gr = 1.0, float vx = 0.0, float vy = 0.0) //Vector2f xy = (0.0f, 0.0f)
		:direcao(d), ground(g), gravidade(gr), velocidadeX(vx), velocidadeY(vy) {
	} //precisa inicializar persona?
	~Personagem() {}
	Sprite* getSprite() { return &persona; }
	void setVelocidadeX(float v)
	{
		velocidadeX = v;
	}
	float getVelocidadeX()const
	{
		return velocidadeX;
	}
	float getVelocidadeY()
	{
		if (ground)
			return 0.0;
		else
			velocidadeY += gravidade;
		return velocidadeY;
	}
	void steped() { ground = true; }
	void setGround() { ground = !ground; }
	bool getGround()const { return ground; }
	void setDirecao() { direcao = -direcao; }
	bool getDirecao()const { return direcao; }
};

class Ant : public Personagem
{
private:
	bool detectar;
	Texture antTex;
public:
	void inicializar() {}
	Ant() :Personagem(), direcao(1), ground(false), gravidade(10.0), velocidadeX(0.0), velocidadeY(0.0)
	{
		if (!antTex.loadFromFile("Textures/ant2.png"))
			throw "nao abriu imagem";
		persona.setTexture(antTex);
		persona.setScale(0.03, 0.03);
	}
	~Ant() {}
	Sprite* getSprite() { return &persona; }
	float getVelocidadeX()const
	{
		return velocidadeX;
	}
	void setVelocidadeX(float v)
	{
		velocidadeX = v;
	}
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
	// fazer um set e um get velocidade separados!!! desacoplamento!!!
	// void executar(){} // executa comportamento da formiga
};

class Spider
{
private:
	bool direcao; // se 1, está se movendo para direita, 0 esquerda
	bool ground; // 1 se toca no chao, 0 se nao
	float gravidade;
	float velocidadeX;
	float velocidadeY;
	Texture spiderTex;
	Sprite spider;
public:
	void inicializar() {}
	Spider() :direcao(true), ground(false), gravidade(1.0), velocidadeX(0.0), velocidadeY(0.0)
	{
		if (!spiderTex.loadFromFile("Textures/spider.png"))
			throw "nao abriu imagem";
		spider.setTexture(spiderTex);
		spider.setScale(0.03, 0.03);
	}
	~Spider() {}
	Sprite* getSprite() { return &spider; }
	float getVelocidadeX()const
	{
		return velocidadeX;
	}
	void setVelocidadeX(float v)
	{
		velocidadeX = v;
	}
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