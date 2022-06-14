# Utilisation de la librairie can
```c++
Can can;  // crée un objet de la classe Can

int err = can.init(CAN_ADDR_RASPBERRY_E); // initialise le bus can avec l'adresse CAN_ADDR_RASPBERRY_E
if(err <0){
  can.logC << "erreur dans l'init du bus can. err n°" << dec << err << "\t\t c.f. #define" << mendl;
  return err;
}

can.start_listen(); // demarre un thread qui écoute les messages sur le bus can

uint8_t data[8] = {0x01,0x02,0xFF,0x34,0x45};
err = can.send(CAN_ADDR_BASE_ROULANTE, DEPLACEMENT_COURROIE, data, 5, true, 5); // envoie data à la base roulante 

while(!can.is_message(1)){ // attend un message d'id 1
}

CanResponse_t msg = can.get_message(1); // récupère le message d'id 1
```

### pour envoyer un message dans le bus can : 
```c++
can.send(CAN_ADDR addr, CAN_CODE_FCT codeFct , uint8_t data[], uint data_len, bool isRep, uint repLenght, uint idmessage);
```

### pour recevoir un message dans le bus can :
```c++
can.is_message(1)
```
cette fonction renvoie vrai si il y a un message d'id **1** en attente venant du bus can

```c++
CanResponse_t msg = can.get_message(1);
```
cette fonction permet de recuperer le message du buffer et le sortir du buffer 
>`is_message(1)` renvera toujours vrai tant que le message est dans le buffer et donc tant que `get_message(1)` n'est pas appeler





pour crée un bus can virtuel (vcan0) :
  - sudo modprobe vcan
  - sudo ip link add dev vcan0 type vcan
  - sudo ip link set up vcan0
