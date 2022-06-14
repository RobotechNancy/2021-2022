#include <iostream>
#include "newEtat.h"
#include "Arc.h"
#include "Graphe.h"
#include "Transition.h"
#include "CycleVie.h"

#include <regex>
#include <fstream>

//Main dans lequel notre but est de lire un fichier txt par esemple qui contient dans une certaine forme la structure d'un grafcet et on veut créer les instances
//de ce grafcet par les class que nous avons (graphe, arc, etat, etc.)

// Nous avons un autre main mis de côté les dernières séances qui permettaient depuis une instance de cycle de vie avec des graphes dedans de générer le code à éxécuter.
int main()
{
    newEtat e;
    ifstream monFlux("Graphes.txt");

    if (monFlux) {
        string ligne;
        while(getline(monFlux,ligne)) {
            //On souhaite gérer la structure depuis un fichier extérieur au programme
            //C'est pourquoi on utilise un txt qu'on vient analyser ligne par ligne avec une regex
            //Nous allons ensuite gérer
            regex rgx("(.*) (.*)");
            smatch matches;

            //Lecture du patterne de la regex
            if(regex_search(ligne, matches, rgx)) {
                if(matches[1].str() == "newEtat"){
                   cout << "Etat " << matches[2].str() << endl;
//                   e = newEtat e(matches[2].str());
                }else{
                   cout << "transition " << matches[2].str() << endl;
                }
            } else {
                cout << "Match not found\n";
            }
        }
    }
    else {
        cout << "ERREUR : Impossible d'ouvrir le fichier en lecture." << endl;
    }

    newEtat g1e1(1,"ModeTest");
    return 0;


//    //Création graphe 1
//    newEtat g1e1(1,"ModeAutoTest");
//    newEtat g1e2(2,"InitialisationOdometrie");
//    newEtat g1e3(3,"ModeArretUrgence");
//
//    Transition trans1(1, "robotOpérationnel");
//    Transition trans2(2, "BoutonAR");
//    Transition trans3(3, "AnnulationAR");
//
//    g1e1.addArc(g1e2, trans1);
////    g1e1.addArc(g1e3, trans2);
//    g1e2.addArc(g1e3, trans2);
////    g1e3.addArc(g1e2, trans3);
//    Graphe G1 (g1e1, g1e1);
//
//    //Création graphe 2
//    newEtat g2e1(4, "ModeCompetition");
//    newEtat g2e2(5, "ModeMaintenance");
//    newEtat g2e3(6, "ModeSpectacle");
//
//    Transition trans4(4, "DétectionDefaillance");
//    Transition trans5(5, "QuitterModeMaintenance");
//    Transition trans6(6, "CompetitionTerminée");
//
//    g2e1.addArc(g2e3, trans6);
//    g2e1.addArc(g2e2, trans4);
//    g2e2.addArc(g2e1, trans5);
//    Graphe G2 (g2e1, g2e1);
//
//    CycleVie cv;
//    cv.addGraphe(G1);
//    cv.addGraphe(G2);
//    cv.addActif(G1);
//    cv.addActif(G2);
//
//    //-------------------------------
//
////    G1.Generer();
//
////    G1.SetetatCourant(g1e2);
////    G1.Generer();
//
//
//    cv.GenererFonctions();
//    cv.Generer();
////    cout << "sheeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeesh" << endl;
////    G1.SetetatCourant(g1e2);
////    G2.SetetatCourant(g2e2);
////    cv.Generer();
}
