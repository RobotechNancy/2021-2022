# definition de la trame du bus can

## Champ d'identification en version étendu (29 bit)
| msg urgent | desitnataire | emetteur | code fct |  id msg  | reponse ou question | id rep |
| --- | --- | --- | --- | --- | --- | --- |
|      0     |     0001     |   0010   | 00000101 | 00000001 |         0           |   001  |


- msg urgent : 0 pour un message urgent, 1 sinon
- destinataire : addresse du destinataire du message sur 4 bit (0 à 7)
- emetteur : addresse de l'emetteur du message sur 4 bit (0 à 7)
- code fonction : code fonction du message qui indique a quoi sert le message sur 8 bit (0 à 254)
- id du message : identique entre une demande et une reponse ce qui permet d'idnetifier la réponse, sur 8 bit (0 à 254)
- reponse ou question : un bit , 1 pour une reponse et 0 sinon
- id rep : si des donners doivent etre transmis sur plusieur trame

dans le bus can la prioriter des messages en cas de conflit est donner au message avec le champ d'identification le plus faible.
>ceci implique que les


# Mise en place du bus can
## Sur la raspberry

installer le packet can-utils : 
```bash
sudo apt install can-utils
```

ajouter :
```bash
dtoverlay=mcp2515-can0,oscillator=12000000,interrupt=25,spimaxfrequency=2000000` cette ligne dans le fichier `sudo nano /boot/config.txt
```
12000000 dépend du quartz utiliser (souvent 12000000 ou 8000000)


il faut lancer cette commande a chaque redémarage de la raspberry :
```bash
sudo ip link set can0 up type can bitrate 181818 loopback off
```
- le bitrate doit etre le meme sur toute les cartes du bus can
- il est possible de passer en **loopback on** ce qui fait que les messages ne sont **PLUS** envoyer dans le bus can mais sont renvoyer sur la carte.
- pour arreter le bus can (et pouvoir le redmarer avec d'autre parametre) : `sudo ip link set can0 down`


## Sur une STM32

Dans le .ioc :
- activer le bus **can1** ou **can**
- dans **Parameter Settings** modifier :
	- **Prescaler (for Time Quantum)**
	- **Time Quanta in Bit Segment 1**
	- **Time Quanta in Bit Segment 2**
de tel sorte d'obtenir le **Baud Rate** voulu (identique autre carte connecter au bus can. 181818 bit/s par example).
Sur une carte en confguration par default :

| PARAMETRE | VALEUR |
| --- | --- |
| **Prescaler (for Time Quantum)** | 16 |
| **Time Quanta in Bit Segment 1** | 8 Times | 
| **Time Quanta in Bit Segment 2** | 2 Times | 

- dans **NVIC Settings** tous cocher !!! (4 cases ou 1 en fonction de la carte)
- verifier que les pin sont bien ascossier comme cela :

| PIN  | DESCRIPTION |
| --- | --- |
| PA12 | CAN1_TX |
| PA11 | CAN1_RX | 
- Inclure les fichiers : can.c, can.h, defineCan.h
- dans le main :
	- include `#include "defineCan.h"` et `#include "can.h"`
	- dans user code 2  mettre `CAN_Config(hcan1, CAN_ADDR_BASE_ROULANTE_E);` avec hcan1 la variable de type `CAN_HandleTypeDef` instantier dans private variable, et **CAN_ADDR_BASE_ROULANTE_E** une valeur de l'enum **CAN_EMIT_ADDR**


# Utilisation du bus can
## Sur la raspberry
il existe un certain nombre de commande qui permete d'utilise le bus can :
- **candump can0** permet d'afficher tous les messages qui passe sur le bus can (meme ceux envoyer par la raspberry)
> si les messages envoyer n'apparaissent c'est qu'il n'y a aucune autre carte sur le bus pour accuser reception -> problème de branchement, !! resistance entre canL et canH !!
> si les messages envoyer apparaissent en double -> le loopback est activer, les messages ne sont pas envoyé aux autres cartes

- **cansend can0** permet d'envoyer un messages sur le bus can :
> example de syntaxe : `cansend can0 03132010#12`
> pour information sur l'utilisation de la commande : `cansend` ou `man cansend`

- la librairie possede un grand nombre d'autre commande [cf .doc du packet](https://github.com/linux-can/can-utils)

librairie orienté objet en c++ : voir le dossier **can_raspberry**

## Sur une STM32
les messages reçu déclanche une intéruption en appelant la fonction `void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)`
pour envoyer un message il faut utiliser `int send(CAN_ADDR addr, CAN_CODE_FCT codeFct , uint8_t data[], uint dataLen, bool isRep, uint repLenght, uint idMessage)`
