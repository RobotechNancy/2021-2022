# Le code permet de réaliser :

- la communication en I2C avec les capteurs TOF
- l'initialisation des capteurs un à un
- la lecture et la conversion des valeurs afin de récupérer des valeurs de distances mesurées en mm

> *Remarque :* Le code contenu dans le fichier TOF_SAM est l'ensemble du projet réalisé sur l'**IDE STM32**


# Utilisation du code :

Pour utiliser le code, il vous faut :

- une carte STM32 disposant au minimum d'un bus I2C et d'un GPIO
  > le modèle utilisé pour le projet est la STM32L432KCU3 : pour utiliser la librairie sur une autre carte, copier uniquement le dossier **Drivers/VL53L0X** et le contenu ***utilisateur*** du fichier **Core/Src/main.c** et créer un nouveau projet STM
  >
- un ou plusieurs capteurs TOF de type VL53L0X (ou VL53LXX)
  > attention : pour câbler correctement les modules, référez-vous à la section ci-après
  >
- avoir installé (sur windows ou linux) l'IDE fourni par STM32 appelé STM32CUBEIDE (disponible [ici](https://www.st.com/en/development-tools/stm32cubeide.html))
- des câbles de connexion et une plaque d'essai

Ce code est basé sur la librairie STM32 qui a été adaptée de manière à être universelle pour toutes les cartes compatibles. La librairie modifiée se trouve dans le dossier **Drivers/VL53L0X.**

Les dossiers **Src** et **Inc** contiennent uniquement des fichiers générés par STM, il ne faut surtout pas les modifier.

Les fichiers commencant par **"TOF_"** et situés dans les dossiers **Implementation** et **Platform** ont été écrit à la main, et servent à l'implémentation du code pour notre utilisation. Il se peut que vous soyez ammenés à les modifier, donc voici une courte description de chacun d'entre eux :

-> Dossier **Implementation** :

- le fichier "*TOF_STM_Reference.h*" contient uniquement le code permettant d'inclure la librairie associée à la famille de la carte en cours d'utilisation.

  ```
  #include "stm32l4xx_hal.h"
  ```

    Pour une autre famille de carte, il suffit de remplacer cette ligne, et de mettre le nom de la famille de la carte. Vous 			pouvez trouver cette information en regardant le nom du fichier de votre projet situé dans "**Core/Inc/stm32XXXX_hal_conf.h**". Recopier ce nom (sans le *_conf*) dans le fichier cité précédemment.


- le fichier "*TOF_STM_Units.h*" contient les informations par défaut des capteurs (adresse I2C, ID de base, mode de relevé de mesure, ...) ainsi que la liste des noms de capteurs TOF utilisés sous forme d'une structure de type *enum*.

  ```
  typedef enum {
  	TOF_UNIT_0 = 0,
  	TOF_UNIT_1 = 1,

  	TOF_UNIT_COUNT // Let this enum value !!!! Mandatory for the driver operations
  } TOF_Units_t;
  ```

    Dans notre exemple, il y deux capteurs TOF listés qui s'appellent respectivement*TOF_UNIT_0* et *TOF_UNIT_1* et qui possèdent les numéros 0 et 1. Pour ajouter un modèle, il suffit de le mettre dans cette liste, et dans le fichier "*TOF_STM_Units.c*" associé.


- le fichier "*TOF_STM_Units.c*" contient les informations détaillées de la liste des capteurs TOF du fichier précédent.
  ```
  VL53L0X_Dev_t TOF_Devices[] = {
  	{
  		.Id = TOF_UNIT_0,
  		.I2cHandle = &hi2c1,
  		.XSHUT_Port = TOF0_XSHUT_GPIO_Port,
  		.XSHUT_Pin = TOF0_XSHUT_Pin
  	},
  	{
  		.Id = TOF_UNIT_1,
  		.I2cHandle = &hi2c1,
  		.XSHUT_Port = TOF1_XSHUT_GPIO_Port,
  		.XSHUT_Pin = TOF1_XSHUT_Pin
  	}
  };
  ```

    Pour chaque module listé dans le fichier .h, on retrouve son ID, l'ID de l'objet I2C (du bus I2C) auquel il est connecté, le nom du port GPIO auquel est connecté la sortie XSHUT du capteur, ainsi que le nom de la Pin qui lui est associée. Pour ajouter un module, il suffit de respecter le format en incrémentant le numéro que le dernier TOF listé possède dans chacune des variables (le même bus I2C étant utilisé pour tous les capteurs, cette variable ne change pas).

