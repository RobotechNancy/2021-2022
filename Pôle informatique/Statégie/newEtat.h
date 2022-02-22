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

        //Fonction de vérification visuelle des voisins de l'état
        void afficherArcs();
        //Méthodes pour attacher un état à l'état courant
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
