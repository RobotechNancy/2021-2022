#include <iostream>

#include <wiringPi.h> //Pour les inputs outputs


#include "canClass.h"
#include "logLib.h"
#include "defineCan.h"

using namespace std;

bool init_communication(); // Ouvre une communication � l'autre robot qui doit lui r�pondre apr�s
void stop_communication(); // Fonction qui stoppe la communication entre les robots
bool init_odometrie(); // V�rifie si les capteurs fonctionnent et place le robot dans la bonne position

bool mode_auto_test();
void mode_competition();
void mode_AU(); //Mettre un param�tre d'entr�e indiquant d'o� on vient dans le graphe

bool test_goupille();


typedef union{
    struct {
        uint16_t tof_2 : 10; ///Action
        uint16_t tof_34 : 10; ///Action
        uint16_t tof_5 : 10; ///Action
        uint16_t tof_67 : 10; ///Action
        uint16_t tof_8 : 10; ///Action
        uint16_t tof_91 : 10; ///Action
        } fields;
    uint64_t unified;
    uint8_t raw_data[8];
} Trame_Automate_TOFs;


Can g_can;
XBee g_xbee;

int gb_robot_fonctionnel;

int pin_goupille = 1;


struct dpt{
    float _vitesse;
    int _direction;
    int _distance;
};

struct zone{
    int _X;
    int _Y;
    int _orientation;
};
const zone GAUCHE_PIEDESTAL = {500, 500, -135};
const zone GAUCHE_PREM_RESISTANCE = {509, 300, -45};
const zone GAUCHE_ABRI_CHANTIER = {500, 500, -135};
const zone GAUCHE_CAMPEMENT = {500, 500, -135};

const zone DROITE_PIEDESTAL = {2500, 500, -45};
const zone DROITE_PREM_RESISTANCE = {2491, 300, -45};
const zone DROITE_ABRI_CHANTIER = {2500, 500, -45};
const zone DROITE_CAMPEMENT = {2700, 1300, -90};


int main()
{
/*/ Initialisation des pins /*/
    wiringPiSetup();
    pinMode(pin_goupille, input);

/*/ Initialisation du CAN /*/
    int err = g_can.init(CAN_ADDR_RASPBERRY);
	if(err <0){
		can.logC << "erreur dans l'init du bus can. err n�" << dec << err << "\t\t c.f. #define" << mendl;
		return err;
	}

/*/ Initialisation du robot (phase de tests et attente du lancement manuel /*/
//  On passe en mode AUTO TEST
//  SI true : alors le robot est op�rationnel
//  SI false : alors des d�fauts ont �t� d�tect�
    if(mode_auto_test()){
        // Si nous sommes dans les cas o� les 2 inits marchent alors on peut passer en mode Comp�tition (� la condition que l'on tire la goupille)
        if(init_communication() && init_odometrie()){
            while(test_goupille()){ // Faire une boucle qui wait le passage � faux de testgoupille
            }
            mode_competition();
            stop_communication();
        }
    }else{
        cout << "Mode d�faut" << endl;

    }

//while(!erreur || !fini) //Boucle dans le mode comp�tition qui va permettre de faire le programme jusqu'� erreur ou fin de programme
}

void lecture_TOFs(){
    Trame_Automate_TOFs trametofs;

    if (trametofs.fields.tof_2 < )

}

/*/ Description des fonctions /*/
bool mode_auto_test(){
    bool bValRet = true;

    /// Envoyer des trames aux cartes et attendre le retour :
    ///     Carte Odom�trie
    ///     Carte Automate
    ///     Carte Base Roulante


	uint8_t data[8] = {};
	err = g_can.send(CAN_ADDR_ODOMETRIE, AT_ODOMETRIE , data, 0, false, 0);
	can.start_listen();
    bvalRet = bValRet &&

	err = g_can.send(CAN_ADDR_AUTOMATE, AT_AUTOMATE, data, 0, false, 0);
    can.start_listen();
    bvalRet = bValRet &&

	err = g_can.send(CAN_ADDR_BASE_ROULANTE, AT_BASE_ROULANTE, data, 0, false, 0);
    can.start_listen();
    bvalRet = bValRet &&

    return bValRet;
}

void strat_NOrobot(){

}

