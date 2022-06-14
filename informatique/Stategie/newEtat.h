#ifndef NEWETAT_H
#define NEWETAT_H

#include <vector>
#include <string>

#include "Arc.h"
#include "Transition.h"

class newEtat
{
    public:
        //Constructeurs
        newEtat(int i, string n);
        newEtat();
        virtual ~newEtat();

        //GETTERS SETTERS
        int getId();
        string getNom();
        int getNbsorties();
        vector<newEtat*> getvectEtats();
        vector<Transition*> getvectTransitions();

        //Fonction de v�rification visuelle des voisins de l'�tat
        void afficherArcs();
        //M�thodes pour attacher un �tat � l'�tat courant
        void addArc(newEtat &e, Transition &t);
        void addArc(int i, Transition &t);

        void genererProgrammes();
        string genererEntetes();
    private:
        int id;
        string nom;
        int nb_sorties;

        vector <newEtat*> vectEtats;
        vector <Transition*> vectTransitions;
};

#endif // NEWETAT_H
