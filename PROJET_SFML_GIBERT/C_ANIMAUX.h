#ifndef  C_ANIMAUX_H
#define C_ANIMAUX_H


#include "C_ENTITE.h"

class C_ANIMAUX :
	protected C_ENTITE
{
public:
	

	C_ANIMAUX()=default;
	C_ANIMAUX(char * P_Nom, char * P_Chemin_Sprite);
	~C_ANIMAUX()=default;

	using C_ENTITE::Retourne_Sprit;
	inline Sprite Retourne_Sprit();
	
	inline virtual void Deplacement()=0;

	

protected : 

	char* NAME;


	bool Positionnement;



};

//-------------------------------------------------------------------------------//


Sprite C_ANIMAUX::Retourne_Sprit()
{
	return sprite;
}

//-------------------------------------------------------------------------------//




#endif // ! C_ANIMAUX_H