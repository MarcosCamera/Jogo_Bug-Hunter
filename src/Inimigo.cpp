#include "Inimigo.hpp"

namespace Entidades
{
	namespace Personagens
	{
		Inimigo::Inimigo() :Personagem(sf::Vector2f(0.0f, 0.0f), NULL),nivel_maldade(0){}

		Inimigo::Inimigo(sf::Vector2f pos, Listas::ListaEntidades* p ) : Personagem(pos, p), nivel_maldade(0){}
		Inimigo:: ~Inimigo() {}
        
		void Inimigo::setMaldade(int m)
		{
			nivel_maldade = m;
		}

		int Inimigo::getMaldade()
		{
			return nivel_maldade;
		}
		
		void Inimigo::operator++()
		{
			nivel_maldade++;
		}

		void Inimigo::operator--()
		{
			nivel_maldade--;
		}

		
	}
}
