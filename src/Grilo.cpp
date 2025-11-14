#include "Grilo.hpp"

namespace Entidades
{
	namespace Personagens
	{
		Grilo::Grilo(): Inimigo(), tamanhoSalto(0)
		{

		}
		Grilo::~Grilo()
		{
			if (pFig)
			{
				delete pFig;
				pFig = NULL;
			}
		}

		void Grilo::danificar(Jogador* pJog) //deve ser diferente para cada inimigo
		{
			pJog->setVida(forca);
		}

		void Grilo::mover() //usar timer
		{
			if (chao)
			{
				if (direcao)
					vel.x = velMovMax/3;
				else
					vel.x = -velMovMax/3;
				vel.y = -velMovMax;
				//força normal para cima
			}
			else
			{
				acel.y = gravidade;
			}

			vel.x += acel.x * (nivel_maldade + 1);
			vel.y += acel.y * (nivel_maldade + 1);
			pFig->move(vel);
		}

		void Grilo::salvar()
		{

		}

		void executar()
		{

		}
	}
}