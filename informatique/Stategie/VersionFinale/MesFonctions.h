#ifndef MESFONCTIONS_H
#define MESFONCTIONS_H

#include <string>
using namespace std;

//Ceci est le fichier qui fera idéalement le lien entre les entêtes de fonctions appelés et le contenu réel de ces fonctions.
//Il faudra réélement trouver dans le cpp les fonctions qui feront les actions voulues dans les états

void headerFonctions(string name);
int headerIntFonctions(string name);
int headerVariables(string name);

void ModeAutoTestIN();
void ModeAutoTestRUN();
void ModeAutoTestOUT();

void InitialisationOdometrieIN();
void InitialisationOdometrieRUN();
void InitialisationOdometrieOUT();

void ModeArretUrgenceIN();
void ModeArretUrgenceRUN();
void ModeArretUrgenceOUT();

int headerFcts(string _f);
#endif // ARC_H
