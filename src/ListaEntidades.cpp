#include "ListaEntidades.hpp"

using namespace  std;

using Iterador = Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade>;

namespace Listas
{
    ListaEntidades::ListaEntidades(Gerenciadores::Gerenciador_Eventos* ger) 
    {
        pGe = ger;
    }

    ListaEntidades::~ListaEntidades()
    {
        limpar();
    }

    Lista<Entidades::Entidade>* ListaEntidades::getLista()
    {
        return &LEs;
    }

    void ListaEntidades::incluir(Entidades::Entidade* pE)
    {
        if (pE)
        {
            LEs.incluir(pE);
        }
        else
            cout << "ListaEntidades::incluir() -> Entidade* pE NULL" << endl;
    }

    void ListaEntidades::percorrer()
    {

        Iterador it = LEs.getIterador();

        pGe->setNumeroFormigas(0);
        pGe->setNumeroFormigueiros(0);
        while (!it.end())
        {

            Entidades::Entidade* pEntidade = it.getElemento();
            if (pEntidade)
            {
                pGe->percorrer(pEntidade);
                pEntidade->executar();
            }
            it.proximo();
        }
        Entidades::Personagens::Formiga::setNumeroFormigas(pGe->getNumeroFormigas());
        Entidades::Obstaculos::Formigueiro::setNumeroFormigueiros(pGe->getNumeroFormigueiros());
    }


    void ListaEntidades::limpar()
    {
        LEs.limpar();
    }
}