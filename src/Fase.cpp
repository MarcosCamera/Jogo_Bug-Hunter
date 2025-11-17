
#include "Fase.hpp"
#include <iostream> 
#include "Jogador.hpp"
#include "Inim_Facil.hpp"
#include "Plataforma.hpp"
#include "Ente.hpp" 
using namespace Fases;
using namespace std;
using namespace Entidades; 
using namespace Entidades::Personagens; 
using namespace Entidades::Obstaculos; 
using namespace Listas;
using namespace Gerenciadores;

Fase::Fase(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC):
    Ente(), gC(gC), pGG(pGG), lista_ents(), pJog1(NULL), maxInim(0), minInim(0)
{
    
    Ente::setpGG(pGG); 
}

Fase::~Fase()
{
   lista_ents.limpar();
}

void Fase::executar()
{
   
    
    Lista<Entidade>* pLista = lista_ents.getLista();
    if (!pLista) return;
    Lista<Entidade>::Iterador<Entidade> it = pLista->getIterador();
    
    while (!it.end())
    {
        Entidade* pEnt = it.getElemento();
        if (pEnt)
        {
            pEnt->executar();
            pEnt->desenhar();
        }
        it.proximo();
    }
}

json Fase::lerArquivoJSON(const std::string& caminho) {
    ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        cerr << "nao foi possivel abrir o arquivo JSON: " << caminho << endl;
        throw std::runtime_error("Nao foi possivel abrir o arquivo JSON: " + caminho);
    }
    json j;
    arquivo >> j;
    arquivo.close();
    return j;
}

vector<vector<vector<int>>> Fase::extrairCamadas(const json& mapa) {
    int altura = mapa["height"];
    int largura = mapa["width"];
    int numLayers = mapa["layers"].size();
    vector<vector<vector<int>>> camadas;

    for (int k = 0; k < numLayers; k++) {
        const auto& layer = mapa["layers"][k];
        
        if(layer["type"] != "tilelayer") {
            continue; 
        }

        const auto& data = layer["data"];
        
        vector<vector<int>> camada2D(altura, vector<int>(largura));
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                camada2D[i][j] = data[i * largura + j];
            }
        }
        camadas.push_back(camada2D);
    }
    return camadas;
}


void Fase::criarFormigas(float posX, float posY) 
{
    
    Inim_Facil* pInim = new Inim_Facil(sf::Vector2f(posX, posY));
    if(pJog1) {
       pInim->setJogador(pJog1); 
    }

    lista_ents.incluir(static_cast<Entidade*>(pInim));
    gC.incluirInimigo(pInim); 
}

void Fase::criarPlataforma(float posX, float posY, int id_tile) 
{
    
    Entidades::Obstaculos::Plataforma* pPlat = new Entidades::Obstaculos::Plataforma(sf::Vector2f(posX, posY), id_tile); 
    lista_ents.incluir(static_cast<Entidade*>(pPlat));
    gC.incluirObstaculo(pPlat); 
    
}

void Fase::criarJogador(float posX, float posY) 
{
    
    if(pJog1) {
        pJog1->getCorpo().setPosition(sf::Vector2f(posX, posY)); 
    }
    else {
        pJog1 = new Jogador(sf::Vector2f(posX, posY)); 
        lista_ents.incluir(static_cast<Entidade*>(pJog1));
        gC.setJogador(pJog1); 
    }
}
/*void Fase::criarCenario()
{
   


}*/

