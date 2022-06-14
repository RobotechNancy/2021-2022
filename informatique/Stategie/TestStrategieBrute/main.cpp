#include <iostream>
#include <math.h>
#include "convertionTrame.h"
#include "defineDeplacement.h"

#define PI 3.14159265

//Faire les includes pour le can
//#include ""
//#include "canClass.h"
//#include "logLib.h"
//#include "defineCan.h"

using namespace std;

typedef union{
    struct {
        uint16_t vitesse : 16;
        uint16_t distance : 16;
        uint8_t direction : 8;
    } fields;
    uint64_t unified;
    uint8_t raw_data[8];
} Trame_BR_dpt;

struct dpt{
    long _angle;
    int _distance;
};

struct zone{
    int _X;
    int _Y;
    int _orientation;
};

const zone GAUCHE_PIEDESTAL = {500, 500, 135};
const zone GAUCHE_PREM_RESISTANCE = {509, 300, 315};
const zone GAUCHE_ABRI_CHANTIER = {500, 500, 225};
const zone GAUCHE_CAMPEMENT = {200, 1300, 270};

const zone DROITE_PIEDESTAL = {2500, 500, 315};
const zone DROITE_PREM_RESISTANCE = {2491, 300, 315};
const zone DROITE_ABRI_CHANTIER = {2500, 500, 315};
const zone DROITE_CAMPEMENT = {2700, 1300, 270};


int cas_deplacement(zone dep,zone arr){
    if (arr._X > dep._X)
        if (arr._Y > dep._Y) //Droit haut
            return 1;
        else //Droit bas
            return 2;
    else
        if (arr._Y > dep._Y) //Gauche haut
            return 3;
        else //Gauche bas
            return 4;
}

dpt calcul_deplacement(zone dep, zone arr){
    long delta_x = abs(arr._X - dep._X);
    long delta_y = abs(arr._Y - dep._Y);
    long alpha = dep._orientation;
    long beta = atan(delta_x / delta_y) * 180 / PI;
    cout << "delta X " << delta_x << endl;
    cout << "delta Y " << delta_y << endl;
    cout << "alpha " << alpha << endl;
    cout << "beta " << beta << endl;
    cout << "beta " << atan(delta_x / delta_y) * 180 / PI << endl;
    //Valeurs que l'on cherche
    long angle;
    int distance = sqrt(pow(arr._X - dep._X, 2) + pow(arr._Y - dep._Y, 2));

    switch (cas_deplacement(dep, arr))
    {
    case 1: //Droit Haut
        cout << "test" << (-1)*alpha + 90 - beta << endl;
        angle = alpha - (90 - beta);
        break;
    case 2: //Droit Bas
        angle = alpha + (90 - beta);
        break;
    case 3: //Gauche Haut
        angle = 360 - abs(180 - alpha - beta);
        break;
    case 4: //Gauche Bas
        cout << "test2" << endl;
        angle = 360 - abs(180 - alpha + beta);
        break;
    default:
        break;
    }

    cout << angle << endl;
    cout << distance << endl;
    return {angle, distance};

}

void deplacement_ordres(dpt D, zone depart, zone destination){
    Trame_BR_dpt data;
//    Trame_Moteur_t trameMoteur;


    int ajustement = D._angle % 60;
    int direction = D._angle / 60 +1;

    if (ajustement > 30){
        ajustement = 60 - ajustement;
        ajustement *= (-1);
        direction++;
    }


    ///Faire une rotation d'angle ajustement
    data.fields.vitesse = 100;
    data.fields.direction = 7;
    data.fields.distance = ajustement;
    cout << data.fields.vitesse << " " << data.fields.direction << " " << data.fields.distance << endl;
//    g_can.send(CAN_ADDR_BASE_ROULANTE, AVANCE, data.raw_data, 0, false, 0);
    cout << "Rotation d'angle " << ajustement << endl;

    ///Faire un tout droit sur l'action direction sur distance
    data.fields.vitesse = 100;
    data.fields.direction = direction;
    data.fields.distance = D._distance;
//    g_can.send(CAN_ADDR_BASE_ROULANTE, DPT_BASE_ROULANTE, data.raw_data, 0, false, 0);
    cout << "Tout droit " << D._distance << " Sur l'action " << direction << endl;

    ///Faire une rotation sur = ajustement --- NE PAS FAIRE ?
    cout << destination._orientation << " " << D._angle << " " << ajustement << " " << D._angle + ajustement << endl;
    ajustement = destination._orientation - (depart._orientation + ajustement);
    data.fields.vitesse = 100;
    data.fields.direction = 7;
    data.fields.distance = ajustement;
//    g_can.send(CAN_ADDR_BASE_ROULANTE, DPT_BASE_ROULANTE, data.raw_data, 0, false, 0);
    cout << ajustement;
//    g_can.send(CAN_ADDR_BASE_ROULANTE, DPT_BASE_ROULANTE, data, 0, false, 0);

}

void deplacement(zone destination){
    zone depart = {1000, 1000, 0};

    if(destination._orientation == -1){
        destination._X = depart._X;
        destination._Y = depart._Y;
        destination._orientation = (depart._orientation + 180) % 360;
    }

    dpt D = calcul_deplacement(depart, destination);

    deplacement_ordres(D, depart, destination);
}


int main()
{
    deplacement(GAUCHE_PIEDESTAL);
    return 0;
}

