#include "Obstaculo.hpp"

using namespace std;


namespace Entidades
{
	namespace Obstaculos
	{

		Obstaculo::Obstaculo() : Entidade(), danoso(false), timer(0) 
		{
			//falso por padrão

		}
		/*Obstaculo::Obstaculo(const std::string& caminhoSprite, sf::Vector2f posicao) :
		Entidade(caminhoSprite, posicao), danoso(){}*/

		Obstaculo::~Obstaculo() {}
	}
}