#include "CycleVie.h"
#include <iostream>

#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <bitset>
#include <fstream>

CycleVie::CycleVie()
{
    nb_graphesActifs=0;
    motBinaireActifs = 0b0;
}

CycleVie::~CycleVie()
{
    //dtor
}

int CycleVie::GetmotBinaireActifs()
{
    return motBinaireActifs;
}

void CycleVie::addGraphe(Graphe &adGraphe)
{
    vectGraphes.insert(vectGraphes.begin(), &adGraphe);
}

void CycleVie::addActif(Graphe &adGraphe)
{
    //Variable de travail - indice de parcours
    int ind=-1;
    for(unsigned int i = 0; i < vectGraphes.size(); i++)
    {
        if (vectGraphes[i] == &adGraphe)
            ind = i;
    }
    //Si le graphe est dans la "liste" vectGraphe (qui contient les graphes déjà ajoutés) alors on rend son statut actif en ajoutant 2^ind au mot binaire
    //RAPPEL : on gère le statut d'activité avec un mot binaire = 1 actif 0 non-actif | En partant de la droite le rang du digit correspond au statut du graphe de même rang dasn le vector
    if (ind != -1){
        motBinaireActifs += pow(2, ind);
    }else{
        //Sinon on ajoute dans le vecteur(=liste) le graphe ET on ajoute 1 au mot binaire (car le statut sur le mot binaire e lit de droite à gauche
        //Un graphe dernièrement ajouté au vecteur (ayant pour rang 3 par exemple dans celui-ci aura son statu lisible en entrée du motbinaire = rang 0)
        vectGraphes.insert(vectGraphes.begin(), &adGraphe);
        motBinaireActifs += 1;
    }
    nb_graphesActifs++;

}

void CycleVie::delActif(Graphe &adGraphe)
{
    //Variable de travail de parcours
    int ind=-1;
    //On vérifie si la requête est légitime (est ce que le graphe est bien stocké dans notre liste)
    for(unsigned int i = 0; i < vectGraphes.size(); i++)
    {
        if (vectGraphes[i] == &adGraphe)
            ind = i;
    }
    //Si c'est le cas (indice trouvé) alors on soustrait 2^ind au mot binaire
    if (ind != -1){
        motBinaireActifs -= pow(2, ind);
        nb_graphesActifs--;
    }
}

//On écrit dans le fichier FonctionGraphe qui contient le code temporaire de sortie du moteur de graphe
//Cette fonction permet de refresh ce fichier en réécrivant en effaçant dessus
//On écrit dedans les includes des différentes librairies nécessaires
void CycleVie::resetFonctionGraphe(){
    ofstream MyFile("FonctionGraphe.cpp");
    //Parties includes
    MyFile << "#include \"MesFonctions.h\"" << endl
    << "#include <string>" << endl
    << "#include <ctime>" << endl
    << "#include <iostream>" << endl
    << "#include <fstream>" << endl
    << "#include \"Graphe.h\"" << endl
    << "using namespace std;\n" << endl;
    MyFile.close();
}

//Génération des codes des états courants DES graphes ACTIFS (pas bien géré pour le moment)
void CycleVie::Generer()
{
    //On met le motbinaire dans une chaine de caractères pour le parcourir bit à bit
    string strMotBinaire;
    stringstream ss;
    ss << std::bitset<32>(motBinaireActifs);
    ss >> strMotBinaire;

    cout << strMotBinaire << endl;
    //Pour tout les voisins
    for (int i = 0; i < vectGraphes.size() ; i++){
        if (strMotBinaire[strMotBinaire.size()-1-i] == '1'){
            cout << i << endl;
            //Appel de la fonction générer de Graphe
            vectGraphes[i]->Generer();
            cout << "----------------------------" << endl;
        }
    }
}

void CycleVie::GenererFonctions()
{
    string strMotBinaire;
    stringstream ss;
    ss << std::bitset<32>(motBinaireActifs);
    ss >> strMotBinaire;

    resetFonctionGraphe();

    for (int i = 0; i < vectGraphes.size() ; i++){
        if (strMotBinaire[strMotBinaire.size()-1-i] == '1'){
            vectGraphes[i]->genererFonctions();
        }
    }
}









