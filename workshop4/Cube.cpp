#include "Cube.h"
#include <iostream>
#include <string>

using namespace std;

// Constructeur par d�faut : appelle le constructeur par d�faut de Rectangle
Cube::Cube() : Rectangle() {};

// Constructeur surcharg� : appelle le constructeur surcharg� de Rectangle avec les c�t�s �gaux pour cr�er un cube
Cube::Cube(int tcote) : Rectangle(tcote, tcote) {};

// Obtient le p�rim�tre du cube en utilisant la m�thode getPerimetre() de Rectangle
int Cube::getPerimetre() { return Rectangle::getPerimetre(); };

// Obtient l'aire du cube en utilisant la m�thode getAire() de Rectangle
int Cube::getAire() { return Rectangle::getAire(); };

// Obtient la longueur du c�t� du cube en utilisant la m�thode getLongueur() de Rectangle
int Cube::getCote() { return this->getLongueur(); };

// Affiche les informations sur le cube : c�t�s, p�rim�tre et aire
string Cube::afficheInfo() {
    return "l'objet est un cube : Cote = " + to_string(dim1) +
        ", Perimetre = " + to_string(getPerimetre()) +
        ", Aire = " + to_string(getAire());
};
