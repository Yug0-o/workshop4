#include "Objet2D.h"

// Constructeur par d�faut : initialise dim1 et dim2 � 0, et Suivant � nullptr
Objet2D::Objet2D() : dim1(0), dim2(0), Suivant(nullptr) {};

// Constructeur surcharg� : initialise dim1 et dim2 avec les valeurs sp�cifi�es, Suivant � nullptr
Objet2D::Objet2D(int tdim1, int tdim2) : dim1(tdim1), dim2(tdim2), Suivant(nullptr) {};

// Renvoie 0 pour le p�rim�tre de l'objet 2D
int Objet2D::getPerimetre() {
	return 0;
};

// Renvoie 0 pour l'aire de l'objet 2D
int Objet2D::getAire() {
	return 0;
};

// Renvoie une cha�ne indiquant que c'est une fonction Objet2D
string Objet2D::afficheInfo() {
	return "Objet2D function";
};
