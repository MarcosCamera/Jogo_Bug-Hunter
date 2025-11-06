#include "Jogador.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>
using namespace std;

using namespace Entidades::Personagens;


Jogador::Jogador():Personagem(), pontos(0)
{
	pFig->setPosition(10, 500); //em cima de uma plataforma (ninho)
	//setar posiçao padrao na fase. (funçao de entidade)
	//para jogador2, posiçao relativa ao jogador 1, ou ambos aparecem ao mesmo tempo.
}


Jogador::~Jogador() {}


void Jogador::colidir(Inimigo* pIn)
{
	float alturaJog = getFigura()->getGlobalBounds().height;

	if (pos.y + 0.9 * alturaJog < pIn->pos.y) //para o caso de o jogador passar pelo inimigo
	{
		/*danifica inimigo*/
		vel.y = - 0.9 * vel.y // 0.9 relativo a perda de energia. Pode se tornar atributo?
	}
	else
	{
		pIn->danificar(this) //ta certo???
	}
}


void Jogador::salvar(){}//...


void Jogador::controlar()
{
	//posição mouse
	/* sf::Vector2i posMouse = sf::Mouse::getPosition(*pGG->getWindow());
	setPos(static_cast<float>(posMouse.x), static_cast<float>(posMouse.y));*/

	int keyTimeMax = 10; // delay para mover novamente //faço como atributo(???)

	int keyTime = 0;
	if (keyTime < KeyTimeMax) // para eliminar o atraso, KeyTimeMax = 0;
		keyTime++;

	if (Keyboard::isKeyPressed(Keyboard::A) && keyTime >= keyTimeMax && vel.x < (-velMax))
	{
		vel -= (acelera, 0.0);
		keyTime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::D) && keyTime >= keyTimeMax && vel.x < velMax)
	{
		vel += (acelera, 0.0);
		keyTime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::W) && keyTime >= keyTimeMax && vel.y < (-velMax))
	{
		vel -= (0.0, acelera); //fazer como velocidade de pulo depois
		keyTime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::S) && keyTime >= keyTimeMax && vel.y < velMax)
	{
		vel += (0.0, acelera); //na pratica so a gravidade acelera
		keyTime = 0;
	}
}


void Jogador::mover()
{
	cair();
	desacelerar();
	controlar();

	pFig->move(vel);
}


void Jogador::executar()
{
	mover();
}