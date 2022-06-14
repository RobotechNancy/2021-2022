#include "Graphe.h"
#include "../MesFonctions.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <stdio.h>
#include <string>
#include <thread>

#include "../rapidxml/rapidxml_utils.hpp"

using namespace std;
using namespace rapidxml;

Graphe::Graphe()
{
}

Graphe::Graphe(Etat &initEtat, Etat &currEtat)
{
    etatInit = &initEtat;
    etatCourant = &currEtat;
    nom = currEtat.getNom();
    nb_sorties = currEtat.getNbsorties();
    vectEtats = currEtat.getvectEtats();
    vectTransitions = currEtat.getvectTransitions();
    temporisation = boucle = 0;
    trameTemporisation = 0b0;

    //Ajouté à l'arrache
    nb_etats = vectEtats.size();
    nb_transitions = vectTransitions.size();
}

Graphe::~Graphe()
{
}

void Graphe::SetetatCourant(Etat &val)
{
    cout << "Etat courant set " << etatCourant->getId() << "->" << val.getId() << endl;
    etatCourant = &val;
    nom = val.getNom();
    nb_sorties = val.getNbsorties();
    vectEtats = val.getvectEtats();
    vectTransitions = val.getvectTransitions();
    trameTemporisation = 0b0;
}
void Graphe::setvectEtats(vector<Etat*> &x){ vectEtats=x; }
void Graphe::setvectTransitions(vector<Transition*> &x){ vectTransitions=x; }

//Ecrit dans les logs les informations de temps et de boucle du moteur de graphe
void Graphe::AjouterLogs(int temps){
    cout << "transitionne" << endl;
    ofstream myfile;
    myfile.open ("Logs.txt",ios::out | ios::app);
//    myfile << "test" << endl;
    myfile << "00000000" << std::bitset<8>(etatCourant->getId()).to_string() << std::bitset<8>(boucle).to_string() << std::bitset<8>(temps).to_string() << endl;

    myfile.close();
}


void Graphe::setTransi(int idTransi, bool valeur){
    if (valeur)
        trameTemporisation += pow(2, idTransi);
    else
        trameTemporisation -= pow(2, idTransi);
}
void Graphe::clearTransi(){
    trameTemporisation = 0b0;
}

