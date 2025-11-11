#include <fstream> 
#include <iostream> 
#include "Fase.hpp"
#include "nlohmann/json.hpp"

using namespace Fases;
using namespace std;
using namespace Entidades;
using namespace Listas; 
using namespace Personagens;
using namespace Gerenciadores;
using namespace nlohmann;

using Iterador = Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade>;

Fase::Fase(std::string mapJson, Gerenciadores::Gerenciador_Colisoes &gc) :
    Ente(),
    gC(gc)
{
    criarCenario(mapJson);
    criarMapa(mapJson);
}

Fase::~Fase()
{
    lista_ents.limpar();
}

void Fase::executar()
{
    lista_ents.percorrer(); 

    gC.executar();
    Gerenciadores::Gerenciador_Grafico* pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
    pGG->desenharCenario();
    if (pGG)
    {
        Iterador it = lista_ents.getLista()->getIterador();
        while (!it.end())
        {
            Entidades::Entidade* pEnt = it.getElemento();
            if (pEnt)
            {
                pGG->desenharEnte(pEnt);
            }
            it.proximo();
        }
    }
}

void Fase::criarInimFaceis(int minInim, int maxInim, sf::Vector2f pos)
{
    int num_inim = minInim + rand() % (maxInim - minInim + 1);
    for(int i =0; i< num_inim;i++)
    {
      Entidades::Personagens::Inim_Facil* pInim = new Entidades::Personagens::Inim_Facil("Textures/formiga2.png", pos);
      lista_ents.incluir(static_cast<Entidade*>(pInim));//static cast!!
      gC.incluirInimigo(pInim);
    }
}

void Fase::criarPlataformas(sf::Vector2f pos)
{
    Entidades::Obstaculos::Plataforma* pPlat = new Entidades::Obstaculos::Plataforma("Textures/plataformas.png", pos, sf::Vector2f(200.0f, 50.0f));
    lista_ents.incluir(static_cast<Entidade*>(pPlat));//static cast!!
    gC.incluirObstaculo(pPlat);
    
}

void Fase::criarJogador(sf::Vector2f pos)
{
   Entidades::Personagens::Jogador* pJog1 = new Entidades::Personagens::Jogador("Textures/aranha.png", pos);
    lista_ents.incluir(static_cast<Entidade*>(pJog1));
}

void Fase::criarCenario(const std::string& caminho)
{
    std::string caminhoTextura = caminho.substr(0, caminho.find_last_of(".")) + ".png";
    
    
    Gerenciadores::Gerenciador_Grafico* pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
    if (pGG)
    {
        pGG->carregarCenario(caminhoTextura);
    }

}

void Fase::criarMapa(const std::string& caminhoJson)
{
    
    std::ifstream arquivo(caminhoJson);
    if (!arquivo.is_open()) {
        std::cerr << "Fase::CriarMapa() -> erro ao carregar o arquivo " << caminhoJson << std::endl;
        return;
    }

    nlohmann::json mapaJson;
    try 
    {
        arquivo >> mapaJson;
    } 
    catch (std::exception& e) 
    {
        std::cerr << "Fase::criarMapa() -> erro" << e.what() << std::endl;
        arquivo.close();
        return;
    }
    arquivo.close();
    const int larguraTiles = mapaJson["tilewidth"];  
    const int alturaTiles = mapaJson["tileheight"]; 
    const int larguraMapa = mapaJson["width"];   

    for (const auto& camada : mapaJson["layers"])
    {
        if (camada["name"] != "Tile Layer 1" || camada["data"].empty()) { 
            continue;
        }

        const auto& data = camada["data"];//está tudo na mesma camada!!
        
        for (int i = 0; i < data.size(); ++i)
        {
            int id = data[i];
            if (id == 0) continue; 

            int coluna = i % larguraMapa;
            int linha = i / larguraMapa;
            float x = static_cast<float>(coluna * larguraTiles);
            float y = static_cast<float>(linha * alturaTiles);
            sf::Vector2f pos(x, y);

            if ((id >= 276 && id < 1004)) 
            {
                int mult = 1;
                while (coluna + mult < larguraMapa && (i + mult) < data.size() && data[i + mult] == id)
                {
                    mult++;
                }

                sf::Vector2f tamanho(static_cast<float>(larguraTiles * mult), static_cast<float>(alturaTiles));
                Entidades::Obstaculos::Plataforma* pPlat = new Entidades::Obstaculos::Plataforma("Textures/tiles.png", pos, tamanho);
                lista_ents.incluir(static_cast<Entidade*>(pPlat));
                gC.incluirObstaculo(pPlat);
                i += mult - 1; 
            }
            // --
            else if (id >= 1004 && id < 1020) 
            {
                criarInimFaceis(minInim, maxInim, pos);
            }
            else if (id >= 1020 && id < 2098)
            {
                
                criarJogador(pos);
            }
            

        } 

    }     
}
