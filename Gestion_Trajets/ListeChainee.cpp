
/*************************************************************************
                           ListeChainee  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeChainee.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ListeChainee::Méthode ( liste des paramètres )
// Algorithme :
//{
//} //----- Fin de Méthode

// Méthode pour obtenir la tête de la liste
ElemListe * ListeChainee::GetHead() const {
    return head;
} //----- Fin de GetHead

// Méthode pour obtenir le nombre d'éléments dans la liste
int ListeChainee::GetNbElem() const {
    return nbElem;
} //----- Fin de GetNbElem

// Méthode pour ajouter un nouvel élément à la fin de la liste
void ListeChainee::AjouterEnFin(Trajet* newTrajet) {
    ElemListe * newElem = new ElemListe(newTrajet);
    if (nbElem == 0) {
        head = newElem;
        tail = newElem;
    }
    else {
        tail->SetNext(newElem);
        tail = newElem;
    }
    nbElem++;
} //----- Fin de AjouterEnFin

// Méthode pour afficher tous les éléments de la liste
void ListeChainee::Afficher() const {
    printf("-----------------\n");
    ElemListe* cur = head;
    while(cur != nullptr) {
        cout << "    ";
        cur->GetTrajet()->Afficher();
        cur= cur->GetNext();
    }
    printf("-----------------\n\n");
} //----- Fin de Afficher

//-------------------------------------------- Constructeurs - destructeur
ListeChainee::ListeChainee()
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
    head = nullptr;
    tail = nullptr;
    nbElem = 0;
}
 //----- Fin de ListeChainee


ListeChainee::~ListeChainee ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif

while(head != NULL) { // Tant que la liste n'est pas vide
    ElemListe* temp = head;
    head = head->GetNext();
    delete temp; // Destruction de l'élément courant
}

} //----- Fin de ~ListeChainee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

