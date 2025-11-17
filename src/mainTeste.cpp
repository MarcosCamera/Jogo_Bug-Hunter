#include "Ente.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Formiga.hpp" // Adicionado para garantir tipo completo
#include "Jogador.hpp"
#include "Plataforma.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace Gerenciadores;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;
using namespace sf;

int main()
{
	Gerenciador_Grafico graf;
	Gerenciador_Colisoes colis;

	Jogador jog;
	Formiga form(&jog);
	Plataforma plat;

	Ente* eJog = &jog; //ta certo? ao inves de fazer static cast???
	Ente* eForm = &form;
	Ente* ePlat = &plat;

	jog.setTexture("Texturas/aranha.png", sf::Vector2f(0.03f, 0.03f));
	form.setTexture("Texturas/formiga.png", sf::Vector2f(0.03f, 0.03f));
	plat.setTexture("Texturas/plataforma.png", sf::Vector2f(10.f, 10.f));

	plat.getFig()->setPosition(0, 500);
	form.getFig()->setPosition(80, 450);

	colis.setJogador(&jog);
	colis.incluirInimigo(&form);
	colis.incluirObstaculo(&plat);

	while (graf.abertaJanela())
	{
		Event event;
		while (graf.getWindow().pollEvent(event))
		{
			if (event.type == Event::Closed)
				graf.fecharJanela();
		}

		/*UPDATE*/

		jog.executar();
		form.executar();
		plat.executar();

		colis.executar();


		/*DRAW*/
		graf.getWindow().clear(Color::White);
		graf.desenharEnte(eJog);
		graf.desenharEnte(ePlat);
		graf.desenharEnte(eForm);
		graf.getWindow().display();
	}
	return 0;
}