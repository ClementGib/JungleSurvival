#include "C_ENTITE.h"


#include <SFML\Graphics.hpp>
#include <SFML/OpenGL.hpp> // ajout de open gl cour 3
#include <iostream>

using namespace std;
using namespace sf;





//////////////////////////////////////////////////////////////////////////////////
C_ENTITE::C_ENTITE(char * P_Chemin_Texture)
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
	}
}


//////////////////////////////////////////////////////////////////////////////////

C_ENTITE::C_ENTITE(char * P_Chemin_Texture,float P_Echelle_1,float P_Echelle_2)
	:Facteur_Echelle_1(P_Echelle_1),Facteur_Echelle_2(P_Echelle_2)
{

	if (!texture.loadFromFile(P_Chemin_Texture))
	{
		cout << "Erreur durant le chargement de l'image Objet" << endl;
		cout <<__FUNCTION__ << endl;
	}


	else
	{
		texture.setRepeated(true);
		sprite.setTexture(texture);
		sprite.scale(Vector2f(Facteur_Echelle_1, Facteur_Echelle_2));
	}

	
}






