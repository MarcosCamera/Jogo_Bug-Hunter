/*#include "Ente.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Formiga.hpp"
#include "Grilo.hpp"
#include "LouvaDeus.hpp"
#include "Folha.hpp"
#include "Formigueiro.hpp"
#include "PlantaCarnivora.hpp"
#include "Parede.hpp"
#include "Jogador.hpp"
#include "Projetil.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace Gerenciadores;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;
using namespace Entidades;
using namespace sf;

int main()
{
	Gerenciador_Grafico graf;
	Gerenciador_Colisoes colis;

	Jogador jog;
	Ente* eJog = &jog;
	jog.setTexture("Texturas/aranha.png", sf::Vector2f(0.03f, 0.03f));
	jog.setPos(sf::Vector2f(200, 400));
	colis.setJogador(&jog);

	Formiga form(sf::Vector2f(0, 400));
	Ente* eForm = &form;
	form.setTexture("Texturas/formiga.png", sf::Vector2f(0.03f, 0.03f));
	form.setPos(sf::Vector2f(0, 400));
	colis.incluirInimigo(&form);

	Grilo gril;
	Ente* eGril = &gril;
	gril.setTexture("Texturas/grilo.png", sf::Vector2f(1.f, 1.f));
	gril.setPos(sf::Vector2f(0, 400));
	colis.incluirInimigo(&gril);

	LouvaDeus ld;
	Ente* eLd = &ld;
	ld.setTexture("Texturas/louvaDeus.png", sf::Vector2f(1.f, 1.f));
	ld.setPos(sf::Vector2f(0, 400));
	colis.incluirInimigo(&ld);

	Folha fol(sf::Vector2f(0.f, 0.f)); 
	Ente* eFol = &fol;
	fol.setTexture("Texturas/folha.png", sf::Vector2f(1.f, 1.f));
	fol.setPos(sf::Vector2f(430, 400));
	colis.incluirObstaculo(&fol);

	Formigueiro formig(sf::Vector2f(0.f,0.f), 1);
	Ente* eFormig = &formig;
	formig.setTexture("Texturas/formigueiro.png", sf::Vector2f(0.03f, 0.03f));
	formig.setPos(sf::Vector2f(460, 400));
	colis.incluirObstaculo(&formig);

	PlantaCarnivora pc(sf::Vector2f(0.f, 0.f));
	Ente* ePc = &pc;
	pc.setTexture("Texturas/plantaCarnivora.png", sf::Vector2f(0.07f, 0.07f));
	pc.setPos(sf::Vector2f(490, 400));
	colis.incluirObstaculo(&pc);

	Parede plat1(sf::Vector2f(0, 500));
	Ente* ePlat1 = &plat1;
	plat1.setTexture("Texturas/parede.png", sf::Vector2f(100.f, 100.f));
	plat1.setPos(sf::Vector2f(0, 500));
	colis.incluirParede(&plat1);

	Parede plat2(sf::Vector2f(0, 480));
	Ente* ePlat2 = &plat2;
	plat2.setTexture("Texturas/parede.png", sf::Vector2f(1.f, 1.f));
	plat2.setPos(sf::Vector2f(0, 480));
	colis.incluirParede(&plat2);

	Parede plat3(sf::Vector2f(400, 480));
	Ente* ePlat3 = &plat3;
	plat3.setTexture("Texturas/parede.png", sf::Vector2f(1.f, 1.f));
	plat3.setPos(sf::Vector2f(400, 480));
	colis.incluirParede(&plat3);

	while (graf.abertaJanela())
	{
		Event event;
		while (graf.getWindow().pollEvent(event))
		{
			if (event.type == Event::Closed)
				graf.fecharJanela();
		}

		//UPDATE

		colis.executar(); //deve ser primeiro?

		jog.executar();
		form.executar();
		gril.executar();
		pc.executar();
		fol.executar();
		formig.executar();
		pc.executar();
		plat1.executar();
		plat2.executar();
		plat3.executar();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			jog.setPos(sf::Vector2f(30, 300));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			form.setPos(sf::Vector2f(80, 300));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			gril.setPos(sf::Vector2f(80, 300));;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			ld.setPos(sf::Vector2f(80, 300));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			form.setPos(sf::Vector2f(80, 800));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			gril.setPos(sf::Vector2f(80, 800));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			ld.setPos(sf::Vector2f(80, 800));
		}

		
		//if (ld.getDisparo())
		//{
		//	ld.setDisparo(false);

		//	Projetil pj(&ld);
		//	Ente* ePj = &pj;
		//	jog.setTexture("Texturas/projetil.png", sf::Vector2f(1.f, 1.f));
		//}

		//DRAW
		graf.getWindow().clear(Color::White);

		graf.desenharEnte(eJog);
		graf.desenharEnte(eForm);
		graf.desenharEnte(eGril);
		graf.desenharEnte(eLd);
		graf.desenharEnte(eFol);
		graf.desenharEnte(eFormig);
		graf.desenharEnte(ePc);
		graf.desenharEnte(ePlat1);
		graf.desenharEnte(ePlat2);
		graf.desenharEnte(ePlat3);
		//graf.desenharEnte(ePj);
		
		graf.getWindow().display();
	}
	return 0;
}
*/


#include "Jogo.hpp"

int main()
{
	Jogo jogo;
	jogo.executar();
	return 0;
}