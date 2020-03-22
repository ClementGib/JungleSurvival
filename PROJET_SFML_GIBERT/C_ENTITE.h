#ifndef C_ENTITE_H
#define C_ENTITE_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>// ajout de open gl cour 3


using namespace std;
using namespace sf;

class C_ENTITE {

public:

	C_ENTITE()=default;
	C_ENTITE(char *P_Chemin_Texture);
	C_ENTITE(char *P_Chemin_Texture,float P_Echelle_1, float P_Echelle_2);
	
	inline virtual void Apparition();
	inline virtual void Apparition(bool P_Cote);

	inline Sprite Retourne_Sprit();
	inline void Debug_Affiche_Donnes();


protected:

	int Position_Y = 0;
	int Position_X = 0;
	float Facteur_Echelle_1;
	float Facteur_Echelle_2;

	Sprite sprite;
	Texture texture;
	

private:



};


inline void C_ENTITE::Apparition()
{
}


inline void C_ENTITE::Apparition(bool P_Cote)
{
}


inline Sprite C_ENTITE::Retourne_Sprit()
{
	return sprite;;
}

inline void C_ENTITE::Debug_Affiche_Donnes()
{

}



#endif // !C_ENTITE_H

