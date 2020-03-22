#ifndef C_FOND_H
#define C_FOND_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML/OpenGL.hpp> // ajout de open gl cour 3


using namespace sf;
using namespace std;

class C_FOND{
	friend void Affichage_GAME_OVER();
	friend void Affichage_Text();
public : 

	C_FOND();
	~C_FOND()=default;
	C_FOND(char * P_Chemin_Texture, float P_Echelle_1, float P_Echelle_2);
	C_FOND(char * P_Chemin_Texture, float P_Echelle_1, float P_Echelle_2,int P_Transparence);

	inline Sprite Retourne_Sprit();
protected:

	float Facteur_Echelle_1;
	float Facteur_Echelle_2;

	Sprite sprite;
	Texture texture;

};

inline Sprite C_FOND::Retourne_Sprit()
{
	return sprite;;
}


#endif // !C_FOND_H
