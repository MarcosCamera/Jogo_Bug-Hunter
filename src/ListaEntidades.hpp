#pragma once
#include "Lista.hpp"

namespace Gerenciadores { class Gerenciador_Eventos; }


namespace Entidades
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
        Gerenciadores::Gerenciador_Eventos* pGe;

    public:
        ListaEntidades(Gerenciadores::Gerenciador_Eventos* ger); //usar gE como parametro; 
        ~ListaEntidades();

        Lista<Entidades::Entidade>* getLista();
        void incluir(Entidades::Entidade* pE);
        void remover(Entidades::Entidade* pE);
        void percorrer();
        void limpar();
    };

}

