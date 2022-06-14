/*
 programme de test de la fonction
*/

#include <iostream>
#include <string>
#include "convertionTrameGR.h"

using namespace std ;

int main()
{

    Trame_Moteur_t trameMoteur;
    Trame_BR_dpt trameDpt;
    //vitesse min = 16mm mais essayer de mettre un peu peu de préférence
    //vitesse max = mm
    uint16_t a;
    uint16_t b;
    uint16_t c;
    cout << "trameDpt->fields.vitesse = ";
    cin >> a;
    cout << "trameDpt->fields.distance = ";
    cin >> b;
    cout << "trameDpt->fields.direction = ";
    cin >> c;
    trameDpt.fields.vitesse = a;
    trameDpt.fields.distance = b;
    trameDpt.fields.direction = c;
    convertir(&trameDpt, &trameMoteur);
    cout << "trameDpt->fields.vitesse = " << (uint16_t)trameDpt.fields.vitesse << endl;    
    cout << "trameDpt->fields.distance = " << (uint16_t)trameDpt.fields.distance << endl;
    cout << "trameDpt->fields.direction = " << (uint16_t)trameDpt.fields.direction << endl;
    cout << "trameMoteur->fields.nb_steps = " << trameMoteur.fields.nb_steps << endl;
    cout << "trameMoteur->fields.div0 = " << (uint16_t)trameMoteur.fields.div0 << endl;    
    cout << "trameMoteur->fields.div1 = " << (uint16_t)trameMoteur.fields.div1 << endl;
    cout << "trameMoteur->fields.div2 = " << (uint16_t)trameMoteur.fields.div2 << endl;
    cout << "trameMoteur->fields.dir0 = " << trameMoteur.fields.dir0 << endl;
    cout << "trameMoteur->fields.dir1 = " << trameMoteur.fields.dir1 << endl;
    cout << "trameMoteur->fields.dir2 = " << trameMoteur.fields.dir2 << endl;

    return 0;
}