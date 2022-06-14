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

        //Fonction de vérification visuelle des voisins de l'état
        void afficherArcs();
        //Méthodes pour attacher un état à l'état courant
        void addArc(Etat &e, Transition &t);
        void addArc(int i, Transition &t);

        //Méthodes de génération (PLUS D'ACTUALITE)
        void genererProgrammes();
        string genererEntetes();

        void setEtat(bool); //Set ou unset l'activité de cet état
        void setPhase(int); // Set la phase dans lequel est l'état | 1 2 3 4 (IN RUN OUT ARURG)
        void setType(int); //Set le type de l'état | 1 2 3 (INITIAL COURANT FINAL)
    private:
        //Caractéristiques de cet Etat
        unsigned int id;
        string nom;
        unsigned int nb_sorties;

        //Renvoie l'état des transitions de l'état sous forme d'un mot binaire (voir rapport MoteurDeGraphe)
        unsigned int motBinaire;

        //Etats voisins de cet Etat
        vector <Etat*> vectEtats;
        //Transitions de cet Etat
        vector <Transition*> vectTransitions;
};

#endif // ETAT_H
