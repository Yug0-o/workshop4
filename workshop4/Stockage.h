#pragma once
#include <iostream>
#include "Objet2D.h"

class StockageObjet2D {
private:
    struct Node {
        Objet2D* objet;
        Node* suivant;
    };

    Node* Head;
    Node* Tail;

public:
    StockageObjet2D();
    Node* getHead() const {
        return Head;
    }
    void ajouterAtHead(Objet2D* objet);
    void ajouterAtTail(Objet2D* objet);
    void ajouterAtIndex(Objet2D* objet, int index);
    void supprimerAtHead();
    void supprimerAtTail();
    void supprimerAtIndex(int index);
    void afficherInfos() const;
};
