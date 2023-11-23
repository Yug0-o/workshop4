#include "Rectangle.h"
#include <iostream>
#include <string> 

using namespace std;

// Constructeur par défaut : appelle le constructeur par défaut de Objet2D
Rectangle::Rectangle() : Objet2D() {};

// Constructeur surchargé : appelle le constructeur surchargé de Objet2D avec longueur et largeur spécifiées
Rectangle::Rectangle(int tlongueur, int tlargeur) : Objet2D(tlongueur, tlargeur) {};

// Obtient le périmètre du rectangle en utilisant les dimensions longueur et largeur
int Rectangle::getPerimetre() { return (dim1 + dim2) * 2; };

// Obtient l'aire du rectangle en multipliant longueur par largeur
int Rectangle::getAire() { return dim1 * dim2; };

// Obtient la longueur du rectangle
int Rectangle::getLongueur() { return dim1; };

// Obtient la largeur du rectangle
int Rectangle::getLargeur() { return dim2; };

// Affiche les informations sur le rectangle : longueur, largeur, périmètre et aire
string Rectangle::afficheInfo() {
    return "l'objet est un rectangle : longueur = " + to_string(dim1) +
        ", largeur = " + to_string(dim2) +
        ", Perimetre = " + to_string(getPerimetre()) +
        ", Aire = " + to_string(getAire());
};
