#include "newEtat.h"
#include "Arc.h"

#include <string>
#include <vector>
#include <iostream>


using namespace std;

newEtat::newEtat(int i, string n)
{
    id = i;
    nom = n;
    nb_sorties = 0;
    //voir comment gérer le tableau
}

newEtat::newEtat()
{
}

newEtat::~newEtat()
{
    //dtor
}

//Fonction qui permet d'ajouter un voisin à l'état courant
void newEtat::addArc(newEtat &e, Transition &t){
    vectEtats.push_back(&e);
    vectTransitions.push_back(&t);
    nb_sorties++;
}

//fonction de test qui permet d'afficher les voisins de l'état courant
void newEtat::afficherArcs(){
    for (int i = 0; i < nb_sorties; i++){
        cout << vectEtats[i] << endl;
        cout << vectTransitions[i] << endl;
    }
}

//GETTERS SETTERS
int newEtat::getId(){
    return id;
}

string newEtat::getNom(){
    return nom;
}

int newEtat::getNbsorties(){
    return nb_sorties;
}

vector<newEtat*> newEtat::getvectEtats(){
    return vectEtats;
}
vector<Transition*> newEtat::getvectTransitions(){
    return vectTransitions;
}

//Générer ce qu'on appelle les entêtes = fonctions IN RUN et OUT de l'état courant
string newEtat::genererEntetes(){
    string ret = "\t\t" + nom + "IN();\n" +
    "\t\t" + nom + "RUN();\n" +
    "\t\t" + nom + "OUT();";
    return ret;
}

//Génération du programme d'un état :
//Génération de l'entête de l'état courant
//Puis des conditions des transitions et des entêtes des états voisins sous forme de if elseif
void newEtat::genererProgrammes(){
    genererEntetes();
    //Pour tous les états de la liste des arcs faire l'affichage
    //Si on est sur la première transition alors c'est if autrement else if
    for (int i = 0; i < nb_sorties; i++){
        cout << (i==0?"if(":"else if(") << vectTransitions[i]->Getcondition() << "){" << endl;
        vectEtats[i]->genererEntetes();
        cout << "}" << endl;
    }
}


