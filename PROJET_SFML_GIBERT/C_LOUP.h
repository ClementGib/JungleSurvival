#ifndef C_LOUP_H
#define C_LOUP_H

#include "C_Fleche.h"
#include "C_ANIMAUX.h"
#include "C_ENTITE.h"
#include "C_PERSONNAGE.h"

using namespace sf;
using namespace std;


class C_LOUP :protected C_ANIMAUX
{
	friend void Mort(int P_Loup_Touche);
	friend void Affichage_GAME_OVER();
	friend void Deplacement_Animaux();
	
	
	friend class C_PERSONNAGE;
public:

	C_LOUP();
	~C_LOUP()=default;

	bool C_LOUP::operator==(const C_PERSONNAGE& P_Personnage);


	using C_ANIMAUX::Retourne_Sprit;
	inline Sprite Retourne_Sprit(char* P_Position, int P_Numero);

	using C_ENTITE::Debug_Affiche_Donnes;
	inline void Debug_Affiche_Donnes();

	using C_ANIMAUX::Apparition;
	void Apparition(bool P_Cote) override;

	using C_ANIMAUX::Deplacement;
	void Deplacement() override;

	void Attaque(C_PERSONNAGE& LE_PERSONNAGE);

	void Meurt();

	static int Vitesse_Deplacement;
	
	inline int Get_X();
protected:
	
	
	bool Etat_de_vie;

};



////////////////////////////////////////////// Retourne Sprite ///////////////////////////////////////////////////

Sprite C_LOUP::Retourne_Sprit(char* P_Position, int P_Numero)
{



	return sprite;
}

////////////////////////////////////////////// Affiche position DEBUG ///////////////////////////////////////////////////

inline void C_LOUP::Debug_Affiche_Donnes()
{
	cout << "LOUP:  X : " << Position_X << "    Y:" << Position_Y << endl;

}

////////////////////////////////////////////// ASCECEUR ///////////////////////////////////////////////////

int C_LOUP::Get_X()
{
	return Position_X;
}


#endif // !C_LOUP_H