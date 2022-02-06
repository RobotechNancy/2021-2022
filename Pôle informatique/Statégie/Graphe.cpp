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
    cout << "Etat courant set � " << val.getId() << endl;
}

void Graphe::setvectEtats(vector<newEtat*> &x){ vectEtats=x; }
void Graphe::setvectTransitions(vector<Transition*> &x){ vectTransitions=x; }


string Graphe::genererEntetes(){
    return nom + "RUN();";
}

//M�thode qui permet � la fois d'�crire dans le terminal et de g�n�rer dans FonctionGraphe le code  de l'�tat courant
void Graphe::genererProgrammes(){
    ofstream MyFile("FonctionGraphe.cpp", std::ios::app);
    //Parties variables
    MyFile << "int Graphe" + nom + "(Graphe &adGraphe){" << endl
    << "\t" << "clock_t time_Graphe" + nom + ";" << endl
    << "\t" << "time_Graphe" + nom + " = clock();" << endl
    << "\t" << genererEntetes() << endl;


    cout << genererEntetes() << endl; //G�n�rer seulement le run ?

    //Pour tous les voisins de cet �tat
    for (int i = 0; i < nb_sorties; i++){
        cout << (i==0?"if(":"else if(") << vectTransitions[i]->Getcondition() << "){" << endl;
        cout << "\t" << nom + "OUT();" << endl;
        cout << "\t" << nom << ".SetetatCourant(" << vectEtats[i]->getNom() << ");" << endl;
        cout << vectEtats[i]->genererEntetes() << endl;
        cout << "}" << endl;


        //Partie debug -> �criture dans un fichier logs
        MyFile << (i==0?"\tif(":"\telse if(") << vectTransitions[i]->Getcondition() << "){" << endl;
        MyFile << "\t\t" << "time_Graphe" + nom + " = clock() - time_Graphe" + nom + ";" << endl
        << "\t\t" << "float temps = (float)time_Graphe" + nom + "/CLOCKS_PER_SEC;" << endl
        << "\t\t" << "ofstream myLogs;" << endl
        << "\t\t" << "myLogs.open(\"debug.dot\", std::ios::app);" << endl
        << "\t\t" << "myLogs << \"Passage au graphe" + vectEtats[i]->getNom() + " en \";" << endl
        << "\t\t" << "myLogs << temps << \"sec.\" << endl;" << endl;

        //Partie execution de l'apr�s transition
        MyFile << "\t\t" << nom + "OUT();" << endl;
        MyFile << vectEtats[i]->genererEntetes();
        //Trouver comment appeler une fonction avec un nom personnalis�
//        {vectEtats[i]->getNom();}();
        //Faire la g�n�ration du nouveau fichier cpp
        MyFile << "\t\t" << "adGraphe.SetetatCourant(" << vectEtats[i]->getNom() << ");" << endl;
        MyFile << "\t\t" << "adGraphe.genererProgrammes();" << endl;

        //Appel � la fonction pour rentrer dedans ?
        MyFile << "Graphe" + nom + "(" << vectEtats[i] << ");" << endl;
        MyFile << "\n\t}" << endl;
    }
    MyFile << "}";
    MyFile.close();
}

//Cette m�thode permet d'�crire dans notre fichier FonctoinGraphe � la suite les ent�tes des fonctions des �tats courants
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
