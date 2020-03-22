#include "C_LOUP.h"
#include "C_PERSONNAGE.h"
#include <windows.h>
#include <time.h>


using namespace sf;
using namespace std;



////////////////////////////////////////////// CONSTRUCTEUR ///////////////////////////////////////////////////

C_LOUP::C_LOUP()
	:C_ANIMAUX("Loup", "Textures/LOUP.png")
{
	srand(time(NULL));//Rafraichissement du rand


	Etat_de_vie = 1;
	Position_Y = 700;
	Facteur_Echelle_1 = 2.7f;
	Facteur_Echelle_2 = 2.5f;
	
	int P_ROUGE = 75 +(rand() % 180);
	int P_VERT= 75 + (rand() % 180);
	int P_BLEU= 75 + (rand() % 180);

	

	sprite.scale(Vector2f(Facteur_Echelle_1,Facteur_Echelle_2 ));
	sprite.setColor(sf::Color(P_ROUGE,P_VERT,P_BLEU, 255));//P_ROUGE, P_VERT, P_BLEU, TRANPARENCE
	sprite.setTextureRect(sf::IntRect(610, 131, 103, 71));// [Ligne 3 , 7eme] Marche: Gauche Haut
	sprite.setPosition(Vector2f(0 ,Position_Y));

	
}




/////////////////////////////////////////////////////////////// OPERATEUR /////////////////////////////////////////////////////////////////////////////////




bool C_LOUP::operator==(const C_PERSONNAGE & P_Personnage)
{

	if (P_Personnage.Positionnement == Positionnement) { 

		if (Position_X > P_Personnage.Position_X - P_Personnage.Taille_du_demi_Sprite && Position_X < P_Personnage.Position_X + P_Personnage.Taille_du_demi_Sprite) { // avec marge de 40

			return true;
			
		}

		else {

			return false;

		}

	}

	
		if (P_Personnage.Positionnement != Positionnement) {

			if (Position_X < P_Personnage.Position_X + P_Personnage.Taille_du_demi_Sprite+180 && Position_X > P_Personnage.Position_X - P_Personnage.Taille_du_demi_Sprite-180) { // avec marge de 180

				
				return true;
			}

			else {

				return false;

			}
		



	}
}




/////////////////////////////////////////////////////////////// SPAWN ////////////////////////////////////////////////////////////////////////////



void C_LOUP::Apparition(bool P_Cote)
{



	if (P_Cote == 0) 
	{
		Positionnement = 0;//vers droite
		Facteur_Echelle_1 = -1;
		Facteur_Echelle_2 = 1;
		Position_X = -50;


		sprite.scale(Vector2f(Facteur_Echelle_1, Facteur_Echelle_2));//positionement vers la droite
		sprite.setPosition(Vector2f(Position_X, Position_Y)); //extreme gauche	
		
	}

	else
	{
		Positionnement = 1;//vers gauche
		Facteur_Echelle_1 = 1;
		Facteur_Echelle_2 = 1;
		Position_X = 1930;
		

		sprite.scale(Vector2f(Facteur_Echelle_1, Facteur_Echelle_2));//positionement vers la gauche
		sprite.setPosition(Vector2f(Position_X, Position_Y));//extreme droite
		
	}
}




////////////////////////////////////////////// DEPLACEMENT ///////////////////////////////////////////////////

int Index_Image_Loup = 1;
void C_LOUP::Deplacement()
{
	

	switch (Index_Image_Loup)
	{

	case(1):sprite.setTextureRect(sf::IntRect(0, 105, 103, 71));//marche L3-1 GB
		Index_Image_Loup++;
		break;

	case(2): sprite.setTextureRect(sf::IntRect(307, 129, 101, 71));//marche L3-4 DH
		Index_Image_Loup++;
		break;

	case(3):sprite.setTextureRect(sf::IntRect(103, 106, 103, 71));//marche L3-2 DB
		Index_Image_Loup++;
		break;

	case(4):sprite.setTextureRect(sf::IntRect(610, 131, 103, 71));//marche L3-7 GH
		Index_Image_Loup=1;
		break;
	}



	if (Positionnement == 0) {
		Position_X+= Vitesse_Deplacement;
		sprite.move(sf::Vector2f(Vitesse_Deplacement, 0));
		
	
		if (Position_X >= 2360) {
			Positionnement = 1;

			Facteur_Echelle_1 = -1;
			Facteur_Echelle_2 = 1;
			sprite.scale(Vector2f(Facteur_Echelle_1, Facteur_Echelle_2));//positionement vers la droite */


		}
	}



	else
	{
		Position_X -= Vitesse_Deplacement;
		sprite.move(sf::Vector2f(-Vitesse_Deplacement, 0));
		

		if (Position_X <= -50) {
			Positionnement = 0;

			Facteur_Echelle_1 = -1;
			Facteur_Echelle_2 = 1;
			sprite.scale(Vector2f(Facteur_Echelle_1, Facteur_Echelle_2));//positionement vers la gauche */
			
		}
	}
	

	
}



////////////////////////////////////////////// :ATTAQUE: ///////////////////////////////////////////////////


void C_LOUP::Attaque(C_PERSONNAGE& LE_PERSONNAGE)
{
	
	
	if (Positionnement == LE_PERSONNAGE.Positionnement) {
		
		LE_PERSONNAGE.Positionne_Toi_Inverse();
	}
	sprite.setTextureRect(sf::IntRect(514, 201, 110, 74));//attaque 6 
	sprite.move(sf::Vector2f(0, -30));
	
	

	
}

////////////////////////////////////////////// :Mort: ///////////////////////////////////////////////////


int index_etapes_mort = 1;
void C_LOUP::Meurt()
{
	switch (index_etapes_mort)
	{

	case 1:sprite.setTextureRect(sf::IntRect(443, 0, 91, 62));//Debout 5 yeux fermé
		   sprite.setColor(sf::Color(250, 0, 0, 150));
		   sprite.move(0, 20);
		   index_etapes_mort++;
		break;

	case 2:
		sprite.move(Vector2f(0, 64));
		sprite.setTextureRect(sf::IntRect(108, 0, 110, 42)); //MORT
		index_etapes_mort=1;
		break;

	}


}


