#include <SFML\Graphics.hpp> // 2.4.0 used
#include <SFML/OpenGL.hpp> // ajout de open gl cour 3
#include <iostream>
#include <thread>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <math.h>
#include <random>

#include "C_ENTITE.h"
#include "C_FOND.h"
#include "C_ANIMAUX.h"
#include "C_LOUP.h"
//#include "C_OISEAU.h" Par Terminé
#include "C_PERSONNAGE.h"
#include "C_Fleche.h"

using namespace std;
using namespace sf;


Clock Chronometre;
Time temps_ecoule;// a modifier


//=====================================================================

RenderWindow* Fenetre_Principale;
C_FOND Fond_Demarage("Textures/Fond_Demarage.png", 2.5f, 2.0f);
C_FOND La_MAP("Textures/Fond.png", 1.3f, 1.265f); // STYLE ARCADE 2D 1994-1998
C_FOND GAME_OVER("Textures/GAME_OVER_1.jpg", 3.0f, 2.82f,0);

//C_OISEAU Un_Oiseau;
C_PERSONNAGE Le_Personnage { "Textures/Chasseur_Fusion.psd",850,690 };// STYLE ARCADE 2D 1994-1998
vector<C_LOUP* > Meute_de_Loup;
C_LOUP* Loup_mourant;

//=====================================================================
int C_LOUP::Vitesse_Deplacement = 21;
int Nombre_Loups_Tue = 0;
int Nombre_Max_De_Loup = 20;
int Loup_Genere = 0;
int index_Generation_Meute = 0;

void Generation_Loup() {
	
	if (index_Generation_Meute < Nombre_Max_De_Loup) {

	srand(time(NULL));
	
	Meute_de_Loup.push_back(new C_LOUP); // en cas de plusieurs loup en même temps
	Meute_de_Loup[index_Generation_Meute]->Apparition(  0 + (rand() % 2) ); //random booléén 0 ou 1
	

	
	Loup_Genere+=1;
	index_Generation_Meute++;
	

	}   
}

//=====================================================================//


void Affichage_Text() {
	Text Texte_demarage;
	Text Instruction;
	Font La_Police;

	if (!La_Police.loadFromFile("Textures/Polices/Dorovar.ttf"))
	{
		cout << "Erreur avec la police.";
	}

Texte_demarage.setString("Bienvenue ");
Texte_demarage.setFont(La_Police);
Texte_demarage.setCharacterSize(120); 
Texte_demarage.setColor(sf::Color::Red);
Texte_demarage.setStyle(sf::Text::Bold);
Texte_demarage.setPosition(700, -30);

Instruction.setString("\n Appuyez sur 'Espace' pour continuer ");
Instruction.setFont(La_Police);
Instruction.setPosition(180, 120);
Instruction.setCharacterSize(80);
Instruction.setColor(sf::Color::Red);
//Texte_demarage.setStyle(sf::Text::Bold);

Fond_Demarage.sprite.setPosition(Vector2f(450, 420));
	
	Fenetre_Principale->clear();

	Fenetre_Principale->draw(Texte_demarage);
	Fenetre_Principale->draw(Instruction);
	Fenetre_Principale->draw(Fond_Demarage.Retourne_Sprit());
	
	Fenetre_Principale->display();


	while (1) {


		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			break;
		}
	}

	Sleep(200);
	Texte_demarage.setPosition(620, -40);
	Texte_demarage.setString("Commandes:");
	Instruction.setString( " \n Déplacement du personage : fléches directionnelles \n				   (Gauche et Droite). \n Tir du personnage : Touche Espace \n Appuyez sur 'Espace' pour accéder au jeux ");
	Instruction.setFont(La_Police);
	Instruction.setPosition(20, 0);
	Instruction.setCharacterSize(80);
	Instruction.setColor(sf::Color::Red);

	Fenetre_Principale->clear();
	Fenetre_Principale->draw(Texte_demarage);
	Fenetre_Principale->draw(Instruction);
	Fenetre_Principale->draw(Fond_Demarage.Retourne_Sprit());

	Fenetre_Principale->display();


	while (1) {


		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			break;
		}
	}
	
}
//=====================================================================//




