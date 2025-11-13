#include "Personagem.hpp"
namespace Entidades
{
	namespace Personagens
	{

		Personagem::Personagem() :Entidade(), num_vidas(0), forca(0) {}

		Personagem::~Personagem() {}

		void Personagem::setVida(int f)
		{
			num_vidas -= f;
		}

		int Personagem::getVida()const
		{
			return num_vidas;
		}

		int Personagem::getForca()const
		{
			return forca;
		}
	}
}