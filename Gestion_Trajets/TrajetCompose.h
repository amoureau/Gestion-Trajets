
/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

#include "Trajet.h"
#include "TrajetSimple.h"
#include "ListeChainee.h"
#include "ElemListe.h"

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
/*
 * Classe TrajetCompose
 * 
 * Cette classe représente un trajet composé, c'est-à-dire un trajet qui est constitué de plusieurs trajets simples.
 * Elle hérite de la classe Trajet.
 * 
 * Le rôle de cette classe est de permettre la gestion et l'affichage des détails d'un trajet composé, tels que le point de départ, le point d'arrivée global
 * et la décomposition en trajets simples.
 */
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual void Afficher() const;
    // Mode d'emploi : Affiche les détails (départ/arrivée global, décomposition en trajets simples) du trajet
    //
    // Contrat :
    //

    void Ajouter(Trajet* ajout);
    // Mode d'emploi : Ajoute un trajet simple à la liste des trajets composant le trajet composé
    //
    // Contrat :
    //

    virtual void Save(std::ofstream& fichier) const;

    virtual std::string GetType() const;

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose(Trajet* trajInit, const char* from, const char* to);
    // Mode d'emploi : Constructeur de la classe TrajetCompose qui prend en paramètre un trajet simple, un point de départ et un point d'arrivée
    //
    // Contrat :
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi : Destructeur de la classe TrajetCompose
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
ListeChainee* trajets;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H
