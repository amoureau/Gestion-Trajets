/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//Méthode pour afficher les détails (départ/arrivée global, décomposition en trajets simples) du trajet composé
void TrajetCompose::Afficher() const {
    cout << "Le trajet est de " << depart << " à " << arrivee << " en utilisant les trajets : " << endl;
    trajets->Afficher(); //Affiche tous les trajets simples composant le trajet composé
} //----- Fin de Afficher


//Méthode pour obtenir le nombre de trajets simples composant le trajet composé
void TrajetCompose::Ajouter(Trajet* ajout) {
    trajets->AjouterEnFin(ajout); //Ajoute le trajet simple à la liste des trajets simples composant le trajet composé
    delete[] arrivee; //Supprime l'ancienne valeur de l'attribut arrivee
    arrivee = new char[strlen(ajout->GetArrivee())+1]; //Alloue la mémoire nécessaire pour stocker la nouvelle valeur de l'attribut arrivee
    strcpy(arrivee, ajout->GetArrivee()); //Copie la nouvelle valeur de l'attribut arrivee
} //----- Fin de Ajouter

void TrajetCompose::Save(std::ofstream& fichier) const {
    fichier << "C;" << trajets->GetNbElem() << ";" << depart << ";"<< arrivee << ";";
    ElemListe* cur = trajets->GetHead();
    while (cur != nullptr) {
        cur->GetTrajet()->Save(fichier);
        cur = cur->GetNext();
    }
}

string TrajetCompose::GetType() const {
    return "C";
}
//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur



TrajetCompose::TrajetCompose(Trajet* trajInit, const char* from, const char* to) : Trajet(from, to), trajets(new ListeChainee)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
trajets->AjouterEnFin(trajInit); //Ajoute le trajet simple à la liste des trajets simples composant le trajet composé
}//----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
delete trajets; //Libère la mémoire allouée pour la liste des trajets simples composant le trajet composé
}
 //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
