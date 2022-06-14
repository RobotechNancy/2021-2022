#ifndef GRAPHE_H
#define GRAPHE_H

#define CodeTemporisation 2
#define CodeBoucle 3
#define CodeEgaliteVariable 4
#define CodeEgaliteFonction 5
#define CodeArretUrgence 7

#define CodeEgal 11
#define CodeSup 12
#define CodeSupEgal 13
#define CodeInf 14
#define CodeInfEgal 15
#define CodeDiff 16

#include "Etat.h"

class Graphe
{
    public:
        void remplace();

        Graphe();
        //Constructeur
        Graphe(Etat &initEtat, Etat &currEtat);
        virtual ~Graphe();

        //G�rer les transitions
        void setTransi(int idTransi, bool valeur);
        void clearTransi();
        int getTransi();


        int TesterSorties();

        //Lancer l'ex�cution du moteur de graphe
        bool Executer();

        //Ajouter dans le fichier log l'information de l'�tat en cours
        void AjouterLogs(int temps);


        void InitialiserEnfants(int nbEnfants);

        //TEST
        void testThread(int nb);

        //Getters Setters
        Etat* GetetatInit() { return etatInit; }
        void SetetatInit(Etat* val) { etatInit = val; }
        int Getboucle() { return boucle; }
        void Setboucle(int val) { boucle = val; }
        int Gettemporisation() { return temporisation; }
        void Settemporisation(int val) { temporisation = val; }
        Etat* GetetatCourant() { return etatCourant; }
        void SetetatCourant(Etat &val);
        Etat* GetetatPrecedent() { return etatPrecedent; }
        void SetetatPrecedent(Etat &val){etatPrecedent = &val;}
        void setvectEtats(vector<Etat*> &x);
        void setvectTransitions(vector<Transition*> &x);

        // Fonctions pour la cr�ation de graphes Enfants
        void addEnfants(Graphe* g);
        void activerEnfant(unsigned int indice);
        void terminerEnfant(unsigned int indice);
        void activerGraphesEnfants();

    private:
        //Etat initial du graphe
        Etat* etatInit;

        //Etat pr�c�dent du graphe
        Etat* etatPrecedent;

        //Etat courant du graphe
        Etat* etatCourant;
        string nom;
        unsigned int nb_sorties;
        //Etats voisins de l'�tat courant par les transitions donn�es (rang�s dans le m�me ordre dans les 2 matrices)
        unsigned int trameTemporisation;

        //Donn�es g�n�rales sur les graphes
        unsigned int nb_etats;
        unsigned int nb_transitions;

        //Graphe = Etat actuel | On r�p�te ici les donn�es de l'�tat -> les voisins et les transitions
        vector <Etat*> vectEtats;
        vector <Transition*> vectTransitions;

        //Variables de sauvegarde des boucles et de la temporisation
        unsigned int boucle,temporisation;

        //Liste des enfants de ce graphe
        unsigned int Nombre_enfants;
        unsigned int Etat_enfants;
        vector <Graphe*> vectEnfants;
};

#endif // GRAPHE_H
