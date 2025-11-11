#include "Jogador.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>
using namespace std;

using namespace Entidades::Personagens;


Jogador::Jogador():Personagem(), pontos(0)
{
	pFig->setPosition(10, 300); //setar posiçao padrao na fase.
	forca = 1;
	num_vidas = 10;

}
	//para jogador2, posiçao relativa ao jogador 1, ou ambos aparecem ao mesmo tempo.

/* Posso fazer: (?)
Jogador::Jogador():Personagem():Entidade(5, 10, ...), pontos {}
*/


Jogador::~Jogador() 
{
	if (pFig)
	{
		delete pFig;
		pFig = NULL;
	}
}


void Jogador::danificarInim(Inimigo* pIn)
{
	pIn->num_vidas -= forca;
}


void Jogador::colidir(Inimigo* pIn)
{
	float alturaJog = getFigura()->getGlobalBounds().height;

	if (pos.y + 0.9 * alturaJog < pIn->pos.y) //para o caso de o jogador passar pelo inimigo
											  //ao invés de 0.9, o que poderia ser?
	{
		danificarInim(pIn);
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
	//posição mouse //para debugar
	/* sf::Vector2i posMouse = sf::Mouse::getPosition(*pGG->getWindow());
	setPos(static_cast<float>(posMouse.x), static_cast<float>(posMouse.y));*/

	int keyTimeMax = 10; // delay para mover novamente //faço como atributo(???)
	int keyTime = 0;
	if (keyTime < KeyTimeMax) // para eliminar o atraso, KeyTimeMax = 0;
		keyTime++;

	//implementar para ao invés de aumentar a velocidade, o controle modificar a aceleração ate a velocidade limite.
	//velocidade = velocidade + aceleração;
	//posiçao = posiçao + velocidade; // talvez esse seja melhor para padronizar. Teria que fazer um setPosicao.
	//.move(velocidade); um dos dois.
	//implementar o mesmo para outras entidades.
	if (Keyboard::isKeyPressed(Keyboard::A) && keyTime >= keyTimeMax && vel.x < (-velMax))
	{
		vel.x -= velMax/10; //há uma aceleração
		keyTime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::D) && keyTime >= keyTimeMax && vel.x < velMax)
	{
		vel.x += velMax/10;
		keyTime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::W) && keyTime >= keyTimeMax && vel.y < (-velMax))
	{
		vel.y -= velMax/10; //fazer como velocidade de pulo depois
		keyTime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::S) && keyTime >= keyTimeMax && vel.y < velMax)
	{
		vel.y += velMax/10; //na pratica so a gravidade acelera
		keyTime = 0;
	}
}
//é possivel implementar tambem sem haver uma velocidade maxima, mas a desaceleraçao naturalmente limita


void Jogador::mover()
{
	
	controlar();
	acelerar();
	atualizaVel(); //antes ou depois das acelerações? Testar com ambas formas.

	pFig->move(vel); //ou uso (this)->move ?
}


void Jogador::executar()
{
	mover();
}