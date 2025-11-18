#pragma once
#include "Lista.hpp"
#include "Entidade.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>
#include "Gerenciador_Colisoes.hpp"
#include "Fase_Primeira.hpp" 

namespace Entidades //está correto?
{
    class Entidade;
}
using Iterador = Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade>;

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidades::Entidade> LEs;

    public:
        ListaEntidades();
        ~ListaEntidades();
        Lista<Entidades::Entidade>* getLista();
        void incluir(Entidades::Entidade* pE);
        void percorrer();
        void limpar();
    };

}

