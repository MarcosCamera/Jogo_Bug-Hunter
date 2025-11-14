#pragma once

#include "Entidade.hpp"

namespace Entidades
{
	class Projetil : public Entidade
	{
	protected:
		bool ativo;

	public:
		Projetil();
		~Projetil();

		void salvar();
		void executar();
	};
}