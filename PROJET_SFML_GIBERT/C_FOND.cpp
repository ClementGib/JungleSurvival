#include "C_FOND.h"

using namespace std;


// a mettre dans le constructeur :

C_FOND::C_FOND()
{

		if (!texture.loadFromFile("Textures/Fond.png"))
		{
			cout << "Erreur durant le chargement de l'image Objet" << endl;
			cout << __FUNCTION__ << endl;
		}


		else
		{
			texture.setRepeated(true);
			sprite.setTexture(texture);
			sprite.scale(Vector2f(1.3f, 1.265f));

			sprite.setColor(sf::Color(255, 255, 255, 128));//Tranparence 128 = semi transparent
		}


}




//////////////////////////////////////////////////////////////////////////////////

C_FOND::C_FOND(char * P_Chemin_Texture, float P_Echelle_1, float P_Echelle_2)
	:Facteur_Echelle_1(P_Echelle_1), Facteur_Echelle_2(P_Echelle_2)
{

	if (!texture.loadFromFile(P_Chemin_Texture))
	{
		cout << "Erreur durant le chargement de l'image Objet" << endl;
		cout << __FUNCTION__ << endl;
	}


	else
	{
		texture.setRepeated(true);
		sprite.setTexture(texture);
		sprite.scale(Vector2f(Facteur_Echelle_1, Facteur_Echelle_2));
		sprite.setColor(sf::Color(255, 255, 255, 128));//Tranparence 128 = semi transparent
	}


}

C_FOND::C_FOND(char * P_Chemin_Texture, float P_Echelle_1, float P_Echelle_2,int P_Transparence)
	:Facteur_Echelle_1(P_Echelle_1), Facteur_Echelle_2(P_Echelle_2)
{

	if (!texture.loadFromFile(P_Chemin_Texture))
	{
		cout << "Erreur durant le chargement de l'image Objet" << endl;
		cout << __FUNCTION__ << endl;
	}


	else
	{
		texture.setRepeated(true);
		sprite.setTexture(texture);
		sprite.scale(Vector2f(Facteur_Echelle_1, Facteur_Echelle_2));
		sprite.setColor(sf::Color(255, 255, 255, P_Transparence));//Tranparence 128 = semi transparent
	}


}



