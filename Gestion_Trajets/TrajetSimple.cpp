/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//Méthode pour afficher les détails (départ, arrivée, moyen de transport) du trajet
void TrajetSimple::Afficher() const {
    cout << "Le trajet est de " << depart << " à " << arrivee << " en " << moyen_transport << endl;
} //----- Fin de Afficher

void TrajetSimple::Save(std::ofstream& fichier) const {
    fichier << "S;" << depart << ";" << arrivee << ";" << moyen_transport << ";";
}

string TrajetSimple::GetType() const {
    return "S";
}

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char* from, const char* to, const char* moyen_trans) : Trajet(from, to)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
moyen_transport = new char[strlen(moyen_trans)+1];
strcpy(moyen_transport,moyen_trans);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
delete [] moyen_transport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

