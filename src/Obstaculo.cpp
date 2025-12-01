#include "Obstaculo.hpp"

using namespace std;


namespace Entidades
{
	namespace Obstaculos
	{


		Obstaculo::Obstaculo() : Entidade(sf::Vector2f(0.0f, 0.0f)),/*aqui*/ danoso(false), timer(0) 
		{
			

		}
		

		Obstaculo::~Obstaculo() {}
		void Obstaculo::setDano(bool dano)
		{
       		danoso = dano;
		}

		bool Obstaculo::getDano()
		{
			return danoso;
		}
	}
}
