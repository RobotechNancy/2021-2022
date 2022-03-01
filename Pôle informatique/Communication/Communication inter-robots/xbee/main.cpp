#include "xbeelib.h"

using namespace std;

int main(int argc, char *argv[]){
    
    XBee xbee;

    /*int error_open_connection = xbee.openSerialConnection();

    if(error_open_connection != 1)
        cout << ": Erreur de connexion à " << XB_SERIAL_PORT << " [Code erreur : " << error_open_connection << "]." << endl;
    else
        cout << ": Connexion ouverte avec succès sur le port \"" << XB_SERIAL_PORT << "\".\n" << endl;
*/
    //int error_configuration = xbee.checkATConfig();
    
    //if(error_configuration == XB_AT_E_SUCCESS)
     //   cout << "Configuration AT réussie." << endl;
    //else
      //  cout << "Configuration AT non réussie | [Code erreur : " << error_configuration << "]" << endl;
       
    //vector<int> test = {0x02, 0x12, 0X13, 0X1, 0XA, 0x1E, 0x63, 0x6F, 0x75, 0x63, 0x6F, 0x75, 0x9B, 0x56, 0x03};

    //int result = xbee.subTrame(test);

    //if(result != XB_SUB_TRAME_E_SUCCESS){
    //    cout << dec << "code erreur : " << result << endl; 
    //}
    //xbee.subTrame(test);

    //string trame_totale = "";

    //xbee.subTrame(trame_totale);
    
    //thread heartbeat(&XBee::sendHeartbeat, xbee);
    //thread t(&XBee::waitForATrame, xbee);
    //while(true){}

    //xbee.closeSerialConnection();
    
    cout << ": Connexion fermée avec succès sur le port \"" << XB_SERIAL_PORT << "\".\n" << endl;
    return EXIT_SUCCESS;
}
