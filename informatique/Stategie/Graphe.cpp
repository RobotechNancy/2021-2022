#include "Graphe.h"

#include <iostream>
#include <fstream>

Graphe::Graphe()
{
}

Graphe::Graphe(newEtat &initEtat, newEtat &currEtat)
{
    etatInit = &initEtat;
    etatCourant = &currEtat;
    nom = currEtat.getNom();
    nb_sorties = currEtat.getNbsorties();
    vectEtats = currEtat.getvectEtats();
    vectTransitions = currEtat.getvectTransitions();
}

Graphe::~Graphe()
{
}

void Graphe::SetetatCourant(newEtat &val)
{
    etatCourant = &val;
    nom = val.getNom();
    nb_sorties = val.getNbsorties();
    vectEtats = val.getvectEtats();
    vectTransitions = val.getvectTransitions();
    cout << "Etat courant set à " << val.getId() << endl;
}

void Graphe::setvectEtats(vector<newEtat*> &x){ vectEtats=x; }
void Graphe::setvectTransitions(vector<Transition*> &x){ vectTransitions=x; }


string Graphe::genererEntetes(){
    return nom + "RUN();";
}

//Méthode qui permet à la fois d'écrire dans le terminal et de générer dans FonctionGraphe le code  de l'état courant
void Graphe::genererProgrammes(){
    ofstream MyFile("FonctionGraphe.cpp", std::ios::app);
    //Parties variables
    MyFile << "int Graphe" + nom + "(Graphe &adGraphe){" << endl
    << "\t" << "clock_t time_Graphe" + nom + ";" << endl
    << "\t" << "time_Graphe" + nom + " = clock();" << endl
    << "\t" << genererEntetes() << endl;


    cout << genererEntetes() << endl; //Générer seulement le run ?

    //Pour tous les voisins de cet état
    for (int i = 0; i < nb_sorties; i++){
        cout << (i==0?"if(":"else if(") << vectTransitions[i]->Getcondition() << "){" << endl;
        cout << "\t" << nom + "OUT();" << endl;
        cout << "\t" << nom << ".SetetatCourant(" << vectEtats[i]->getNom() << ");" << endl;
        cout << vectEtats[i]->genererEntetes() << endl;
        cout << "}" << endl;


        //Partie debug -> écriture dans un fichier logs
        MyFile << (i==0?"\tif(":"\telse if(") << vectTransitions[i]->Getcondition() << "){" << endl;
        MyFile << "\t\t" << "time_Graphe" + nom + " = clock() - time_Graphe" + nom + ";" << endl
        << "\t\t" << "float temps = (float)time_Graphe" + nom + "/CLOCKS_PER_SEC;" << endl
        << "\t\t" << "ofstream myLogs;" << endl
        << "\t\t" << "myLogs.open(\"debug.dot\", std::ios::app);" << endl
        << "\t\t" << "myLogs << \"Passage au graphe" + vectEtats[i]->getNom() + " en \";" << endl
        << "\t\t" << "myLogs << temps << \"sec.\" << endl;" << endl;

        //Partie execution de l'après transition
        MyFile << "\t\t" << nom + "OUT();" << endl;
        MyFile << vectEtats[i]->genererEntetes();
        //Trouver comment appeler une fonction avec un nom personnalisé
//        {vectEtats[i]->getNom();}();
        //Faire la génération du nouveau fichier cpp
        MyFile << "\t\t" << "adGraphe.SetetatCourant(" << vectEtats[i]->getNom() << ");" << endl;
        MyFile << "\t\t" << "adGraphe.genererProgrammes();" << endl;

        //Appel à la fonction pour rentrer dedans ?
        MyFile << "Graphe" + nom + "(" << vectEtats[i] << ");" << endl;
        MyFile << "\n\t}" << endl;
    }
    MyFile << "}";
    MyFile.close();
}

//Cette méthode permet d'écrire dans notre fichier FonctoinGraphe à la suite les entêtes des fonctions des états courants
void Graphe::genererFonctions(){
    ofstream MyFile("FonctionGraphe.cpp", std::ios::app);

    for (int i = 0; i < nb_sorties; i++){
        MyFile << "int Graphe" + vectEtats[i]->getNom() + "(Graphe &adGraphe);" << endl;
        cout << "int Graphe" + vectEtats[i]->getNom() + "(Graphe &adGraphe);" << endl;
    }
    MyFile.close();
}

void Graphe::Generer(){
    cout << "Generation" << endl;
    genererProgrammes();
    cout << "fini" << endl;
}
