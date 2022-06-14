#include "ecranlib.h"

using namespace std;

int main(int argc, char *argv[]){
    
    Ecran ecran;
    int status = ecran.openSerialConnection();
    if(status != EC_SER_E_SUCCESS)
        return 0;

    uint8_t data[] = {'2', '3', '1'};

    Trame_t trame;
    
    trame.taille = (sizeof(data)/sizeof(data[0]))+5;
    trame.mode = EC_MODE_COMPETITION;
    trame.categorie = EC_CAT_SCORE;
    trame.sous_categorie = EC_SOUS_CAT_SCORE_TOTAL;
    trame.valeur = data;

    ecran.sendTrame(trame);

    ecran.closeSerialConnection();
    return 0;
}
