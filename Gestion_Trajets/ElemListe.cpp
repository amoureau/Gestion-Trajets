/*************************************************************************
                           ElemListe  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ElemListe> (fichier ElemListe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ElemListe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ElemListe::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//Méthode pour récupérer le pointeur vers élément suivant (next) dans la liste
ElemListe* ElemListe::GetNext() const{
    return next;
} //----- Fin de GetNext

//Méthode pour modifier vers quel élément pointe l'élément courant (donc modifie l'attribut next)
void ElemListe::SetNext(ElemListe* nextElem) {
    next = nextElem;
} //----- Fin de SetNext

//Méthode pour récupérer le trajet de l'élément courant
Trajet* ElemListe::GetTrajet() const{
    return trajet;
} //----- Fin de GetTrajet


//-------------------------------------------- Constructeurs - destructeur
//Constructeur par défaut
ElemListe::ElemListe()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <ElemListe>" << endl;
#endif
trajet = nullptr;
next = nullptr;
} //----- Fin de ElemListe

//Constructeur avec initialisation du trajet
ElemListe::ElemListe(Trajet* newTrajet)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur avec trajet de <ElemListe>" << endl;
#endif
trajet = newTrajet;
next = nullptr;

} //----- Fin de ElemListe


ElemListe::~ElemListe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ElemListe>" << endl;
#endif
delete trajet; // Destruction du trajet
} //----- Fin de ~ElemListe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

