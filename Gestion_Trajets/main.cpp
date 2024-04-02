#include <iostream>
#include <cstring>
#include "ListeChainee.h"
#include "ElemListe.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

using namespace std;

int main() {
    //Initialisation des variables, pointeurs et du catalogue
    int choixMode = 0;
    int choixTrajet = 0;
    Catalogue Cat; // Création du catalogue

    bool finAjout = false;
    int nbTrajets = 1;
    int choixArret = 0;
    int choixSave;

    char* depart = nullptr;
    char* arrivee = nullptr;
    char* transport = nullptr;
    char* departRecherche = nullptr;
    char* arriveeRecherche = nullptr;
    

    while (choixMode != 6) { // Tant que l'utilisateur ne veut pas quitter le programme
        cout << endl;
        cout << "Que voulez vous faire ?" << endl;
        cout << "1. Ajouter un trajet" << endl;
        cout << "2. Afficher le catalogue" << endl;
        cout << "3. Rechercher un trajet" << endl;
        cout << "4. Sauvegarder le catalogue" << endl;
        cout << "5. Charger le catalogue" << endl;
        cout << "6. Abandon" << endl;
        if (!(cin >> choixMode)) {
            // En cas d'échec de la saisie, on vide le tampon et on ignore la ligne
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << endl;
        switch(choixMode) {
            case 1: // Ajout d'un trajet
                depart = new char[25];
                arrivee = new char[25];
                transport = new char[25];
                choixTrajet = 0;
                cout << "Quel type de trajet voulez vous ajouter ?" << endl;

                while (choixTrajet != 1 && choixTrajet != 2 && choixTrajet != 3) {
                    cout << "1. Trajet Simple" << endl;
                    cout << "2. Trajet Composé" << endl;
                    cout << "3. Revenir à l'étape précédente" << endl;
                    if (!(cin >> choixTrajet)) {
                        // En cas d'échec de la saisie, on vide le tampon et on ignore la ligne
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Erreur de saisie. Veuillez entrer une valeur valide." << endl << endl;
                    }
                }

                cout << endl;
                switch(choixTrajet) {
                    case 1: // Ajout d'un trajet simple
                    {
                        cout << "Donner le départ du trajet" << endl;
                        cin >> depart;
                        cout << "Donner l'arrivée du trajet" << endl;
                        cin >> arrivee;
                        cout << "Donner le mode de transport du trajet" << endl;
                        cin >> transport;
                        TrajetSimple* Traj = new TrajetSimple(depart,arrivee,transport); // Création du trajet simple
                        Cat.Ajouter(Traj); // Ajout du trajet simple au catalogue
                        break;
                    }
                    case 2: // Ajout d'un trajet composé
                    {  
                        finAjout = false;
                        nbTrajets = 1;
                        choixArret = 0;
                        // Ajout du premier trajet simple
                        cout << "Donner le départ du trajet composant votre trajet composé n°" << nbTrajets << endl;
                        cin >> depart;
                        cout << "Donner l'arrivée du trajet composant votre trajet composé n°" << nbTrajets << endl;
                        cin >> arrivee;
                        cout << "Donner le mode de transport du trajet composant votre trajet composé n°" << nbTrajets << endl;
                        cin >> transport;
                        nbTrajets++;

                        while (choixArret != 1 && choixArret != 2) {
                            cout << "1. Continuer à ajouter" << endl;
                            cout << "2. Arrêter" << endl;
                            if (!(cin >> choixArret)) {
                                // En cas d'échec de la saisie, on vide le tampon et on ignore la ligne
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Erreur de saisie. Veuillez entrer une valeur valide." << endl << endl;
                            }
                        }

                        if (choixArret == 2) { // Si l'utilisateur veut arrêter d'ajouter des trajets simples
                            finAjout = true;
                        }

                        TrajetSimple* T1 = new TrajetSimple(depart,arrivee,transport); // Création du premier trajet simple
                        TrajetCompose* Tc = new TrajetCompose(T1,depart,arrivee); // Création du trajet composé avec le premier trajet simple

                        while (!finAjout) { // Tant que l'utilisateur veut ajouter des trajets simples
                            choixArret = 0;
                            cout << "Donner le départ du trajet composant votre trajet composé n°" << nbTrajets << endl;
                            cin >> depart;
                            while (strcmp(depart, arrivee) != 0) { // Tant que le départ du trajet simple n'est pas l'arrivée du trajet précédent
                                cout << "Erreur de saisie. Le départ du trajet simple doit être l'arrivée du trajet précédent." << endl;
                                cout << "Donner le départ du trajet composant votre trajet composé n°" << nbTrajets << endl;
                                cin >> depart;
                            }
                            cout << "Donner l'arrivée du trajet composant votre trajet composé n°" << nbTrajets << endl;
                            cin >> arrivee;
                            cout << "Donner le mode de transport du trajet composant votre trajet composé n°" << nbTrajets << endl;
                            cin >> transport;
                            nbTrajets++;

                            TrajetSimple* Ttemp = new TrajetSimple(depart,arrivee,transport); // Création du trajet simple
                            Tc->Ajouter(Ttemp); // Ajout du trajet simple au trajet composé

                            while (choixArret != 1 && choixArret != 2) {
                                cout << "1. Continuer à ajouter" << endl;
                                cout << "2. Arrêter" << endl;
                                if (!(cin >> choixArret)) {
                                    // En cas d'échec de la saisie, on vide le tampon et on ignore la ligne
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                    cout << "Erreur de saisie. Veuillez entrer une valeur valide." << endl << endl;
                                }
                            }
                            cout << endl;
                            if (choixArret == 2) { // Si l'utilisateur veut arrêter d'ajouter des trajets simples
                                finAjout = true;
                            }
                        }
                        Cat.Ajouter(Tc); // Ajout du trajet composé au catalogue
                        break;
                    }
                    case 3: // Retour à l'étape précédente
                        break;
                    default: // Erreur de saisie
                        cout << "Erreur de saisie. Veuillez entrer une valeur valide." << endl;
                        cin.clear();
                        break;
                }
                delete[] depart; delete[] arrivee; delete[] transport; // Libération de la mémoire
                break;

            case 2: // Affichage du catalogue
                Cat.Afficher(); 
                break;

            case 3: // Recherche d'un trajet
                departRecherche = new char[25];
                arriveeRecherche = new char[25];
                cout << "Donner le départ du trajet recherché" << endl;
                cin >> departRecherche;
                cout << "Donner l'arrivée du trajet recherché" << endl;
                cin >> arriveeRecherche;

                Cat.RechercheAvancee(departRecherche,arriveeRecherche); // Appel de la méthode de recherche avancée
                delete[] departRecherche; delete[] arriveeRecherche; // Libération de la mémoire
                break;

            case 4: // Sauvegarde du catalogue*
                
                cout << "1. Sauvergarder tous les trajets" << endl;
                cout << "2. Sauvegarder les trajets simples" << endl;
                cout << "3. Sauvegarder les trajets composés" << endl;
                if (!(cin >> choixSave)) {
                    // En cas d'échec de la saisie, on vide le tampon et on ignore la ligne
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                Cat.Sauvegarder("Catalogue.txt", choixSave); // Appel de la méthode de sauvegarde

                break;
            case 5: //Charge le catalogue
                Cat.Charger("Catalogue.txt");
                break;
            case 6: // Quitter le programme
                break;

            default: // Erreur de saisie
                cout << "Erreur de saisie. Veuillez entrer une valeur valide." << endl;
                cin.clear();
                continue;
        }
    }   
}
