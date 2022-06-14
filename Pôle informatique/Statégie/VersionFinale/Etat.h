#ifndef ETAT_H
#define ETAT_H

#include <vector>
#include <string>

#include "Arc.h"
#include "Transition.h"

class Etat
{
    public:
        //Constructeurs
        Etat(int i, string n);
        Etat();
        virtual ~Etat();

        //GETTERS SETTERS
        int getId();
        string getNom();
        int getNbsorties();
        vector<Etat*> getvectEtats();
        vector<Transition*> getvectTransitions();

        //Fonction de v�rification visuelle des voisins de l'�tat
        void afficherArcs();
        //M�thodes pour attacher un �tat � l'�tat courant
        void addArc(Etat &e, Transition &t);
        void addArc(int i, Transition &t);

        //M�thodes de g�n�ration (PLUS D'ACTUALITE)
        void genererProgrammes();
        string genererEntetes();

        void setEtat(bool); //Set ou unset l'activit� de cet �tat
        void setPhase(int); // Set la phase dans lequel est l'�tat | 1 2 3 4 (IN RUN OUT ARURG)
        void setType(int); //Set le type de l'�tat | 1 2 3 (INITIAL COURANT FINAL)
    private:
        //Caract�ristiques de cet Etat
        unsigned int id;
        string nom;
        unsigned int nb_sorties;

        //Renvoie l'�tat des transitions de l'�tat sous forme d'un mot binaire (voir rapport MoteurDeGraphe)
        unsigned int motBinaire;

        //Etats voisins de cet Etat
        vector <Etat*> vectEtats;
        //Transitions de cet Etat
        vector <Transition*> vectTransitions;
};

#endif // ETAT_H
