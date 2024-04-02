
/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
/*
 * Classe Trajet
 * Classe parente de TrajetSimple et TrajetCompose
 *
 * La classe Trajet représente un trajet entre deux points, avec un point de départ et un point d'arrivée.
 * Elle permet d'afficher les détails du trajet et d'obtenir les informations sur le point de départ et d'arrivée.
 */
//
//------------------------------------------------------------------------

class Trajet 
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
    // Mode d'emploi : Affiche les détails (départ, arrivée) du trajet
    //                 Virtual car la méthode est redéfinie dans les classes filles
    // Contrat :
    //
    char* GetDepart() const;
    // Mode d'emploi : Appeler la méthode GetDepart sur un objet de la classe Trajet pour obtenir le point de départ du trajet
    //
    // Contrat :
    //

    char* GetArrivee() const;
    // Mode d'emploi : Appeler la méthode GetArrivee sur un objet de la classe Trajet pour obtenir le point d'arrivée du trajet
    //
    // Contrat :
    //

    virtual std::string GetType() const;

    virtual void Save(std::ofstream& fichier) const;

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    Trajet ( const char* from, const char* to);
    // Mode d'emploi : Constructeur qui prend en paramètre le point de départ et le point d'arrivée du trajet
    //
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char* arrivee;
char* depart;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H

