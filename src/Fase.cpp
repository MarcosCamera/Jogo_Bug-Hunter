
#include "Fase.hpp"
using namespace Fases;
using namespace std;
using namespace Entidades; 
using namespace Entidades::Personagens; 
using namespace Entidades::Obstaculos; 
using namespace Listas;
using namespace Gerenciadores;

Fase::Fase(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC):
    Ente(), gC(gC), pGG(pGG), lista_ents(), pJog1(NULL), pParedeChao(NULL), maxFormigas(6), minFormigas(3), maxPlataformas(4), minPlataformas(3), larguraNivel(800.0f), alturaNivel(608.0f)
{
    
    Ente::setpGG(pGG); 
}

Fase::~Fase()
{
   lista_ents.limpar();
}

void Fase::executar()
{
   
     Listas::Lista<Entidades::Entidade>* pLista = lista_ents.getLista();
        if (!pLista) return;
        Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade> it = pLista->getIterador();

        while (!it.end())
        {
            Entidades::Entidade* pEnt = it.getElemento();
            if (pEnt)
            {
                pEnt->executar();
                //pEnt->desenhar(); mudei aqui por conta dsa lógica em q a camera funciona
            }
            it.proximo();
        
        }
           gC.executar();
            if (pJog1) 
        {
                 std::cout << "Posicao X: " << pJog1->getPos().x << "Posicao Y: " << pJog1->getPos().y << "\n";

            
            pGG->moverCamera(NULL, pJog1, NULL); 
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



void Fase::criarFormigas() 
{
/*int numFormigas = minInim + rand() % (maxInim - minInim + 1);
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
  }*/
//mudei o código pq não estava conseguindo fazer,ao mesmo tempo, pegar uma posicao aleatoria e criar instancias aleatorias. daí para criar instancias aleatórias, estou usando int chance(está no código das fases derivadas)
     if (!pParedeChao) 
             return; 
        float y_chao = pParedeChao->getPos().y; 
    
        float x = 100.f + static_cast<float>(rand() % static_cast<int>(larguraNivel - 200.f));
        
        Entidades::Personagens::Formiga* pInim = new Entidades::Personagens::Formiga(sf::Vector2f(x, y_chao));
        float altura_inimigo = pInim->getFig()->getGlobalBounds().height;
        float y_corrigido = y_chao - altura_inimigo;
        
        pInim->getFig()->setPosition(x, y_corrigido);
        if(pJog1) {
        pInim->setJogador(pJog1); 
        }

        lista_ents.incluir(static_cast<Entidade*>(pInim));
        gC.incluirInimigo(pInim);
}

void Fase::criarFolhas() 
{
   /* if (!pParedeChao)   
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
    } */

    
        if (!pParedeChao) return; 


        int numPlataformas = minPlataformas + rand() % (maxPlataformas - minPlataformas + 1);
        float y_chao = pParedeChao->getPos().y; 
        for(int i = 0; i < numPlataformas; i++)
        {
            float x = 100.f + static_cast<float>(rand() % static_cast<int>(larguraNivel - 200.f));
            Entidades::Obstaculos::Folha* pFolha = new Entidades::Obstaculos::Folha(sf::Vector2f(x, y_chao));
            float altura_obstaculo = pFolha->getFig()->getGlobalBounds().height;
            float y_corrigido = y_chao - altura_obstaculo;
            
            pFolha->getFig()->setPosition(x, y_corrigido);
            lista_ents.incluir(static_cast<Entidade*>(pFolha));
            gC.incluirObstaculo(pFolha);
        }
    
}

void Fase::criarJogador() 
{
   /* float posX = larguraNivel/2.0f;
    float posY = alturaNivel - 150.0f;
    if(pJog1) {
        pJog1->getCorpo().setPosition(sf::Vector2f(posX, posY)); 
    }
    else {
        pJog1 = new Jogador(sf::Vector2f(posX, posY)); 
        lista_ents.incluir(static_cast<Entidade*>(pJog1));
        gC.setJogador(pJog1); 
    }*/
    float posX = 200.0f;//coloquei estes valores pq era oq dava certo, sinceramente, não sei oq está dando, mas tem alguma função q modifica a posição do jogador, depois de eu ter fixado aqui. No fim, quando eu rodo, o jogador não aparece nessas posições fixas.
    float posY = 416.5f;
    

    if (pJog1) 
    {
        pJog1->setChao(true); // vai ser true no primeiro frame
        pJog1->setVel(sf::Vector2f(0.0f, 0.0f));
        pJog1->getFig()->setPosition(sf::Vector2f(200.0f , 416.5)); //ao inves de corpo, pFig
                          //std::cout << "Posicao X11111: " << pJog1->getPos().x << "Posicao Y11111: " << pJog1->getPos().y << "\n";

    }
    else 
    {
        pJog1 = new Entidades::Personagens::Jogador(sf::Vector2f(200.0f, 416.5));
       // cout<<"posx jogador: "<<posX<<"posy jogador: "<<posY<<endl;
        lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1));
        gC.setJogador(pJog1);
    }
    
}