void Affichage_Sprit()
{


	Fenetre_Principale->clear();


	Fenetre_Principale->draw(La_MAP.Retourne_Sprit());
	
	//Fenetre_Principale->draw(Un_Oiseau.Retourne_Sprit()); // pas paramétré 

	Fenetre_Principale->draw(Le_Personnage.La_Fleche.Retourne_Sprite());

	for (int index_Meute_affichage = 0; index_Meute_affichage < Meute_de_Loup.size(); index_Meute_affichage++) {
		Fenetre_Principale->draw(Meute_de_Loup[index_Meute_affichage]->Retourne_Sprit());
	}
	
	if (Loup_mourant != nullptr) Fenetre_Principale->draw(Loup_mourant->Retourne_Sprit());

	Fenetre_Principale->draw(Le_Personnage.Retourne_Sprit());
	Fenetre_Principale->draw(GAME_OVER.Retourne_Sprit());

	

	Fenetre_Principale->display();



}


//=====================================================================//

void Affichage_GAME_OVER()
{
	
	Le_Personnage.sprite.setTextureRect(sf::IntRect(0, 110, 55, 47));//peur
	Le_Personnage.sprite.move(0, 15);
	Affichage_Sprit();
	Sleep(1500);

	GAME_OVER.sprite.setColor(sf::Color(255, 255, 255, 250));//Visible

	Fenetre_Principale->clear();
	
	Fenetre_Principale->draw(GAME_OVER.Retourne_Sprit());
	
	if (Nombre_Loups_Tue>=3){
	cout << "F\202licitation vous avez abattu " << Nombre_Loups_Tue<<" loups, mais la for\210t vous a vaincu..." << endl;
	}
	else
	{
		cout <<" Wow , c'\202tait rapide pour un chasseur! Score :" << Nombre_Loups_Tue <<" ..."<<endl;
	}

	Fenetre_Principale->display();

	static Event L_Evenement;


	while (1) {

		while (Fenetre_Principale->pollEvent(L_Evenement)) {

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				Fenetre_Principale->close();
			}

			if (L_Evenement.type == Event::Closed) Fenetre_Principale->close();

		}
	}
}

//=====================================================================//

void Gestion_Entrees()
{
static Event L_Evenement;
	while (Fenetre_Principale->pollEvent(L_Evenement)) {


		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			cout << "Loup tu\202 :" << Nombre_Loups_Tue << endl;
			Fenetre_Principale->close();
		}


		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			Le_Personnage.Positionnement = Le_Personnage.Deplacement(0);

			return;
		}


		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			Le_Personnage.Positionnement = Le_Personnage.Deplacement(1);

			return;
		}
		

		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			
			int Loup_Touche;
			
			for(int P_index_Image_Tir = 0;P_index_Image_Tir<25;P_index_Image_Tir+=5){
				Deplacement_Animaux();
				Loup_Touche = Le_Personnage.Tir(Meute_de_Loup,P_index_Image_Tir );
				Affichage_Sprit();
				
			}

			if (Loup_Touche < Nombre_Max_De_Loup && Loup_Genere > 0) {

				Mort(Loup_Touche);

			}

			return;
		}

	

		

		


		if (L_Evenement.type == Event::Closed) Fenetre_Principale->close();

		} 
	}

//=====================================================================//

void Charge_Texture_Video() {

	Texture La_Texture;
	if (!La_Texture.create(1920, 1080)) {
		cout << "Erreur durant le chargement de l'image" << endl;
	}

	else {

		Uint8* pixels = new Uint8[200 * 200 * 4];

		La_Texture.update(pixels);
		La_Texture.loadFromFile("C:/Users/user/Documents/Visual Projet SFML/Textures/Fond.png");

		RenderWindow window;
		La_Texture.update(window);


	}

}

