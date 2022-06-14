#include <iostream>
#include "Etat.h"
#include "Arc.h"
#include "Graphe.h"
#include "Transition.h"
#include "CycleVie.h"
#include <chrono>


#include <regex>
#include <fstream>
#include <vector>
#include <string>

#include "rapidxml/rapidxml_utils.hpp"
using namespace rapidxml;

//Faire des variables globales pour contrôler l'idCourant, l'idSource, la temporisation, le bouclage
//Changer ses variables tout au long de l'exécution
Graphe ParsingXML(string);

int main(int argc, char *argv[])
{
    //Parsing du fichier argv[1]
    Graphe g = ParsingXML(argv[1]);

    while(1){
        auto start = chrono::steady_clock::now();

        cout << "------------" << g.GetetatCourant()->getId() << "------------" << endl;

        if (g.Executer()){//Cas où on reste dans le même état - Incrémenter le compteur de boucles
            auto end = chrono::steady_clock::now();
            cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
            //MàJ les données de temporisation et de boucle
            g.Settemporisation(g.Gettemporisation()==-1?0:g.Gettemporisation() + chrono::duration_cast<chrono::milliseconds>(end - start).count());
            g.Setboucle(g.Getboucle() + 1);
        }else{//Cas où on transitionne
            auto end = chrono::steady_clock::now();
            cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

            g.AjouterLogs(g.Gettemporisation() + chrono::duration_cast<chrono::milliseconds>(end - start).count());

            g.Settemporisation(0);
            g.Setboucle(0);
        }
    }

    return 0;
}

Graphe ParsingXML(string name){
    string arguments;
    vector<Etat*> vectEtat;
    vector<Transition*> vectTransi;
    Transition* transi;

    int idEtat, idVoisin, idCourant, idDebut, idTransi, typeTransi;
    Graphe g;

    xml_document<> doc;
    cout << name << endl;
	// Read the xml file into a vector
	ifstream theFile (name);
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);

    xml_node<> *root_node = doc.first_node("graphe");

    //iterate for etats
  	for (xml_node<> * etat_node = root_node->first_node("etat"); etat_node; etat_node = etat_node->next_sibling())
	{
	    cout << "Etat " << etat_node->first_attribute("id")->value() << " " << etat_node->first_attribute("nom")->value() << endl;
	    idEtat = stoi((string)etat_node->first_attribute("id")->value());
        vectEtat.push_back(new Etat(idEtat, etat_node->first_attribute("nom")->value()));
	}
    for (xml_node<> * etat_node = root_node->first_node("etat"); etat_node; etat_node = etat_node->next_sibling())
	{
        // Interate over transis
	    for(xml_node<> * transi_node = etat_node->first_node("transition"); transi_node; transi_node = transi_node->next_sibling())
	    {
	    	cout << "Transi " << transi_node->first_attribute("condition")->value() << endl;
            idEtat = stoi((string)etat_node->first_attribute("id")->value());
            idVoisin = stoi((string)transi_node->first_attribute("id")->value());
            typeTransi = stoi((string)transi_node->first_attribute("type")->value());
            idTransi = stoi((string)transi_node->value());

            transi = new Transition(idTransi, typeTransi, transi_node->first_attribute("condition")->value());
            (*vectEtat[idEtat]).addArc(*vectEtat[idVoisin], *transi);
	    }

	}
	idCourant = stoi((string)root_node->first_attribute("idC")->value());
	idDebut = stoi((string)root_node->first_attribute("idS")->value());
    theFile.close();


    g = Graphe((*vectEtat[idCourant]), (*vectEtat[idDebut]));

    return g;
}
