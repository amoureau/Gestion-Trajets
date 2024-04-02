/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//Méthode pour obtenir le départ du trajet
char* Trajet::GetDepart() const {
    return depart;
} //----- Fin de GetDepart

//Méthode pour obtenir l'arrivée du trajet
char* Trajet::GetArrivee() const{
    return arrivee;
} //----- Fin de GetArrivee


//Méthode pour afficher les détails (départ, arrivée) du trajet
void Trajet::Afficher() const{
    cout << "Le trajet est de " << depart << " à " << arrivee << endl;
} //----- Fin de Afficher

void Trajet::Save(std::ofstream& fichier) const {
}

string Trajet::GetType() const {
    return "";
}
//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet (const char* from, const char* to)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>"  << endl;
#endif
depart = new char[strlen(from)+1]; //Alloue la mémoire nécessaire pour l'attribut depart
strcpy(depart,from); //Copie from dans l'attribut depart
arrivee = new char[strlen(to)+1]; //Alloue la mémoire nécessaire pour l'attribut arrivee
strcpy(arrivee,to); //Copie to dans l'attribut arrivee
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
delete[] depart; //Libère la mémoire allouée pour l'attribut depart
delete[] arrivee; //Libère la mémoire allouée pour l'attribut arrivee
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

