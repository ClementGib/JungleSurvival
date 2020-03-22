#include "C_PERSONNAGE.h"
#include "C_LOUP.h"

using namespace std;
using namespace sf;


int Nb_Max_Loup = 20;

C_PERSONNAGE::C_PERSONNAGE(char * P_Chemin_Texture, int P_Position_X, int P_Position_Y)
	:C_ENTITE(P_Chemin_Texture, 0.5f, 0.5f), Position_X(P_Position_X),
Position_Y (P_Position_Y)//Définie pour le personnage
	
{

	Taille_du_demi_Sprite = 24;//en partant du centre calcule d'un demi sprite en moyenne.
	La_Fleche.Position_X = P_Position_X;
	La_Fleche.Position_Y = P_Position_Y;
	La_Fleche.Positionne_Toi();

	Points_De_Vie = 100;
	Positionnement = 0;
	Facteur_Echelle_1 = 1;
	Facteur_Echelle_2 = 1;

	sprite.setPosition(Vector2f(Position_X,Position_Y));
	sprite.setColor(sf::Color(140, 150, 150,225));
	sprite.scale(8.7f, 8.5f);
	
	
	sprite.setTextureRect(sf::IntRect(0, 8, 49, 46));//pause

	
	
	//EN CAS DE TIR SUR OISEAUX ::
	//sprite.setTextureRect(sf::IntRect(0, 532, 61, 50)); //tir haut 1
	//sprite.setTextureRect(sf::IntRect(69, 532, 55, 50)); //tir haut 2
	//sprite.setTextureRect(sf::IntRect(120, 532, 61, 50)); // tir haut 3
	//sprite.setTextureRect(sf::IntRect(180, 532, 61, 50)); // tir haut 4 
	//sprite.setTextureRect(sf::IntRect(242, 532, 61, 50)); //tir haut 5
}


//-----------------------------------------------------------------------------------------------//

C_PERSONNAGE::C_PERSONNAGE()
	:C_ENTITE("Textures/Chasseur_Fusion.psd")
{

	Position_X = 850;
	Position_Y = 690;
	Taille_du_demi_Sprite = 24;//en partant du centre calcule d'un demi sprite en moyenne.

	La_Fleche.Positionne_Toi();

	Points_De_Vie = 100;
	Positionnement = 0;
    Facteur_Echelle_1 = 1;
	Facteur_Echelle_2 = 1;
	
	sprite.setPosition(Vector2f(Position_X, Position_Y));
	sprite.setColor(sf::Color(140, 150, 150, 225));
	sprite.scale(8.7f, 8.5f);
	sprite.setTextureRect(sf::IntRect(0, 8, 49, 46));//pose

}







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Index_Image_Personnage = 1;

//---------------------------------------------------------------------------------------------------------//


/////////////////////////////////////////////////////DEPLACEMENT////////////////////////////////////////////////////////////

bool C_PERSONNAGE::Deplacement(bool P_Destination) {

	La_Fleche.Disparait();

	switch (Index_Image_Personnage)
	{

	case(1):sprite.setTextureRect(sf::IntRect(50, 210, 48, 47));//marche centre
		Index_Image_Personnage++;
		break;


	case(2):sprite.setTextureRect(sf::IntRect(100, 210, 48, 47));// marche droite
		Index_Image_Personnage++;
		break;

	case(3):sprite.setTextureRect(sf::IntRect(50, 210, 48, 47));//marche centre
		Index_Image_Personnage++;
		break;

	case(4):sprite.setTextureRect(sf::IntRect(0, 210, 48, 47));//marche gauche
		Index_Image_Personnage = 1;
		break;
	}


	if (P_Destination == 0) { //déplacement vers la droite 

		if (Positionnement == 1) {

			Positionne_Toi_Inverse();

		}


		if (Position_X + 45 <= 1700) {
			Position_X = Position_X  + 45;
			sprite.move(sf::Vector2f(45, 0));
			La_Fleche.Positionne_Toi(Position_X);
		}
		return 0;
	}





	if (P_Destination == 1) {//déplacement vers la gauche

		if (Positionnement == 0) {
			Positionne_Toi_Inverse();
		}

		if (Position_X - 45 >= 200) {
			Position_X = Position_X - 45;
			sprite.move(sf::Vector2f(-45, 0));
			La_Fleche.Positionne_Toi(Position_X);
		}

		return 1;
	}

}



///////////////////////////////////////////////////// TIR ////////////////////////////////////////////////////

void C_PERSONNAGE::Positionne_Toi_Inverse()
{


	if (Positionnement == 1) {

		Facteur_Echelle_1 = -1;
		Facteur_Echelle_2 = 1;
		sprite.scale(Vector2f(Facteur_Echelle_1, Facteur_Echelle_2));

		sprite.move(sf::Vector2f(-190, 0));
		Position_X = Position_X - 165;

	}


	if (Positionnement == 0) {

		Facteur_Echelle_1 = -1;
		Facteur_Echelle_2 = 1;
		sprite.scale(Vector2f(Facteur_Echelle_1, Facteur_Echelle_2));//positionement

		sprite.move(sf::Vector2f(190, 0));
		Position_X = Position_X + 165;
	}

}


//-------------------------------------------------------------//

int Loup_Touché = Nb_Max_Loup;
int C_PERSONNAGE::Tir(const vector<C_LOUP* >& P_Meute_de_Loups, int P_index_Image_Tir)
{

	if (P_index_Image_Tir < 5) {
		sprite.setTextureRect(sf::IntRect(0, 427, 51, 47));//tir bas 1
		La_Fleche.Disparait();
		Loup_Touché = Nb_Max_Loup;
		return Nb_Max_Loup;
	}


	if (P_index_Image_Tir >= 5 && P_index_Image_Tir < 10) {
		sprite.setTextureRect(sf::IntRect(50, 427, 51, 47));//tir bas 2

		return Nb_Max_Loup;
	}

	if (P_index_Image_Tir >= 10 && P_index_Image_Tir < 20) {
		sprite.setTextureRect(sf::IntRect(108, 427, 50, 47));//tir bas 3
		return Nb_Max_Loup;
	}

	if (P_index_Image_Tir >= 20 && P_index_Image_Tir < 25) {
		sprite.setTextureRect(sf::IntRect(203, 427, 51, 47));//tir bas attend 5

		for (int index_vector = P_Meute_de_Loups.size() - 1; index_vector >= 0; index_vector--) {// Permet de retourner le loup le plus proche dans le champ

			bool Colision_Loup = La_Fleche.Propulsion(Positionnement, Position_X, P_Meute_de_Loups[index_vector]->Position_X);//Position X d'un/des loup de la meute
			
			if (Colision_Loup == 1) {
				Loup_Touché = index_vector;//index_vector;
				index_vector == -1;// largement supérieur a une apparition de loup possible et fin de boucle for
			}

			
		}
		return Loup_Touché;
	}




}








	



