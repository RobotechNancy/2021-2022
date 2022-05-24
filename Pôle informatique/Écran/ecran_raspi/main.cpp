#include "ecranlib.h"

using namespace std;

int main(int argc, char *argv[]){
    
    Ecran ecran;
    int status = ecran.openSerialConnection();
    if(status != 500)
        return 0;

    uint8_t data[] = {'2', '3', '1'};
    ecran.sendMsg(EC_MODE_COMPETITION, EC_CAT_SCORE, EC_SOUS_CAT_SCORE_TOTAL, data);

    ecran.closeSerialConnection();
    return 0;
}
