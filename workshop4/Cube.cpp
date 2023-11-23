#include "Cube.h"
#include <iostream>
#include <string>

using namespace std;

// Constructeur par défaut : appelle le constructeur par défaut de Rectangle
Cube::Cube() : Rectangle() {};

// Constructeur surchargé : appelle le constructeur surchargé de Rectangle avec les côtés égaux pour créer un cube
Cube::Cube(int tcote) : Rectangle(tcote, tcote) {};

// Obtient le périmètre du cube en utilisant la méthode getPerimetre() de Rectangle
int Cube::getPerimetre() { return Rectangle::getPerimetre(); };

// Obtient l'aire du cube en utilisant la méthode getAire() de Rectangle
int Cube::getAire() { return Rectangle::getAire(); };

// Obtient la longueur du côté du cube en utilisant la méthode getLongueur() de Rectangle
int Cube::getCote() { return this->getLongueur(); };

// Affiche les informations sur le cube : côtés, périmètre et aire
string Cube::afficheInfo() {
    return "l'objet est un cube : Cote = " + to_string(dim1) +
        ", Perimetre = " + to_string(getPerimetre()) +
        ", Aire = " + to_string(getAire());
};
