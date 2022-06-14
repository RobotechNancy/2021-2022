/////////////////////////////////////////////////////// Utilisation code CAPTEUR OPTIQUE PMW3091 ///////////////////////////////////////////////////////

## DRIVERS : PMW3091.c et PMW3091.h

- Le .c contient les fonctions utilent pour faire fonctionner le capteur correctement et dans le .h on annonce chaque fonction
- Les deux doivent être implémentés dans le projet sous forme de Source Folder
- Il faut ajouter en include les drivers pour que ça marche

## STM32L432K : PMW3091.ioc

- Pour faire fonctionner le reste du code : le port SPI sur la carte STM 32 doit être activé manuellement sur l'IDE de STM 32 en FULL Duplex Master
- ACtiver sur la STM32 les ports SPI1_SCK et en plus un port GPIO_OUTPUT : qu'il faut renommer SPI1_CS
- Au niveau de la connectivité SPI de la carte STM il faut aller dans parameter Settings => 

  - Frame Format : Motorola
  - Data Size : 8 Bits
  - First Bit : MSB First
  - Prescaler (for Baud Rate) : 256
  - Baud Rate : 125 Kbits/s
  - Clock Polarity : Low
  - Clock Phase : 1 Edge
  - CRC Calculation : Disabled
  - NSSP Mode : Enabled 
  - NSS Signal Type : Software
 
 ## Main : main.c 
 
 - Il faut ajouter le PMW3091.h en include
 - Il faut d'abord initialiser le capteur dans le code grâce à la fonction qui le permet (PMW3901_Status_t PMW3901_Init(PMW3901_Descriptor_t *_Descriptor))
 - Si l'initialisation fonctionne les leds du capteur devrait s'allumer
 - Ensuite il faut ajouter la fonction permettant de lire la variation de position du capteur (PMW3901_Status_t PMW3901_Read_Variation(int16_t *var_x, int16_t *var_y))

 ## Résumé 
 
 Le code présent déjà sur le Git permet actuellement de faire fonctionner le capteur optqiue c'est à dire qu'en installant l'application putty et en lancant en parallèle le code, on récupère la variation en x et en y du déplacement du capteur en mm grâce à deux DEFINE qui convertissent les données reçues en mm.
 
 De plus, il permet ensuite de calculer la position relative du capteur : c'est à dire que si le robot bouge il va garder en position initiale l'endroit où il était au démarrage du code et ensuite on le déplacant, on observera sur putty en mm les longueurs qu'il aura parcouru. En le remettant à la position initiale il va redonner posX = 0 et posY = 0 avec un taux d'erreur de lordre du mm.
 
 Le code fonctionne pour les 2 robots que ce soit pour le capteur du petit robot tout comme celui du grand robot.
