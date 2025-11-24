#pragma once
#include "Lista.hpp"


namespace Entidades {
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
        void incluir(Entidades::Entidade* pE);//pq dois incluir???
        void percorrer();
        void limpar();
        void retirar(Entidades::Entidade* pE = NULL);
    };

}

