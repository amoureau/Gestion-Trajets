/*************************************************************************
                           ListeChainee  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeChainee> (fichier ListeChainee.h) ----------------
#if ! defined ( ListeChainee_H )
#define ListeChainee_H

//--------------------------------------------------- Interfaces utilisées
#include "ElemListe.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
/*
 * class ListeChainee
 * Classe représentant une liste chaînée.
 * 
 * Cette classe permet de créer et de manipuler une liste chaînée d'objets de type Trajet.
 * Elle offre des méthodes pour ajouter des éléments à la fin de la liste, obtenir la tête de la liste,
 * obtenir le nombre d'éléments dans la liste et afficher tous les éléments de la liste.
 */
//
//------------------------------------------------------------------------

class ListeChainee 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    
    ElemListe * GetHead() const ;
    // Mode d'emploi : Appeler la méthode GetHead sur un objet de la classe ListeChainee pour obtenir la tête de la liste
    // Return : un pointeur de type ElemListe * vers l'élément de tête de la liste chaînée
    // Contrat :

    int GetNbElem() const ;
    // Mode d'emploi : Appeler la méthode GetNbElem sur un objet de la classe ListeChainee pour obtenir le nombre d'éléments dans la liste
    // Return : le nombre (int) d'éléments dans la liste
    // Contrat :

    void AjouterEnFin(Trajet* newTrajet);
    // Mode d'emploi : Prend un paramètre de type Trajet * et l'ajoute à la fin de la liste
    //
    // Contrat :

    void Afficher() const;
    // Mode d'emploi : Affiche tous les éléments de la liste
    //
    // Contrat :



//-------------------------------------------- Constructeurs - destructeur
    ListeChainee ( );
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //


    virtual ~ListeChainee ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ElemListe* head;
    ElemListe* tail;
    int nbElem;
};

//-------------------------------- Autres définitions dépendantes de <ListeChainee>

#endif // ListeChainee_H