//Mettre les actions de r�ajustement de la position par rapport au point d'arriv�e et � l'action � r�aliser
void strat_robotR1(){
    ///R�cup�rer le camp dans lequel nous jouons

//    deplacement_piedestal();
//    saisie_statuette();
//    demi_tour();
//    d�pot_replique();
//    resistances();
//    chantier();
//    campement();

    deplacement(GAUCHE_PIEDESTAL);
    send_can(CAN_ADDR_AUTOMATE, AT_SAISIE);
    deplacement({-1; -1; -1});
    send_can(CAN_ADDR_AUTOMATE, AT_DEPOT_REPLIQUE)
    deplacement(GAUCHE_PIEDESTAL);
    deplacement(GAUCHE_ABRI_CHANTIER);
    //Faire l'acation de pousser
    deplacement(GAUCHE_CAMPEMENT);

    deplacement(DROITE_PIEDESTAL);
    send_can(CAN_ADDR_AUTOMATE, AT_SAISIE);
    deplacement({-1; -1; -1});
    send_can(CAN_ADDR_AUTOMATE, AT_DEPOT_REPLIQUE)
    deplacement(DROITE_PIEDESTAL);
    deplacement(DROITE_ABRI_CHANTIER);
    //Faire l'acation de pousser
    deplacement(DROITE_CAMPEMENT);
}

void strat_robotR2(){
//    site_fouille();
//    recup_echantillons();
//    distributeur_d1();
//    recup_echantillon();
//    distributeur_d2();
//    recup_echantillons();
//    galerie();
//    depot_galerie();

    d�placement(SITE_FOUILLE);
    //Recup echantillons
    d�placement(DISTRIB_D1);
    //Recup echantillons
    d�placement(DISTRIB_D2);
    //Recup echantillons
    d�placement(GAUCHE_GALERIE);
    //deposer galerie
}



void mode_competition(){
    if (gb_robot_fonctionnel)
        strat_robotR1();
    else
        strat_NOrobot();
}

void deplacement(zone destination){
    ///Demander la position du robot au lidar
    send_can(CAN_ADDR_BASE_ROULANTE, GETPOSITION_LIDAR);
    listen;

    send_can(CAN_ADDR_BASE_ROULANTE, GETANGLE_ACCELEROMETRE);
    listen;

    zone depart = {};
    if(destination._orientation == -1){
        destination._X = depart._X;
        destination._Y = depart._Y;
        destination._orientation = (depart._orientation + 180) % 360
    }
    dpt D = calcul_deplacement(depart, destination);

    deplacement_ordres(D, depart, destination);

}

dpt calcul_deplacement(zone dep, zone arr){
    int delta_x = abs(arr._X - dep._X);
    int delta_y = abs(arr._Y - dep._Y);
    int alpha = dep._orientation;
    int beta = tan(delta_x / delta_y);

    //Valeurs que l'on cherche
    dpt valret;
    int angle;
    int distance = sqrt(pow(arr._X - dep._X, 2) + pow(arr._Y - dep._Y, 2));

    switch (cas_deplacement(dep, arr))
    {
    case 1: //Droit Haut
        angle = 360 - abs((-1)*alpha + beta);
        break;
    case 2: //Droit Bas
        angle = 360 - abs((-1)*alpha - beta);
        break;
    case 3: //Gauche Haut
        angle = (180 - alpha - beta);
        break;
    case 4: //Gauche Bas
        angle = (180 - alpha + 90 - beta);
        break;
    default:
        break;
    }


}

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


void send_can(uint addr, uint codeFct){
    uint8_t data[8] = {};
    g_can.send(addr, codeFct , data, 0, false, 0);
}

void position_plaquette(){

}

void mode_AU(string provenance){
    //Faire les actions attendues dans le mode arr�t d'urgence

    //Repartir dans l'�tape ? Sous forme de question ?

}



/// Se trouve �lectroniquement sur la carte donc pas besoin de passer par le can
bool test_goupille(){
    return digitalRead(pin_goupille);
}



bool init_communication(){
    int status = g_xbee.openSerialConnection();
    if(status != XB_SER_E_SUCCESS)
        return false;
    return true;
}

void stop_communication(){
    g_xbee.closeSerialConnection();
}

bool init_odometrie(){
	g_can.start_listen();

    uint8_t data[8] = {};
	err = g_can.send(CAN_ADDR_ODOMETRIE, INIT_ODOMETRIE , data, 0, false, 1);

    g_can.listen();

    //La fonction doit retourner l'�tat de l'odom�trie suite � l'initialisation
    return response;
}

