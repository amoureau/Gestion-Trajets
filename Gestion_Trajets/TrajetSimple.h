/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

#include "Trajet.h"
//--------------------------------------------------- Interfaces utilisées
#include <cstring>
//---------------#---------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
/*
 * classe TrajetSimple
 * Classe représentant un trajet simple.
 *
 * La classe TrajetSimple hérite de la classe Trajet et permet de représenter un trajet simple
 * entre deux villes en spécifiant le moyen de transport utilisé.
 */
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
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
    // Mode d'emploi : Affiche les détails (départ, arrivée, moyen de transport) du trajet
    //
    // Contrat :
    //

    virtual void Save(std::ofstream& fichier) const;
    
    virtual std::string GetType() const;

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    TrajetSimple (const char* from,const char* to, const char* moyen_transport);
    // Mode d'emploi : Constructeur de la classe TrajetSimple qui prend en paramètres le point de départ, le point d'arrivée et le moyen de transport utilisé
    //
    // Contrat :
    //

    virtual ~TrajetSimple ( );
    // Mode d'emploi : Destructeur de la classe TrajetSimple
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char* moyen_transport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H

