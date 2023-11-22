#include "Cube.h"
#include <iostream>
#include <string>

using namespace std;
Cube::Cube() :Rectangle() {};
Cube::Cube(int tcote) : Rectangle(tcote, tcote) {};
int Cube::getPerimetre() { return Rectangle::getPerimetre(); };
int Cube::getAire() { return Rectangle::getAire(); };
int Cube::getCote() { return this->getLongueur(); };
string Cube::afficheInfo() { return "l'objet est un cube : Cote = " + to_string(dim1) + ", Perimetre = " + to_string(getPerimetre()) + ", Aire = " + to_string(getAire()); };