// Fonction qui lit teste l'état des transitions par rapport aux variables en temps réel du robot (temp, boucle, égalité, etc.)
int Graphe::TesterSorties(){
    string cond;
    int a,b;

    unsigned int parcourt=0;
    //Hypothèse que le programme ne peut aller que dans une branche à la fois
    while(parcourt < nb_sorties){
        cond = vectTransitions[parcourt]->Getcondition();
        //Mettre RETURN FALSE dans les case if
        switch(vectTransitions[parcourt]->Gettype()){
            case 1:
                {
                    a = stoi(cond.substr(0,cond.find("=")));
                    b = stoi(cond.substr(cond.find("=")+1, cond.size()));
                    if (a == b){
                        cout << "Egalite passee" << endl;
                        setTransi(parcourt, true);
                        return vectTransitions[parcourt]->Gettype();
                    }
                    break;
                }
            case CodeEgaliteFonction:
                {
                    //Variable à utiliser dans un header fonction
                    // Gérer des potentiels paramètres à cette fonctions

                    //condition cond qui est la valeur que l'on souhaite avoir à droite de l'égalité
                    // on doit faire en sorte de faire un header à variables avec des fonctions à return pour faire l'égalité
                    switch(vectTransitions[parcourt]->Getoperateur())
                        case CodeEgal:
                            {
                                string fc = vectTransitions[parcourt]->GetFonctVar();
                                if (headerFcts(fc) == stoi(cond)){ //Faire le header ici
                                    cout << "EGALITE passée" << endl;
                                    setTransi(parcourt, true);
                                    return vectTransitions[parcourt]->Gettype();
                                }
                                break;
                            }
                        case CodeSup:
                            {
                                string fc = vectTransitions[parcourt]->GetFonctVar();
                                if (headerFcts(fc) > stoi(cond)){
                                    cout << "SUP passée" << endl;
                                    setTransi(parcourt, true);
                                    return vectTransitions[parcourt]->Gettype();
                                }
                                break;
                            }
                        case CodeSupEgal:
                            {
                                string fc = vectTransitions[parcourt]->GetFonctVar();
                                if (headerFcts(fc) >= stoi(cond)){
                                    cout << "SUPEGAL passée" << endl;
                                    setTransi(parcourt, true);
                                    return vectTransitions[parcourt]->Gettype();
                                }
                                break;
                            }
                        case CodeInf:
                            {
                                string fc = vectTransitions[parcourt]->GetFonctVar();
                                if (headerFcts(fc) < stoi(cond)){
                                    cout << "INF passée" << endl;
                                    setTransi(parcourt, true);
                                    return vectTransitions[parcourt]->Gettype();
                                }
                                break;
                            }
                        case CodeInfEgal:
                            {
                                string fc = vectTransitions[parcourt]->GetFonctVar();
                                if (headerFcts(fc) <= stoi(cond)){
                                    cout << "INFEGAL passée" << endl;
                                    setTransi(parcourt, true);
                                    return vectTransitions[parcourt]->Gettype();
                                }
                                break;
                            }
                        case CodeDiff:
                            {
                                string fc = vectTransitions[parcourt]->GetFonctVar();
                                if (headerFcts(fc) != stoi(cond)){
                                    cout << "DIFF passée" << endl;
                                    setTransi(parcourt, true);
                                    return vectTransitions[parcourt]->Gettype();
                                }
                                break;
                            }

                    break;
                }

            case CodeArretUrgence:
                {
                    //tester si le passage à l'arret d'urgence doit se faire
                    //->Lire si le bouton est activé ou pas
                    if (1){
                        cout << "passage arrêt d'urgence" << endl;
                        setTransi(parcourt, true);
                        return vectTransitions[parcourt]->Gettype();
                    }
                    break;
                }
            case CodeTemporisation:
                {
                    unsigned int temps = Gettemporisation();
                    cout << cond << " " << temps << endl;
                    if (stoi(cond) <= temps){
                        cout << "temporisation passee" << endl;
                        setTransi(parcourt, true);
                        return vectTransitions[parcourt]->Gettype();
                    }
                    break;
                }

            case CodeBoucle:
                int boucle = Getboucle();
                cout << cond << " " << boucle << endl;
                if (stoi(cond) <= boucle){
                    cout << "Boucle passee" << endl;
                    setTransi(parcourt, true);
                    return vectTransitions[parcourt]->Gettype();
                }
                break;
        }
        parcourt++;
    }
    return -1;
}

//1 seule transi peut être valide à la fois
int Graphe::getTransi(){
    for(unsigned int c=0; c<nb_sorties; c++){
        if (trameTemporisation == pow(2, c))
            return c;
    }
    return -1;
}


void Graphe::InitialiserEnfants(int nbEnfants){
    thread tabThreads[nbEnfants];
    for(int c=0; c < nbEnfants; c++){
        tabThreads[c] = std::thread([&](int id) {
            vectEnfants[id]->Executer();
        }, c);
    }
}

void Graphe::addEnfants(Graphe* enfant){
    vectEnfants.push_back(enfant);
    Nombre_enfants ++;
}

void Graphe::activerEnfant(unsigned int indice){
    Etat_enfants += pow(2,2*indice);
}
void Graphe::activerGraphesEnfants(){
    for(unsigned int c=0; c<Nombre_enfants; c++){
        activerEnfant(c);
        //Faire avec les threads
    }
}
void Graphe::terminerEnfant(unsigned int indice){
    Etat_enfants -= pow(2,2*indice);
    Etat_enfants += pow(2,2*indice + 1);
}

// Fonction qui exécute le moteur de graphe
bool Graphe::Executer(){
    int typeTransi = TesterSorties();

    int idTransi = getTransi();

    cout << "transi " << typeTransi << endl;
    if (idTransi != -1){

        if(typeTransi == CodeArretUrgence){
            //Faire le out de la fonction ou passer directement dans l'état d'urgence ?
            //headerFonctions(nom + "OUT");

            //Faire un attribut EtatUrgence booleen qui permet de savoir si on n'est dans cet état | Permet également de stocker la valeur de l'état "précédent"
            SetetatPrecedent(*etatCourant);
            headerFonctions("ArretUrgence");
        }
        else {
            headerFonctions(nom + "OUT");
            SetetatPrecedent(*etatCourant);
            SetetatCourant(*vectEtats[idTransi]);
            headerFonctions(nom + "IN");
            //Lancer l'exécution des enfants de l'état suivant ? Sous forme de thread ?

        }


        return false;
    }
    headerFonctions(nom + "RUN");
    return true;
}
