#include "Etat.h"
#include "Arc.h"

#include <string>
#include <vector>
#include <iostream>
#include <cmath>


using namespace std;

Etat::Etat(int i, string n)
{
    id = i;
    nom = n;
    nb_sorties = 0;

    //Je set la partie identifiant de la trame directement depuis le constructeur de la class
    motBinaire = i;

    //voir comment gérer le tableau
}

Etat::Etat()
{
}

Etat::~Etat()
{
    //dtor
}

//Fonction qui permet d'ajouter un voisin à l'état courant
void Etat::addArc(Etat &e, Transition &t){
    vectEtats.push_back(&e);
    vectTransitions.push_back(&t);
    nb_sorties++;
}

//fonction de test qui permet d'afficher les voisins de l'état courant
void Etat::afficherArcs(){
    for (unsigned int i = 0; i < nb_sorties; i++){
        cout << vectEtats[i]->getNom() << endl;
        cout << vectTransitions[i]->Getcondition() << endl;
    }
}

//GETTERS SETTERS
int Etat::getId(){
    return id;
}

string Etat::getNom(){
    return nom;
}

int Etat::getNbsorties(){
    return nb_sorties;
}

vector<Etat*> Etat::getvectEtats(){
    return vectEtats;
}
vector<Transition*> Etat::getvectTransitions(){
    return vectTransitions;
}

//Générer ce qu'on appelle les entêtes = fonctions IN RUN et OUT de l'état courant
string Etat::genererEntetes(){
    string ret = "\t\t" + nom + "IN();\n" +
    "\t\t" + nom + "RUN();\n" +
    "\t\t" + nom + "OUT();";
    return ret;
}

//Génération du programme d'un état :
//Génération de l'entête de l'état courant
//Puis des conditions des transitions et des entêtes des états voisins sous forme de if elseif
void Etat::genererProgrammes(){
    genererEntetes();
    //Pour tous les états de la liste des arcs faire l'affichage
    //Si on est sur la première transition alors c'est if autrement else if
    for (unsigned int i = 0; i < nb_sorties; i++){
        cout << (i==0?"if(":"else if(") << vectTransitions[i]->Getcondition() << "){" << endl;
        vectEtats[i]->genererEntetes();
        cout << "}" << endl;
    }
}

void Etat::setEtat(bool b){ //SET ou UNSET
    if(b)
        motBinaire += pow(2, 15);
    else
        motBinaire -= pow(2, 15);
}
void Etat::setPhase(int i){
    motBinaire+= pow(2, i+7); //car nous allouons la description de la phase aux bits 9 10 11 et 12 du mot binaire (2^9 10 11 12)
}
void Etat::setType(int i){
    motBinaire+= pow(2, i+11); //car nous allouons la description du type de l'étape aux bits 13 14 et 15 du mot binaire (2^12 13 14)
}
