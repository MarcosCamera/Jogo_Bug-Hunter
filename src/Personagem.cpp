#include "Personagem.hpp"

namespace Entidades
{
	namespace Personagens
	{

		Personagem::Personagem() :Entidade(), num_vidas(0), impacto(0), disparar(false), timer(0) {}

		Personagem::~Personagem() {}

		void Personagem::perdeVida(int i)
		{
			num_vidas -= i;
		}

		int Personagem::getVida()const
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