//=====================================================================//



void Deplacement_Animaux() {
	
	for (int index_meute = 0; index_meute < Meute_de_Loup.size(); index_meute++){ //

		if (Meute_de_Loup[index_meute]->Etat_de_vie == 1 )Meute_de_Loup[index_meute]->Deplacement(); // Si le loup est en vie , il se déplace
		

		if (*Meute_de_Loup [ index_meute] == Le_Personnage && Meute_de_Loup[index_meute]->Etat_de_vie ==1){ // si est en position pour attaquer , il attaque
			
			Meute_de_Loup[index_meute]->Attaque(Le_Personnage);
			Affichage_GAME_OVER();

		}

	}
	Sleep(150);


	

	
}


//=====================================================================//


void Mort(int P_Loup_Touche) {
	

	Meute_de_Loup[P_Loup_Touche]->Etat_de_vie = 0;
	
	Loup_mourant = Meute_de_Loup[P_Loup_Touche];



	
	
	
	for (int index_attente = 0; index_attente<2; index_attente++) {
		Deplacement_Animaux();

	Loup_mourant->Meurt();//tombe à terre
	Le_Personnage.La_Fleche.Disparait();
	Affichage_Sprit();
	}
	
	Meute_de_Loup.erase(Meute_de_Loup.begin() + P_Loup_Touche);
	

	index_Generation_Meute--;
	Loup_Genere --;

	Nombre_Loups_Tue++;
	system("cls");
}


void Niveaux_Sup() {

	
	switch (Nombre_Loups_Tue) {

	case 5: Meute_de_Loup[0]->Vitesse_Deplacement += 10; break;

	case 10:Meute_de_Loup[0]->Vitesse_Deplacement += 10; break;

	case 20:Meute_de_Loup[0]->Vitesse_Deplacement += 10; break;

	case 25:Meute_de_Loup[0]->Vitesse_Deplacement += 10; break;

	case 30:Meute_de_Loup[0]->Vitesse_Deplacement += 10; break;//50

	case 36:Meute_de_Loup[0]->Vitesse_Deplacement += 5; break;

	case 40:Meute_de_Loup[0]->Vitesse_Deplacement += 5; break;

	case 50:Meute_de_Loup[0]->Vitesse_Deplacement += 5; break;//65

	case 60:Meute_de_Loup[0]->Vitesse_Deplacement += 1; break;

	case 70:Meute_de_Loup[0]->Vitesse_Deplacement += 1; break;

	case 80:Meute_de_Loup[0]->Vitesse_Deplacement += 1; break;

	case 90:Meute_de_Loup[0]->Vitesse_Deplacement += 1; break;//69

	}

}

//=====================================================================//

int main(int argc, char *argv[])
{	

	//Fenetre_Principale = new RenderWindow(VideoMode(1920, 1080, 32), "Test SFML", Style::Fullscreen);
	Fenetre_Principale = new RenderWindow(VideoMode(1920, 1080, 32), "Test SFML",Style::Resize);
	srand(NULL);
	///////////////////////////////
	Affichage_Text();

	Generation_Loup();

	int Multiple_1 = 1;
	int Multiple_2 = 1;

	while (Fenetre_Principale->isOpen()) {

		temps_ecoule = Chronometre.getElapsedTime();
		Gestion_Entrees();

		if (Loup_Genere == 0) {

			Generation_Loup();
			Niveaux_Sup();

		}

		if ( (int)temps_ecoule.asSeconds() == (3 * Multiple_1) ){

				Generation_Loup();
				Multiple_1++;

			}

		Deplacement_Animaux();
		Gestion_Entrees();
		Affichage_Sprit();
		

	}

	delete Fenetre_Principale;
	La_MAP.~C_FOND();


	return 0;
}

//=====================================================================
