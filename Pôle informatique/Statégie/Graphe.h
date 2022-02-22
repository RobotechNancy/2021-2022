#ifndef GRAPHE_H
#define GRAPHE_H

#include "newEtat.h"

class Graphe
{
    public:
        Graphe();
        //Constructeur
        Graphe(newEtat &initEtat, newEtat &currEtat);
        virtual ~Graphe();

        //Fonction qui permet de g�n�rer le programme du graphe courant
        void genererProgrammes();
        //fonction permet de g�n�rer les ent�tes des "fonctions" (=nom des etats voisins � l'�tat courant)
        void genererFonctions();

       string genererEntetes();
        void Generer();

        //Getters Setters
        newEtat* GetetatInit() { return etatInit; }
        void SetetatInit(newEtat* val) { etatInit = val; }
        newEtat* GetetatCourant() { return etatCourant; }
        void SetetatCourant(newEtat &val);
        void setvectEtats(vector<newEtat*> &x);
        void setvectTransitions(vector<Transition*> &x);
    private:
        //Etat initial du graphe
        newEtat* etatInit;
        //Etat courant du graphe
        newEtat* etatCourant;
        string nom;
        int nb_sorties;
        //Etats voisins de l'�tat courant par les transitions donn�es (rang�s dans le m�me ordre dans les 2 matrices)
        vector <newEtat*> vectEtats;
        vector <Transition*> vectTransitions;
};

#endif // GRAPHE_H
