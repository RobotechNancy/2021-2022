#include "xbeelib.h"

using namespace std;

int main(int argc, char *argv[]){
    
    XBee xbee;
    int status = xbee.openSerialConnection();
    if(status != XB_SER_E_SUCCESS)
        return 0;

    thread heartbeat(&XBee::sendHeartbeat, xbee);
    thread t(&XBee::waitForATrame, xbee);
    while(true){}

    xbee.closeSerialConnection();
    return XB_E_SUCCESS;
}