> *Remarque importante :* Les capteurs TOF VL53L0X ne possèdent que de la mémoire volatile, et ne retiennent donc pas la nouvelle adresse de bus I2C qui leur est associée. Par défaut, tous les capteurs ont la même adresse, à chaque démarrage, il faut donc tous les éteindre, puis les allumer un à un et leur attribuer une adresse différente entre eux pour pouvoir les distinguer et commiquer avec un à un. C'est tout l'intérêt de la sortie XSHUT du capteur qui signifie XSHUTDOWN, et qui permet d'éteindre les capteurs un à un via le port GPIO de la STM lors de l'initialisation.

    Pour que l'ensemble du code fonctionne, il faut donc que chaque capteur TOF soit relié à une Pin GPIO différente sur la carte STM32. Pour configurer les Pins GPIO sur la carte, il faut repérer sur la carte des Pins non utilisées (*voir la section du câblage pour plus d'informations*), puis se rendre dans le fichier **.ioc** du projet STM32, clic droit sur la Pin choisie, puis sélectionner "GPIO Output" dans la liste déroulante des options. La Pin passe alors à l'état activé et se colore en vert. Il faut ensuite éditer son nom, en effectuant un clic gauche sur la Pin, puis sélectionner "Enter User Label" et indiquer le nom de la Pin sous la forme "TOFX_XSHUT", où le premier X désigne le numéro choisi pour le capteur dans la liste du fichier précédent.


-> Dossier **Platform** :

- le fichier "*TOF_Errors.h*" contient la liste de l'ensemble des codes erreurs qui peuvent être utilisés dans toute la librairie. Leurs noms sont assez explicites, et si on effectue un *Ctrl+clic droit* sur chacune des variables, on peut trouver un commentaire descriptif de l'erreur. Toutefois, si vous souhaitez des descriptions plus précises, vous pouvez consulter le site suivant : [https://documentation.help/VL53L0X-API/](https://documentation.help/VL53L0X-API/)
- le fichier "*TOF_Types.h*" contient les listes des options utilisables pour modifier les paramètres des capteurs, comme le mode de relevé de valeurs, ou encore l'état du capteur.
- les fichiers "*TOF.h*" et "*TOF.c*" contiennent les deux fonctions principales qui sont utilisables par l'utilisateur de la librairie, une première qui permet d'initialiser les capteurs TOF, en paramétrant les registres, et les adresses I2C de chaque capteur, et une seconde qui permet d'effectuer un relevé de la distance fournie par un capteur en mm. D'autres fonctions sont également présentes et sont des fonctions utilitaires internes qui servent aux deux fonctions principales pour mieux découper le programme.

  > Par défaut, les relevés de mesure s'effectuent en mode "LONG_RANGE"
  >


L'ensemble de cette librairie est utilisée dans le fichier **Core/Src/main.c** qui permet d'appeler les fonctions de la librairie, d'initialiser les capteurs, de lire les valeurs envoyées par les capteurs et de transmettre ces valeurs via le bus UART à l'utilisateur afin qu'il puisse vérifier qu'elles sont cohérentes (une valeur de statut est également envoyée à chaque mesure, afin d'indiquer si cette dernière a correctement été effectuée).


# Câblage des modules et pinout configuration

Voici le câblage utilisé pour le projet, utilisant 2 capteurs TOF et une carte STM32L432KCU3 :

| VL53L0X n°1        | VL53L0X n°2  | STM32L432KCU3                |
| ------------------ | ------------ | ---------------------------- |
| XSHUT              | /            | PA6                          |
| /                  | XSHUT        | PA5                          |
| GND (masse)        | GND          | GND (pin CN4-2 ou pin CN3-4) |
| SCL (serial clock) | SCL          | PA9                          |
| SDA (serial data)  | SDA          | PA10                         |
| VIN (alimentation) | VIN          | +3.3V (pin CN4-14)           |

*Les pins situés sur la même ligne sont reliés entre eux*


> Pour configurer le bus I2C sur la carte STM32, il faut penser à changer les réglages de la vitesse, dans le fichier **IOC du projet STM32**, dans le menu **Connectivity>I2C1>Parameter Settings** et régler la valeur de **I2C Speed Frequency (KHz)** à 10 (au lieu de 100 par défaut). Il faut ensuite se rendre dans le menu **System Core>GPIO>I2C** et de modifier les 2 lignes du bus I2C en réglant la valeur de **GPIO Pull-Up/Pull-down** sur **Pull-up** (il suffit de double cliquer sur chacune des deux lignes pour faire apparaitre le menu).
>
> Cela permet de ne pas mettre de résistances de Pull-up aux extrémités du bus I2C puisqu'elles sont en réalité internes dans la carte STM32.


Pinout configuration de la carte STM32 NUCLEO-L432KCU3 :

| Numéro de la PIN | CN3 (partie gauche de la carte) | CN4 (partie droite de la carte) |
| ----------------- | ------------------------------- | ------------------------------- |
| 1                 | PA9 - D1 (SCL)                  | VIN                             |
| 2                 | PA10 - D0 (SDA)                 | GND (masse)                     |
| 3                 | NRST                            | NRST                            |
| 4                 | GND (masse)                     | +5V                             |
| 5                 | PA12 - D2                       | PA2 - A7                        |
| 6                 | PB0 - D3                        | PA7 - A6                        |
| 7                 | PB7 - D4                        | PA6 - A5                        |
| 8                 | PB6 - D5                        | PA5- A4                         |
| 9                 | PB1 - D6                        | PA4 - A3                        |
| 10                | PC14 - D7                       | PA3 - A2                        |
| 11                | PC15 - D8                       | PA1 - A1                        |
| 12                | PA8 - D9                        | PA0 - A0                        |
| 13                | PA11 - D10                      | AREF                            |
| 14                | PB5 - D11                       | +3.3V                           |
| 15                | PB4 - D12                       | PB3 - D13                       |
