#include "C_OISEAU.h"



C_OISEAU::C_OISEAU()
	:C_ANIMAUX("Oiseau", "Textures/Bird_Fusion.psd")
	{
	Position_X = 700;
		Position_Y = 300;
		Facteur_Echelle_1 = 8.7f;
		Facteur_Echelle_2 = 8.5f;

		sprite.scale(Vector2f(Facteur_Echelle_1, Facteur_Echelle_2));
		//sprite.setTextureRect(sf::IntRect(610, 131, 103, 71));
		sprite.setPosition(Vector2f(Position_X, Position_Y));

	}


C_OISEAU::~C_OISEAU()
{
}

