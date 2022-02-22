#include "xbeelib.h"

using namespace std;

int main(int argc, char *argv[]){
    
    XBee xbee;

    int error_open_connection = xbee.openSerialConnection();

    if(error_open_connection != 1)
        cout << ": Erreur de connexion à " << SERIAL_PORT << " [Code erreur : " << error_open_connection << "]." << endl;
    else
        cout << ": Connexion ouverte avec succès sur le port \"" << SERIAL_PORT << "\".\n" << endl;
/*
    int error_configuration = xbee.checkATConfig();
    
    if(error_configuration == AT_ERROR_SUCCESS)
        cout << "Configuration AT réussie." << endl;
    else
        cout << "Configuration AT non réussie | [Code erreur : " << error_configuration << "]" << endl;
       
*/
    char msg[6] = {'c', 'o', 'u', 'c', 'o', 'u'};

    char* message = xbee.sendTrame(ROBOT_02, TEST_ALIVE, msg);
    char* message_2 = xbee.sendTrame(ROBOT_01, TEST_ALIVE, msg);
    
    string trame = xbee.charToString(message);
    string trame_2 = xbee.charToString(message_2);

    string trame_totale = "iefuahaiuhfiuh04" + trame + trame_2;

    //xbee.subTrame(trame_totale);

    thread t(&XBee::waitForATrame, xbee);
    while(true){}

    //t.join();

    xbee.sendMsg("coucou");

    xbee.closeSerialConnection();

    return EXIT_SUCCESS;
}
