#include "C_Fleche.h"
#include <SFML\Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>

using namespace std;
using namespace sf;




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
C_Fleche::C_Fleche()
	:Degat(50),Position_X(690), Position_Y(1500), Position_Fleche(true)
{
	

	if (!Texture_Fleche.loadFromFile("Textures/Fleche.psd"))
	{
		cout << "Erreur durant le chargement de l'image Objet" << endl;
		cout << __FUNCTION__ << endl;
	}


	else
	{


		Texture_Fleche.setRepeated(true);
		Sprite_Fleche.setTexture(Texture_Fleche);
		Sprite_Fleche.setPosition(Vector2f(1500, Position_Y));
		Sprite_Fleche.scale(0.5f, 0.5f);
		Sprite_Fleche.setColor(sf::Color(255, 255, 255, 0));//Invisible
		

	}
}





C_Fleche::C_Fleche(int P_Postion_X, int P_Postion_Y)
	:Degat(50),Position_X(P_Postion_X),Position_Y(P_Postion_Y),Position_Fleche(true)
{
	

	

	if (!Texture_Fleche.loadFromFile("Textures/Fleche.psd"))
	{
		cout << "Erreur durant le chargement de l'image Objet" << endl;
		cout << __FUNCTION__ << endl;
	}


	else
	{

		Texture_Fleche.setRepeated(true);
		Sprite_Fleche.setTexture(Texture_Fleche);
		Sprite_Fleche.scale(0.5f, 0.5f);
		Sprite_Fleche.setPosition(Vector2f(1500, Position_Y));
		Sprite_Fleche.setColor(sf::Color(255, 255, 255, 0));//Invisible
	
	}

}


//------------------------------- PROPULTION DU AU TIR --------------------------------//

bool C_Fleche::Propulsion(bool P_Sens_Tir, int P_Postion_Chasseur, int P_Position_Loup)
{

	Sprite_Fleche.setColor(sf::Color(255, 255, 255, 0));//Invisible
	Positionne_Toi(P_Postion_Chasseur);

	if (P_Sens_Tir == 1) {
		Position_Fleche = P_Sens_Tir;

		while (Position_X >= 40 && Position_X != P_Position_Loup) {
			Sprite_Fleche.move(sf::Vector2f(-1, 0));
			Position_X -= 1;

		}

		if (Position_X == P_Position_Loup) {
			Sprite_Fleche.move(sf::Vector2f(-12, 15));
			Sprite_Fleche.setColor(sf::Color(255, 255, 255));//Visible
			return 1;
		}

		else
		{
			Sprite_Fleche.move(sf::Vector2f(-18, 15));
			Sprite_Fleche.setColor(sf::Color(255, 255, 255));//Visible
			return 0;
		}

	}




	if (P_Sens_Tir == 0) {

		if (P_Postion_Chasseur == 1) {


			Sprite_Fleche.scale(Vector2f(1, 1));
		}
		while (Position_X <= 1840 && (Position_X != P_Position_Loup)) {
			Sprite_Fleche.move(sf::Vector2f(1, 0));
			Position_X += 1;
		}

		if (Position_X == P_Position_Loup) {
			Sprite_Fleche.setColor(sf::Color(255, 255, 255));//Visible
			Sprite_Fleche.move(sf::Vector2f(-10, 15));
			return 1;
		}

		else
		{
			Sprite_Fleche.move(sf::Vector2f(15, 15));
			Sprite_Fleche.setColor(sf::Color(255, 255, 255));//Visible
			return 0;
		}


	}
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






