#include "xbeelib.h"

using namespace std;

int main(int argc, char *argv[]){
    
    XBee xbee;
/*
    int error_open_connection = xbee.openSerialConnection();

    if(error_open_connection != 1)
        cout << ": Erreur de connexion à " << SERIAL_PORT << " [Code erreur : " << error_open_connection << "]." << endl;
    else
        cout << ": Connexion ouverte avec succès sur le port \"" << SERIAL_PORT << "\".\n" << endl;
*/
    /*
    int error_configuration = xbee.checkATConfig();
    
    if(error_configuration == AT_ERROR_SUCCESS)
        cout << "Configuration AT réussie." << endl;
    else
        cout << "Configuration AT non réussie | [Code erreur : " << error_configuration << "]" << endl;
    
    char msg[1];
    msg[0] = 0x02;
    
    */

    char msg[2];
    msg[0]= 'c';
    msg[1] = 'o';

    char* trame = xbee.sendTrame(ROBOT_02, TEST_ALIVE, msg);
    xbee.processTrame(trame);

    //xbee.sendMsg("coucou");

    return EXIT_SUCCESS;
}
