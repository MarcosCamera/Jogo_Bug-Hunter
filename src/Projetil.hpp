#pragma once

#include "Entidade.hpp"
#include "Personagem.hpp" 

namespace Entidades
{
	namespace Personagens
    {
        class Personagem;
    }
	class Projetil : public Entidade
	{
	protected:
		bool ativo;
		bool aliado;
		short int impacto;

	public:
		Projetil(bool al, short int i, float posX, float posY);
		~Projetil();

		bool getAliado()const;
		bool getAtividade()const;
		void desativar();
		virtual void danificarPersonagem(Personagens::Personagem* pVitima)=0;
		virtual void mover()=0;
		virtual void executar()=0;
	};
}