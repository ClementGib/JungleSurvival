#ifndef C_FLECHE_H
#define	C_FLECHE_H
#include <ostream>

#include <SFML\Graphics.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;
using namespace sf;

class C_Fleche {
	friend class  C_LOUP;

public:
	C_Fleche();
	C_Fleche(int P_Postion_X, int P_Postion_Y);

	inline Sprite Retourne_Sprite();
	inline void Positionne_Toi();
	inline void Positionne_Toi(int P_Positon_X);
	inline void Disparait();

	bool Propulsion(bool P_Sens_Tir, int P_Postion_Chasseur,int P_Position_Loup);


	int Position_X;
	int Position_Y;


protected:


	bool Position_Fleche;
	const int Degat;


	Sprite Sprite_Fleche;
	Texture Texture_Fleche;


};

//////////////////////////////////////////////////////// :: METHODES :: //////////////////////////////////////////////////////////


inline Sprite C_Fleche::Retourne_Sprite()
{


	return Sprite_Fleche;
}



//------------------------------- POSITIONNE TOI --------------------------------//

inline void C_Fleche::Positionne_Toi()
{
	Sprite_Fleche.setPosition(Vector2f(Position_X - 65, Position_Y));
}

////////////////////////////////////////////////////////

inline void C_Fleche::Positionne_Toi(int P_Positon_X)
{
	Position_X = P_Positon_X;
	Sprite_Fleche.setPosition(Vector2f(Position_X-65, Position_Y));
}


//------------------------------- DISPARAIT --------------------------------//


inline void C_Fleche::Disparait()
{
	Sprite_Fleche.setColor(sf::Color(255, 255, 255, 0));//Invisible
}

//-------------------------------PROPULTION , DANS LA METHODE TIR --------------------------------//





#endif // !C_FLECHE_H