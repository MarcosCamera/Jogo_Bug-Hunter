#include "Personagem.hpp"
#include "ListaEntidades.hpp"
#include "Projetil.hpp"

namespace Entidades
{
	namespace Personagens
	{

		Personagem::Personagem() :Entidade(sf::Vector2f(0.0, 0.0)), num_vidas(0), impacto(0), timer(0),  disparar(false),lista_projeteis(NULL){}

        Personagem::Personagem(sf::Vector2f pos, Listas::ListaEntidades* p) :Entidade(pos), num_vidas(0), impacto(0),timer(0),  disparar(false), lista_projeteis(p) {}

		Personagem::~Personagem() {}

		void Personagem::setVidas(int vidas)
		{
			num_vidas = vidas;
		}

		void Personagem::perdeVida(int i)
		{
			num_vidas -= i;
		}

		int Personagem::getVidas()const
		{
			return num_vidas;
		}

		int Personagem::getImpacto()const
		{
			return impacto;
		}

		void Personagem::setDisparo(bool d)
		{
			disparar = d;
		}

		bool Personagem::getDisparo()const
		{
			return disparar;
		}
	}
}
