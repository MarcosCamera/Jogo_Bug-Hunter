#pragma once

#include "Entidade.hpp"
#include "Personagem.hpp" 

namespace Entidades
{
	class Projetil : public Entidade
	{
	protected:
		bool ativo;
		bool aliado;
		Personagens::Personagem* pAtirador; //só até implementar gerenciador_eventos

	public:
		Projetil(Personagens::Personagem* pAt);
		~Projetil();

		bool getAliado()const;
		void desativar();
		void danificarPersonagem(Personagens::Personagem* pVitima);
		void mover();
		void salvar();
		void executar();
	};
}