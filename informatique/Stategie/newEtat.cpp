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
    //voir comment g�rer le tableau
}

newEtat::newEtat()
{
}

newEtat::~newEtat()
{
    //dtor
}

//Fonction qui permet d'ajouter un voisin � l'�tat courant
void newEtat::addArc(newEtat &e, Transition &t){
    vectEtats.push_back(&e);
    vectTransitions.push_back(&t);
    nb_sorties++;
}

//fonction de test qui permet d'afficher les voisins de l'�tat courant
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

//G�n�rer ce qu'on appelle les ent�tes = fonctions IN RUN et OUT de l'�tat courant
string newEtat::genererEntetes(){
    string ret = "\t\t" + nom + "IN();\n" +
    "\t\t" + nom + "RUN();\n" +
    "\t\t" + nom + "OUT();";
    return ret;
}

//G�n�ration du programme d'un �tat :
//G�n�ration de l'ent�te de l'�tat courant
//Puis des conditions des transitions et des ent�tes des �tats voisins sous forme de if elseif
void newEtat::genererProgrammes(){
    genererEntetes();
    //Pour tous les �tats de la liste des arcs faire l'affichage
    //Si on est sur la premi�re transition alors c'est if autrement else if
    for (int i = 0; i < nb_sorties; i++){
        cout << (i==0?"if(":"else if(") << vectTransitions[i]->Getcondition() << "){" << endl;
        vectEtats[i]->genererEntetes();
        cout << "}" << endl;
    }
}


