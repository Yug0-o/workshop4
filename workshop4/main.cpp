#include <iostream>
#include "Objet2D.h"
#include "Stockage.h"
#include "Rectangle.h"
#include "Cube.h"

using namespace std;

int main11() {
    // D�claration d'un tableau de 3 entiers et Remplissage du tableau avec des valeurs arbitraires
    int tableau[3] = { 10, 20, 30};

    // Affichage du contenu du tableau
    cout << "Contenu du tableau :" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Element " << i << " : " << tableau[i] << endl;
    }
    return 0;
}

int main13() {
    // D�claration d'un tableau de 3 entiers et Remplissage du tableau avec des valeurs arbitraires
    int* tableaudyna = new int[3];
    tableaudyna[0] = 10; tableaudyna[1] = 20; tableaudyna[2] = 30;

    // Affichage du contenu du tableau
    cout << "Contenu du tableau dynamique :" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Element " << i << " : " << tableaudyna[i] << endl;
    }
    int* tempPtr = new int[4];
    for (int i = 0; i < 3; i++) {
        tempPtr[i] = tableaudyna[i];
    }
    delete[] tableaudyna;
    tableaudyna = tempPtr;
    tableaudyna[3] = 999;
    cout << "Contenu du tableau dynamique realloue :" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Element " << i << " : " << tableaudyna[i] << endl;
    }
    return 0;
}

int main2() {
    StockageObjet2D stockage; // Cr�e un objet de stockage

    char choix;
    do {
        cout << "Voulez-vous ajouter un objet (R pour Rectangle, C pour Cube) ? (R/C) ";
        cin >> choix;

        Objet2D* objet;

        if (choix == 'R' || choix == 'r') {
            // Ajoute un Rectangle � la liste
            int longueur, largeur;
            cout << "Entrez la longueur du rectangle : ";
            cin >> longueur;
            cout << "Entrez la largeur du rectangle : ";
            cin >> largeur;
            objet = new Rectangle(longueur, largeur);
        }
        else if (choix == 'C' || choix == 'c') {
            // Ajoute un Cube � la liste
            int cote;
            cout << "Entrez la longueur du cote du cube : ";
            cin >> cote;
            objet = new Cube(cote);
        }
        else {
            break; // Si le choix n'est ni R ni C, sort de la boucle
        }

        stockage.ajouterAtTail(objet); // Ajoute l'objet cr�� � la fin du stockage

    } while (true); // R�p�te jusqu'� ce que l'utilisateur d�cide d'arr�ter

    // Affiche les informations de tous les objets stock�s
    stockage.afficherInfos();

    // Supprime l'int�gralit� des objets stock�s
    while (stockage.getHead()) { // Tant que la liste n'est pas vide
        stockage.supprimerAtHead(); // Supprime la t�te de la liste
    }

    // Affiche les informations apr�s suppression
    cout << "Objets stockes apr�s la suppression : " << endl;
    stockage.afficherInfos();

    return 0;
}

int main() {
    main2();
    return 0;
}