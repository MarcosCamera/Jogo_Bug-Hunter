#pragma once
#include <string>
#include <stdlib.h>
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Grafico.hpp"
#include "ListaEntidades.hpp"
#include "Lista.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "Folha.hpp"
#include "Formiga.hpp"
//#include "Menu.hpp"
#include "Parede.hpp"
#include "Ente.hpp" 
#include <vector>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

using namespace std;
namespace Fases
{
    class Fase_Primeira;
    class Fase_Sefunda;

    class Fase : public Ente
    {
    protected:
        Gerenciadores::Gerenciador_Colisoes& gC;
        Gerenciadores::Gerenciador_Grafico* pGG;
        Listas::ListaEntidades lista_ents;
        Entidades::Personagens::Jogador* pJog1;
        Entidades::Personagens::Jogador* pJog2;
        Entidades::Parede* pParedeChao;

        int maxFormiga;
        int minFormiga;
        int maxFolha;
        int minFolha;

        float larguraNivel;
        float alturaNivel;

        //sf::Texture*  texFundo; //nao usa mais
        //sf::Sprite spriteFundo; //nao usa mais

    public:
        Fase(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC);
        virtual ~Fase();
        virtual void executar();

    protected:
        virtual void carregarFase(const std::string& caminho) = 0;
        virtual void gerarFase(vector<vector<vector<int>>> mapa) = 0;
        json lerArquivoJSON(const std::string& caminho);
        vector<vector<vector<int>>> extrairCamadas(const json& mapa);
        
        virtual void criarCenario() = 0; 
        virtual void criarInimigos() = 0;
        virtual void criarObstaculos() = 0;

        virtual void criarParede(Entidades::Parede* pParede, int id_tile) = 0;//mudei os parâmetros passados, tive q fazer isso pq tava não estava pegando os ids certinhos de cada tile
        virtual void criarEntidades(float posX, float posY, int id_tile) = 0;//criei esta função para desacoplar a função gerarFase();
        void criarFormigas();
        void criarFolhas();
        void criarJogador();
    };
} 

