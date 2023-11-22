#include "Stockage.h"

// Constructeur initialisant les pointeurs Head et Tail à nullptr
StockageObjet2D::StockageObjet2D() : Head(nullptr), Tail(nullptr) {}

// Ajoute un objet au début de la liste
void StockageObjet2D::ajouterAtHead(Objet2D* objet) {
    Node* newNode = new Node{ objet, nullptr };
    if (!Head) {  // Si la liste est vide
        Head = Tail = newNode;  // Le nouveau nœud devient à la fois la tête et la queue
    }
    else {  // Sinon
        newNode->suivant = Head;  // Le nouveau nœud pointe vers l'ancienne tête
        Head = newNode;  // Le nouveau nœud devient la nouvelle tête
    }
}

// Ajoute un objet à la fin de la liste
void StockageObjet2D::ajouterAtTail(Objet2D* objet) {
    Node* newNode = new Node{ objet, nullptr };
    if (!Head) {  // Si la liste est vide
        Head = Tail = newNode;  // Le nouveau nœud devient à la fois la tête et la queue
    }
    else {  // Sinon
        Tail->suivant = newNode;  // Le nœud actuel de la queue pointe vers le nouveau nœud
        Tail = newNode;  // Le nouveau nœud devient la nouvelle queue
    }
}

// Ajoute un objet à un index spécifique dans la liste
void StockageObjet2D::ajouterAtIndex(Objet2D* objet, int index) {
    if (index == 0) {
        ajouterAtHead(objet);  // Si l'index est 0, ajoute à la tête
    }
    else {
        Node* newNode = new Node{ objet, nullptr };
        Node* current = Head;
        int currentIndex = 0;

        while (current && currentIndex < index - 1) {  // Recherche du nœud à l'index précédent
            current = current->suivant;
            currentIndex++;
        }

        if (current) {
            newNode->suivant = current->suivant;  // Insère le nouveau nœud à l'index spécifié
            current->suivant = newNode;
        }
    }
}

// Supprime le nœud en tête de liste
void StockageObjet2D::supprimerAtHead() {
    if (Head) {
        Node* temp = Head;
        Head = Head->suivant;
        delete temp;  // Libère la mémoire du nœud supprimé
    }
}

// Supprime le nœud en queue de liste
void StockageObjet2D::supprimerAtTail() {
    if (Head == Tail) {  // S'il n'y a qu'un seul élément dans la liste
        delete Head;
        Head = Tail = nullptr;  // Vide la liste
    }
    else {
        Node* current = Head;
        while (current->suivant != Tail) {
            current = current->suivant;
        }
        delete Tail;  // Supprime le dernier nœud
        Tail = current;  // Met à jour la queue
        Tail->suivant = nullptr;
    }
}

// Supprime le nœud à un index spécifique dans la liste
void StockageObjet2D::supprimerAtIndex(int index) {
    if (index == 0) {
        supprimerAtHead();  // Si l'index est 0, supprime la tête
    }
    else {
        Node* current = Head;
        int currentIndex = 0;

        while (current && currentIndex < index - 1) {  // Recherche du nœud précédent l'index
            current = current->suivant;
            currentIndex++;
        }

        if (current && current->suivant) {
            Node* temp = current->suivant;
            current->suivant = temp->suivant;  // Supprime le nœud à l'index spécifié
            delete temp;  // Libère la mémoire du nœud supprimé
        }
    }
}

// Affiche les informations de chaque objet dans la liste
void StockageObjet2D::afficherInfos() const {
    Node* current = Head;
    while (current) {
        cout << current->objet->afficheInfo() << endl;  // Appelle afficheInfo() de l'objet
        current = current->suivant;  // Passe au nœud suivant dans la liste
    }
}
