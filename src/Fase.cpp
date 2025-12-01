#include "Fase.hpp"

using namespace std;
using namespace Entidades; 
using namespace Entidades::Personagens; 
using namespace Entidades::Obstaculos; 
using namespace Listas;
using namespace Gerenciadores;

namespace Fases
{

Fase::Fase(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC):
    Ente(), gC(gC), pGG(pGG), lista_ents(), lista_projeteis(), pGE(new Gerenciadores::Gerenciador_Eventos(&lista_ents, &gC)), pJog1(NULL), pParedeChao(NULL), maxFormigas(6), minFormigas(3), maxFolhas(4), minFolhas(3), larguraNivel(800.0f), alturaNivel(608.0f)
{
    
    Ente::setpGG(pGG); 
}

Fase::~Fase()
{
   
   lista_ents.limpar();
   if (lista_projeteis) {
        lista_projeteis->limpar(); 
        delete lista_projeteis;
        lista_projeteis = nullptr;
    }
   if (pGE) 
   {
        delete pGE;
        pGE = nullptr;
    }
}

void Fase::executar()
{
    

    if (pJog1 == NULL) {
        
        return; 
    }
    
    if (pGE) {
        
        pGE->executar();
    
    }


     Entidades::Teia* novaTeia = NULL;
    if (pJog1) 
    {
    
         novaTeia = pJog1->atirarTeia(); 
        if (novaTeia) 
        {
           lista_ents.incluir(static_cast<Entidades::Entidade*>(novaTeia));
            if(lista_projeteis) 
            {
                lista_projeteis->incluir(static_cast<Entidades::Entidade*>(novaTeia));
            }
           //gC.incluirTeia(novaTeia); //está coemntado, pq está dando bug nesta parte do código
            
            
        }  
    }
     
     Listas::Lista<Entidades::Entidade>* pLista = lista_ents.getLista();
     

     if (!pLista) {
        
        return;
    }

    
    
     Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade> it = pLista->getIterador();
     
        while (!it.end())
        {  
            
            Entidades::Entidade* pEnt = it.getElemento();
            if (pEnt)
            {
                
                pEnt->executar();
                if (pGE) 
                {
                
                    pGE->percorrer(pEnt); // 
                }
                    
                if (pEnt->getRemover()) 
                {
                
                   Entidades::Personagens::Inimigo* pInim = dynamic_cast<Entidades::Personagens::Inimigo*>(pEnt);
                    if (pInim) {
                        gC.removerInimigo(pInim);
                    }
                    Entidades::Teia* pTeia = dynamic_cast<Entidades::Teia*>(pEnt);
                    if (pTeia) {
                        

                        gC.removerTeia(pTeia);
                          delete pTeia;
                          pLista->remove(pEnt);   
                    }
                    

                    it.proximo();
                    Entidades::Entidade* proximoElemento = (!it.end()) ? it.getElemento() : NULL;
                     pLista->remove(pEnt);
                    delete pEnt; 
                    if (proximoElemento) //Se havia próximo elemento, continua de lá
                        continue;
                    else 
                        break;        
                }
            }
            it.proximo();
        }

        gC.executar();

       if (pGG && pJog1 && pJog1->getFig()) 
        {
            pGG->moverCamera(dynamic_cast<Entidades::Entidade*>(pJog1), NULL); 
        } 
        
        it = pLista->getIterador();
        while (!it.end())
        {
            Entidades::Entidade* pEnt = it.getElemento();
            if (pEnt)
            {
                pEnt->desenhar(); 
            }
            it.proximo();
        } 
            

}


void Fase::criarFormigas(sf::Vector2f pos)

{ 
     
    Entidades::Personagens::Formiga* pInim = new Entidades::Personagens::Formiga(pos); 
    if(pJog1) {
        gC.setJogador(pJog1);
    }

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pInim));
    gC.incluirInimigo(pInim);
   
    
}
/* 
void Fase::criarFolhas(const std::vector<sf::Vector2f>& posicoesFolhas) 
{
     
}
     
    
} */ 

void Fase::criarJogador(sf::Vector2f pos) 
{
     if(pJog1) {
        return;
    }
    else {
        pJog1 = new Jogador(pos); 
        pJog1->setVidas(10);
        lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1));
        gC.setJogador(pJog1); 
    
    }
   
    
}


}








