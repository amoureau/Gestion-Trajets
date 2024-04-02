/*************************************************************************
                           ElemListe  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ElemListe> (fichier ElemListe.h) ----------------
#if ! defined ( ELEMLISTE_H )
#define ELEMLISTE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ElemListe>
/*
 * class ElemListe
 * Classe représentant un élément d'une liste chaînée.
 *
 * Cette classe représente un élément d'une liste chaînée utilisée pour stocker des objets de type Trajet.
 * Chaque élément contient un pointeur vers le prochain élément de la liste et un pointeur vers un objet de type Trajet.
 */
//
//------------------------------------------------------------------------

class ElemListe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ElemListe* GetNext() const;
    // Mode d'emploi : Appeler la méthode GetNext sur un objet de la classe ElemListe pour obtenir l'élément suivant dans la liste
    // Return : Un pointeur de type ElemListe* vers l'élement suivant dans la liste
    // Contrat :
    //

    void SetNext(ElemListe* nextElem);
    // Mode d'emploi : Appeler la méthode SetNext sur un objet de la classe ElemListe pour modifier l'élément suivant (next) dans la liste
    //
    // Contrat :
    //

    Trajet* GetTrajet() const;
    // Mode d'emploi : Appeler la méthode GetTrajet sur un objet de la classe ElemListe pour obtenir le trajet de l'élément courant
    // Return : Un pointeur de type Trajet* vers le trajet de l'élément courant
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    ElemListe ();
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :

    ElemListe (Trajet* newTrajet);
    // Mode d'emploi : Constructeur qui prend en paramètre un Trajet* et initialise l'attribut trajet avec ce paramètre
    //
    // Contrat :
    //

    virtual ~ElemListe ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

    
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    ElemListe* next;
    Trajet* trajet;
};

//-------------------------------- Autres définitions dépendantes de <ElemListe>

#endif

