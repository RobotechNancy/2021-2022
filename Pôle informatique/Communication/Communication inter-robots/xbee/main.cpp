#include "xbeelib.h"

using namespace std;

int main(int argc, char *argv[]){
    
    XBee xbee;
    xbee.openSerialConnection();

    thread heartbeat(&XBee::sendHeartbeat, xbee);
    thread t(&XBee::waitForATrame, xbee);
    while(true){}

    xbee.closeSerialConnection();
    return XB_E_SUCCESS;
}
