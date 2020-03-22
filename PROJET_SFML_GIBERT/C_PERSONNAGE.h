#ifndef C_PERSONNAGE_H
#define C_PERSONNAGE_H
#include "C_ENTITE.h"
#include "C_Fleche.h"

#include <vector>


#include <SFML\Graphics.hpp>
#include <SFML/OpenGL.hpp> // ajout de open gl cour 3

using namespace std;
using namespace sf;


class C_PERSONNAGE : protected C_ENTITE {
public:
	friend void Affichage_GAME_OVER();
	friend void Gestion_Entrees();
	friend class C_LOUP;


	C_PERSONNAGE();
	C_PERSONNAGE(char* P_Chemin_Texture, int P_Position_X, int P_Position_Y);

	C_Fleche La_Fleche;

	using C_ENTITE::Retourne_Sprit;
	inline Sprite Retourne_Sprit();

	using C_ENTITE::Debug_Affiche_Donnes;
	inline void Debug_Affiche_Donnes();

	void Positionne_Toi_Inverse();
	int Tir(const vector<C_LOUP* >& P_Meute_de_Loups, int P_index_Image_Tir );
	bool Deplacement(bool P_Destination);
	
	

	

protected:
	
	int Points_De_Vie;


	bool Positionnement;
	int Position_X;
	int Position_Y;

	int Taille_du_demi_Sprite;
	



};


////////////////////////////////////////////////////////////////////// :: METHODE INLINE :: ///////////////////////////////////////////////////////////////////////////


inline Sprite C_PERSONNAGE::Retourne_Sprit()
{

	return sprite;
}


inline void C_PERSONNAGE::Debug_Affiche_Donnes()
{
	cout << "PERSONNAGE:  X : " << Position_X << "    Y:" << Position_Y<<endl;
}



#endif // !C_PERSONNAGE_H



