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
*//*
    int error_configuration = xbee.checkATConfig();
    
    if(error_configuration == AT_ERROR_SUCCESS)
        cout << "Configuration AT réussie." << endl;
    else
        cout << "Configuration AT non réussie | [Code erreur : " << error_configuration << "]" << endl;
       
*/
    char msg[] = {'c', 'o', 'u', 'c', 'o', 'u'};

    xbee.sendTrame(ROBOT_02, TEST_ALIVE, msg);

    //string test = "21213191E63";

    int test[3] = {0x02, 0x09, 0x03};

    if(xbee.isCodeFctCorrect(TEST_ALIVE))
        cout << "coucou" << endl;

    //xbee.subTrame(test);

    //string trame_totale = "";

    //xbee.subTrame(trame_totale);

    //thread t(&XBee::waitForATrame, xbee);
    //while(true){}

    //t.join();

    //xbee.sendMsg("coucou");

    //xbee.closeSerialConnection();

    return EXIT_SUCCESS;
}
