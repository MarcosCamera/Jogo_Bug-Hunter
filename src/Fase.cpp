
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
    Ente(), gC(gC), pGG(pGG), lista_ents(), pJog1(NULL), pParedeChao(NULL), maxInim(6), minInim(3), maxPlat(4), minPlat(3), larguraNivel(608.0f), alturaNivel(800.0f)
{
    
    Ente::setpGG(pGG); 
}

Fase::~Fase()
{
   lista_ents.limpar();
}

void Fase::executar()
{
   
    criarCenario();
    
    
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

    //std::cout << "Posicaojog X: "<< pJog1->getPos().x << "Posicaojog Y: " << pJog1->getPos().y << "\n";
    
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


void Fase::criarParede()
{
    float altura = 100.0f;
    float pos_y = alturaNivel - altura;
    const sf::Vector2f dimensoes(larguraNivel, altura);
    const sf::Vector2f posicao(0.0f, pos_y);
    if(!pParedeChao)
    {
        pParedeChao = new Entidades::Parede(posicao, dimensoes);//qual valor de posição e dimensão posso colocar para plataforma??
        lista_ents.incluir(static_cast<Entidades::Parede*>(pParedeChao));
        gC.setParede(pParedeChao); 
    }
    
    else
    {
       pParedeChao->getCorpo().setPosition(posicao); 

    }
}

void Fase::criarFormigas() 
{
int numFormigas = minInim + rand() % (maxInim - minInim + 1);
 float y = pParedeChao->getPos().y;
for(int i =0;i< numFormigas; i++){
     float x = 100.f + static_cast<float>(rand() % static_cast<int>(larguraNivel - 200.f));
    Inim_Facil* pInim = new Inim_Facil(sf::Vector2f(x, y));
    float altura_inimigo = pInim->getCorpo().getSize().y;
         
        
         float y_corrigido = y- altura_inimigo;
         
         
         pInim->getCorpo().setPosition(x, y_corrigido);
    if(pJog1) {
       pInim->setJogador(pJog1); 
    }

    lista_ents.incluir(static_cast<Entidade*>(pInim));
    gC.incluirInimigo(pInim); 
}
}

void Fase::criarPlataforma() 
{
    if (!pParedeChao)
        return;
    const float min_y = pParedeChao->getPos().y -150.0f;
    const float max_y = min_y + 150.0f;


    int num_plataformas = minPlat + rand() % (maxPlat - minPlat + 1);
  for (int i = 0; i < num_plataformas; i++) {
    float x = static_cast<float>(50 + rand() % static_cast<int>(larguraNivel - 500));
    float y = min_y + static_cast<float>(rand() % static_cast<int>(max_y- min_y));

    Entidades::Obstaculos::Plataforma* pPlat = new Entidades::Obstaculos::Plataforma(sf::Vector2f(x,y),440); 
    lista_ents.incluir(static_cast<Entidade*>(pPlat));
    gC.incluirObstaculo(pPlat);
  } 
    
}

void Fase::criarJogador() 
{
    float posX = larguraNivel/2.0f;
    float posY = alturaNivel - 150.0f;
    if(pJog1) {
        pJog1->getCorpo().setPosition(sf::Vector2f(posX, posY)); 
    }
    else {
        pJog1 = new Jogador(sf::Vector2f(posX, posY)); 
        lista_ents.incluir(static_cast<Entidade*>(pJog1));
        gC.setJogador(pJog1); 
    }
}
void Fase::criarCenario()
{
   
    criarParede();
    criarObstaculos();
    criarInimigos();

}




