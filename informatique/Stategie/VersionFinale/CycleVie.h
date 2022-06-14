#ifndef CYCLEVIE_H
#define CYCLEVIE_H

#include <vector>

#include "Graphe.h"

class CycleVie
{
    public:
        //Constructeur et Destructeur
        CycleVie();
        virtual ~CycleVie();

        //ajouter un graphe au cycle de vie
        void addGraphe(Graphe &adGraphe);
        //Rendre le graphe actif
        void addActif(Graphe &adGraphe);
        //Ne plus laisser le graphe actif
        void delActif(Graphe &adGraphe);

        //Générer le code (des graphes actifs)
        void Generer();
        //TESTS
        void GenererFonctions();
        void resetFonctionGraphe();
        //Getters Setters
        int GetmotBinaireActifs();
        int GetnbGraphes() { return nb_graphesActifs; }
        void SetnbGraphes(int val) { nb_graphesActifs = val; }
    private:
        vector <Graphe*> vectGraphes;
        unsigned int nb_graphesActifs;
        unsigned int motBinaireActifs;
//        vector <Graphe*> vectGraphesActifs;
};

#endif // CYCLEVIE_H
