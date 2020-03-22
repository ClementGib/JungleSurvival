#pragma once
#include "C_ENTITE.h"
#include "C_ANIMAUX.h"
#include "C_Fleche.h"

class C_OISEAU :
	protected C_ANIMAUX
{
	friend void Affichage_GAME_OVER();
public:

	
	C_OISEAU();
	~C_OISEAU();

	using C_ANIMAUX::Retourne_Sprit;
	inline Sprite Retourne_Sprit();


	using C_ANIMAUX::Deplacement;
	inline void Deplacement();

	C_Fleche Une_Fleche;
};

Sprite C_OISEAU::Retourne_Sprit()
{
	return Sprite();
}

inline void C_OISEAU::Deplacement()
{


}
