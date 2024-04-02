/*************************************************************************
                           Catalogue  -  description
                             -------------------
    dÃ©but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- RÃ©alisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Mthodes publiques
// type Catalogue::Méthode ( liste des paramÃ¨tres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

// Méthode pour ajouter un trajet au catalogue
void Catalogue::Ajouter(Trajet* ajout) {
    trajets->AjouterEnFin(ajout); // Ajout du trajet à la fin de la liste
} //----- Fin de Ajouter

void Catalogue::Sauvegarder(const char* nomFichier, int mode) const {
    ofstream fichier(nomFichier, ios::out | ios::trunc); // Ouverture du fichier en écriture
    if(fichier.is_open()) { // Si le fichier est ouvert
        ElemListe* cur = trajets->GetHead();
        while(cur!= nullptr){ // Parcours de la liste
            if ((mode == 2 && cur->GetTrajet()->GetType() == "C")|| (mode == 3 && cur->GetTrajet()->GetType() == "S")) {
                cur = cur->GetNext(); // Passage au trajet suivant
                continue;
            }
            cur->GetTrajet()->Save(fichier); // Sauvegarde du trajet
            fichier << endl; 
            cur = cur->GetNext(); // Passage au trajet suivant
        }
        fichier.close(); // Fermeture du fichier
    } else {
        cerr << "Erreur à l'ouverture !" << endl;
    }
} //----- Fin de Sauvegarder

void Catalogue::Charger(std::string nomFichier) {
    std::ifstream fichier(nomFichier);
    if (fichier) {
        string ligne;
        while (getline(fichier, ligne)) {
            string depart, arrivee, transport, type, nombreTraj;
            type = ligne[0];
            int nbTrajets;
            int i = 2;
            if (type == "S") {
                while (ligne[i] != ';') {
                    depart += ligne[i];
                    i++;
                }
                i++;
                while (ligne[i] != ';') {
                    arrivee += ligne[i];
                    i++;
                }
                i++;
                while (ligne[i] != ';') {
                    transport += ligne[i];
                    i++;
                }
                Trajet* trajet = new TrajetSimple(depart.c_str(), arrivee.c_str(), transport.c_str());
                Ajouter(trajet);
                continue;
            }
            if (type == "C") {
                string arrivee_globale, depart_global;



                while (ligne[i] != ';') {
                        nombreTraj += ligne[i];
                        i++;
                    }
                nbTrajets = stoi(nombreTraj);
                    i++;


                while (ligne[i] != ';') {
                        depart_global += ligne[i];
                        i++;
                    }
                    i++;
                    while (ligne[i] != ';') {
                        arrivee_globale += ligne[i];
                        i++;
                    }
                    i = i+3;
                
                while (ligne[i] != ';') {
                        depart += ligne[i];
                        i++;
                    }
                    i++;
                    while (ligne[i] != ';') {
                        arrivee += ligne[i];
                        i++;
                    }
                    i++;
                    while (ligne[i] != ';') {
                        transport += ligne[i];
                        i++;
                    }
                    i = i+3;
                Trajet* trajetSimple = new TrajetSimple(depart.c_str(), arrivee.c_str(), transport.c_str());
                TrajetCompose* trajet = new TrajetCompose(trajetSimple, depart.c_str(), arrivee.c_str());
                for (int j = 1; j < nbTrajets; j++) {
                    string depart, arrivee, transport;
                    while (ligne[i] != ';') {
                        depart += ligne[i];
                        i++;
                    }
                    i++;
                    while (ligne[i] != ';') {
                        arrivee += ligne[i];
                        i++;
                    }
                    i++;
                    while (ligne[i] != ';') {
                        transport += ligne[i];
                        i++;
                    }
                    i = i + 3;
                    Trajet* trajetSimple = new TrajetSimple(depart.c_str(), arrivee.c_str(), transport.c_str());
                    trajet->Ajouter(trajetSimple);
                }

                Ajouter(trajet);
                continue;
            }
        }
    } else {
        cout << "Erreur lors de l'ouverture du fichier" << endl;
    }
} //----- Fin de Charger


//Méthode pour rechercher un trajet dans le catalogue
void Catalogue::Rechercher(const char* depart, const char* arrivee) const {
    ElemListe* cur = trajets->GetHead();
    bool trouve = false;
    while(cur!= nullptr){ // Parcours de la liste
        if(strcmp(cur->GetTrajet()->GetDepart(),depart) == 0 && strcmp(cur->GetTrajet()->GetArrivee(),arrivee)==0){ // Si le trajet a le même départ et la même arrivée
            cur->GetTrajet()->Afficher(); // Affichage du trajet
            trouve = true;
        }
        cur = cur->GetNext(); // Passage au trajet suivant
    }
    if (!trouve) { // Si aucun trajet n'a été trouvé
        cout << "Pas Trouvé" << endl;
    } 
} //----- Fin de Rechercher

//Méthode pour rechercher un trajet dans le catalogue en faisant des combinaisions de trajets
void Catalogue::RechercheAvancee(const char* depart, const char* arrivee) const {
    cout << endl;
    bool* visited = new bool[trajets->GetNbElem()+1]{0}; // Tableau de booléens pour savoir si un trajet a déjà été utilisé
    if (!Recursion(depart, arrivee, visited, 0)) { // Appelle de la méthode récursive
        cout << "Pas Trouvé" << endl; // si aucun trajet n'a été trouvé
    }
    delete[] visited;
} //----- Fin de RechercheAvancee


// Méthode pour afficher tous les trajets du catalogue
void Catalogue::Afficher() const {
    ElemListe* cur = trajets->GetHead();
    int nbAffiches = 1;
    while(cur!= nullptr){ // Parcours de la liste
        cout << nbAffiches++ << ". ";
        cur->GetTrajet()->Afficher(); // Affichage du trajet
        cur = cur->GetNext(); // Passage au trajet suivant
    }
} //----- Fin de Afficher




//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
trajets = new ListeChainee; // Création de la liste de trajets
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
delete trajets; // Destruction de la liste de trajets
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- MÃ©thodes protégées
bool Catalogue::Recursion(const char* depart, const char* arrivee, bool * visite, int depth) const {
    if (strcmp(depart, arrivee) == 0) { // Si le départ et l'arrivée sont les mêmes
        return true;
    }

    ElemListe* cur = trajets->GetHead();
    bool trouve = false;
    int i = 0;

    while(cur!= nullptr){ // Parcours de la liste
        if(strcmp(cur->GetTrajet()->GetArrivee(),arrivee)==0 && !visite[i]){ // Si le trajet a la même arrivée et n'a pas déjà été utilisé
            visite[i] = 1; // On marque le trajet comme utilisé
            if (Recursion(depart, cur->GetTrajet()->GetDepart(), visite, depth+1)) { // On appelle la méthode récursive avec le départ du trajet comme arrivée
                
                cur->GetTrajet()->Afficher(); // Affichage du trajet
                trouve = true; // On a trouvé au moins un trajet
            }
            visite[i] = 0;  // On marque le trajet comme non utilisé
        }
        cur = cur->GetNext(); // Passage au trajet suivant
        if (depth == 0) cout << endl << "- ";
        i++;
    }
    return trouve; // On renvoie true si on a trouvé au moins un trajet, false sinon
}   //----- Fin de Recursion