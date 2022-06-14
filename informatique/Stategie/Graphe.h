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

        //Fonction qui permet de générer le programme du graphe courant
        void genererProgrammes();
        //fonction permet de générer les entêtes des "fonctions" (=nom des etats voisins à l'état courant)
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
        //Etats voisins de l'état courant par les transitions données (rangés dans le même ordre dans les 2 matrices)
        vector <newEtat*> vectEtats;
        vector <Transition*> vectTransitions;
};

#endif // GRAPHE_H
