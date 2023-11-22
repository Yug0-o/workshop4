#include "Stockage.h"

// Constructeur initialisant les pointeurs Head et Tail � nullptr
StockageObjet2D::StockageObjet2D() : Head(nullptr), Tail(nullptr) {}

// Ajoute un objet au d�but de la liste
void StockageObjet2D::ajouterAtHead(Objet2D* objet) {
    Node* newNode = new Node{ objet, nullptr };
    if (!Head) {  // Si la liste est vide
        Head = Tail = newNode;  // Le nouveau n�ud devient � la fois la t�te et la queue
    }
    else {  // Sinon
        newNode->suivant = Head;  // Le nouveau n�ud pointe vers l'ancienne t�te
        Head = newNode;  // Le nouveau n�ud devient la nouvelle t�te
    }
}

// Ajoute un objet � la fin de la liste
void StockageObjet2D::ajouterAtTail(Objet2D* objet) {
    Node* newNode = new Node{ objet, nullptr };
    if (!Head) {  // Si la liste est vide
        Head = Tail = newNode;  // Le nouveau n�ud devient � la fois la t�te et la queue
    }
    else {  // Sinon
        Tail->suivant = newNode;  // Le n�ud actuel de la queue pointe vers le nouveau n�ud
        Tail = newNode;  // Le nouveau n�ud devient la nouvelle queue
    }
}

// Ajoute un objet � un index sp�cifique dans la liste
void StockageObjet2D::ajouterAtIndex(Objet2D* objet, int index) {
    if (index == 0) {
        ajouterAtHead(objet);  // Si l'index est 0, ajoute � la t�te
    }
    else {
        Node* newNode = new Node{ objet, nullptr };
        Node* current = Head;
        int currentIndex = 0;

        while (current && currentIndex < index - 1) {  // Recherche du n�ud � l'index pr�c�dent
            current = current->suivant;
            currentIndex++;
        }

        if (current) {
            newNode->suivant = current->suivant;  // Ins�re le nouveau n�ud � l'index sp�cifi�
            current->suivant = newNode;
        }
    }
}

// Supprime le n�ud en t�te de liste
void StockageObjet2D::supprimerAtHead() {
    if (Head) {
        Node* temp = Head;
        Head = Head->suivant;
        delete temp;  // Lib�re la m�moire du n�ud supprim�
    }
}

// Supprime le n�ud en queue de liste
void StockageObjet2D::supprimerAtTail() {
    if (Head == Tail) {  // S'il n'y a qu'un seul �l�ment dans la liste
        delete Head;
        Head = Tail = nullptr;  // Vide la liste
    }
    else {
        Node* current = Head;
        while (current->suivant != Tail) {
            current = current->suivant;
        }
        delete Tail;  // Supprime le dernier n�ud
        Tail = current;  // Met � jour la queue
        Tail->suivant = nullptr;
    }
}

// Supprime le n�ud � un index sp�cifique dans la liste
void StockageObjet2D::supprimerAtIndex(int index) {
    if (index == 0) {
        supprimerAtHead();  // Si l'index est 0, supprime la t�te
    }
    else {
        Node* current = Head;
        int currentIndex = 0;

        while (current && currentIndex < index - 1) {  // Recherche du n�ud pr�c�dent l'index
            current = current->suivant;
            currentIndex++;
        }

        if (current && current->suivant) {
            Node* temp = current->suivant;
            current->suivant = temp->suivant;  // Supprime le n�ud � l'index sp�cifi�
            delete temp;  // Lib�re la m�moire du n�ud supprim�
        }
    }
}

// Affiche les informations de chaque objet dans la liste
void StockageObjet2D::afficherInfos() const {
    Node* current = Head;
    while (current) {
        cout << current->objet->afficheInfo() << endl;  // Appelle afficheInfo() de l'objet
        current = current->suivant;  // Passe au n�ud suivant dans la liste
    }
}
