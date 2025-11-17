#pragma once
#include <string>
#include <stdlib.h>
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Plataforma.hpp"
#include "Inim_Facil.hpp"
#include "ListaEntidades.hpp"
#include "Lista.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "Menu.hpp"
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

using namespace std;
namespace Fases

{

    class Fase : public Ente

    {

    protected:

        Gerenciadores::Gerenciador_Colisoes& gC;
        Gerenciadores::Gerenciador_Grafico* pGG;
        Listas::ListaEntidades lista_ents;
        Entidades::Personagens::Jogador* pJog1;
        int maxInim;
        int minInim;
        sf::Texture*  texFundo;
        sf::Sprite spriteFundo;


    public:

        Fase(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC);
        virtual ~Fase();
        virtual void executar();
        
        


    protected:

        virtual void carregarFase(const std::string& caminho) = 0;
        virtual void gerarFase(vector<vector<vector<int>>> mapa) = 0;
        json lerArquivoJSON(const std::string& caminho);
        vector<vector<vector<int>>> extrairCamadas(const json& mapa);
        //void criarCenario();
        void criarFormigas(float x, float y);
        void criarPlataforma(float x, float y,int id_tile);
        void criarJogador(float x, float y);

};

} 
