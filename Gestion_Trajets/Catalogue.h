/*************************************************************************
                           Catalogue  -  description
                             -------------------
    dÃ©but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisÃ©es
#include "ListeChainee.h"
#include "Trajet.h"
#include "ElemListe.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
/*
 * class Catalogue
 * Classe représentant un catalogue de trajets.
 *
 * Cette classe permet de gérer un catalogue de trajets en ajoutant, affichant et recherchant des trajets.
 */
//
//------------------------------------------------------------------------

class Catalogue 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter(Trajet* add);
    // Mode d'emploi : Prend un paramètre de type Trajet * et l'ajoute à la fin de la liste de trajets
    //
    // Contrat :
    //

    void Sauvegarder(const char* nomFichier, int mode) const;

    void Charger(std::string nomFichier);

    virtual void Afficher() const;
    // Mode d'emploi : Affiche tous les trajets du catalogue
    //
    // Contrat :
    //

    void Rechercher(const char* depart, const char* arrivee) const;
    // Mode d'emploi : Prend deux paramètres de type const char * et affiche tous les trajets du catalogue qui ont le même départ et la même arrivée
    //
    // Contrat :
    //

    void RechercheAvancee(const char* depart, const char* arrivee) const;
    // Mode d'emploi : Prend deux paramètres de type const char * et affiche tous les trajets du catalogue qui ont le même départ et la même arrivée
    //                 en combinant différents trajets (simples ou composés)
    //                 Utilise la méthode Recursion pour trouver tous les trajets possibles et les afficher, si il n'y en a pas, affiche "Pas Trouvé"
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opÃ©rateurs

//-------------------------------------------- Constructeurs - destructeur

    Catalogue ();
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
bool Recursion(const char* depart, const char* arrivee, bool * visite, int depth) const;
// Mode d'emploi : Prend deux paramètres de type const char *, un tableau de booléens et un entier
//                 et affiche tous les trajets du catalogue qui ont le même départ et la même arrivée que les deux premiers paramètres
//                 en combinant différents trajets (simples ou composés) 
//                 S'appelle de manière récursive pour trouver tous les trajets possibles et les afficher et renvoie true si il y en a au moins un, false sinon
// Contrat :

//----------------------------------------------------- Attributs protégés
ListeChainee* trajets;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>
#endif // Catalogue_H
