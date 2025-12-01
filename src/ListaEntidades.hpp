#pragma once
#include "Lista.hpp"
#include "Gerenciador_Eventos.hpp"
namespace Gerenciadores {
    class Gerenciador_Eventos;
}

using Iterador = Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade>;

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidades::Entidade> LEs;
        Gerenciadores::Gerenciador_Eventos* pGe;
    public:
        ListaEntidades();
        ListaEntidades(Gerenciadores::Gerenciador_Eventos* ger);
        ~ListaEntidades();
        Lista<Entidades::Entidade>* getLista();
        void incluir(Entidades::Entidade* pE);
        void percorrer();
        void limpar();
        void remover(Entidades::Entidade* pE);

    };

}

