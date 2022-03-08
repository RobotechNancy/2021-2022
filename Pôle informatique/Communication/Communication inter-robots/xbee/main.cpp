#include "xbeelib.h"

using namespace std;

int main(int argc, char *argv[]){
    
    XBee xbee;

    int error_open_connection = xbee.openSerialConnection();

    if(error_open_connection != 1)
        cout << ": Erreur de connexion à " << XB_SERIAL_PORT_PRIMARY << " [Code erreur : " << error_open_connection << "]." << endl;
    else
        cout << ": Connexion ouverte avec succès sur le port \"" << XB_SERIAL_PORT_PRIMARY << "\".\n" << endl;

    int error_configuration = xbee.checkATConfig();
    
    if(error_configuration == XB_AT_E_SUCCESS)
       cout << "Configuration AT réussie." << endl;
    else
       cout << "Configuration AT non réussie | [Code erreur : " << error_configuration << "]" << endl;
           
    thread heartbeat(&XBee::sendHeartbeat, xbee);
    thread t(&XBee::waitForATrame, xbee);
    while(true){}

    xbee.closeSerialConnection();
    
    cout << ": Connexion fermée avec succès sur le port \"" << XB_SERIAL_PORT_PRIMARY << "\".\n" << endl;
    return EXIT_SUCCESS;
}
