#pragma once
#include <iostream>

using namespace std;

class Objet2D {
private:
    Objet2D* Suivant; // Membre privé, pointeur vers Objet2D

protected:
    int dim1, dim2;

public:
    Objet2D();
    Objet2D(int tdim1, int tdim2);
    virtual int getPerimetre();
    virtual int getAire();
    virtual string afficheInfo();

    // Accesseurs pour le membre Suivant
    void setSuivant(Objet2D* suivant) { Suivant = suivant; }
    Objet2D* getSuivant() const { return Suivant; }
};