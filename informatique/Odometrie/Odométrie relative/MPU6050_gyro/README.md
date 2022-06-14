# Le code permet de réaliser :

- la communication en I2C avec le gyroscope
- l'initialisation du gyroscope
- la récupération de la vitesse angulaire, et sa conversion en angle de rotation sur l'axe Z (axe à la verticale du capteur lorque ce dernier est posé à l'horizontal)

> *Remarque :* Le code contenu dans le fichier GYRO_ACC_SAM est l'ensemble du projet réalisé sur l'**IDE STM32** | /!\ Le code **ne permet pas** l'utilisation de l'accéléromètre intégré au capteur


# Utilisation du code :

Pour utiliser le code, il vous faut :

- une carte STM32 disposant au minimum d'un bus I2C et d'une Pin d'interruption
  > le modèle utilisé pour le projet est la STM32L432KCU3 : pour utiliser la librairie sur une autre carte, copier uniquement les fichiers **Core/Inc/Gyro.h**, **Core/Inc/MPU6050.h**, **Core/Src/Gyro.c** ainsi que **Core/Src/MPU6050.c** et créer un nouveau projet STM
  >
- un gyrocope de type MCU6050
  > attention : pour câbler correctement le module, référez-vous à la section ci-après
  >
- avoir installé (sur windows ou linux) l'IDE fourni par STM32 appelé STM32CUBEIDE (disponible [ici](https://www.st.com/en/development-tools/stm32cubeide.html))
- des câbles de connexion et une plaque d'essai (ou un shield adapté)

Les fichiers **Core/Inc/Gyro.h**, **Core/Inc/MPU6050.h**, **Core/Src/Gyro.c** ainsi que **Core/Src/MPU6050.c** ont été écrit à la main, et servent à la configuration du capteur pour notre utilisation. Il se peut que vous soyez ammenés à les modifier, donc voici une courte description de chacun d'entre eux :
  
-> Dossier **Core/Inc** :

- le fichier "*MPU6050.h*" contient le code permettant de configurer les paramètres utilisés pour comminiquer avec le capteur et récupérer les valeurs, et permet également d'inclure la librairie associée à la famille de la carte en cours d'utilisation.

Au début du fichier, on trouve :

```
  #include "stm32l4xx_hal.h"
```

   Pour une autre famille de carte, il suffit de remplacer cette ligne, et de mettre le nom de la famille de la carte. Vous pouvez trouver cette information en regardant le nom du fichier de votre projet situé dans "**Core/Inc/stm32XXXX_hal_conf.h**". Recopier ce nom (sans le *_conf*) dans le fichier à la ligne citée précédemment.
   
  Le reste du fichier contient la configuration du module, avec notamment la posibilité de modifier sa sensibilité, sa vitesse d'horloge, sa fréquence et ses paramètres d'interruptions. Toutes les configurations possibles pour ces paramètres se trouvent *dans les énum des lignes 27 à 119*.  
  
  On trouve ensuite les paramètres en cours d'utilisation, sous forme de 3 structures, situées *entre les lignes 121 et 149*. 
  
  Enfin, on trouve les prototypes des fonctions qui permettent d'initialiser le capteur, et de récupérer la vitesse angulaire fournie par le capteur. Cette vitesse sera ensuite utilisée et traitée par le fichier **Gyro.c**.
  
- le fichier "*Gyro.h*" contient les prototypes des fonctions permettant de gérer la calibration du capteur ainsi que la conversion et le traitement des valeurs de vitesse angulaire afin de fournir la rotation en degrés.  


-> Dossier **Core/Src** :

- le fichier "*MPU6050.c*" contient les fonctions qui permettent d'initialiser le capteur, et de récupérer la vitesse angulaire fournie par le capteur.  

- le fichier "*Gyro.c*" contient les fonctions permettant de gérer la calibration du capteur ainsi que la conversion et le traitement des valeurs de vitesse angulaire afin de fournir la rotation en degrés. Ce fichier est une extension des fonctions contenues dans "*MPU6050.c*", d'où l'inclusion du fichier dans la classe *Gyro*.

Afin d'asssurer le fonctionnement de la librairie, il est nécessaire de modifier légèrement le fichier "*Core/Src/stm32l4xx_it.c*", afin d'ajouter dans la liste des include la libairie `#include "MPU6050.h"`. Il faut également appeler la fonction "*MPU6050_Interrupt_Routine()*" dans la fonction d'interruption système (située à la fin du fichier), pour obtenir un résultat comme ceci :

```c
/**
  * @brief This function handles EXTI line[9:5] interrupts.
  */
void EXTI9_5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */

  /* USER CODE END EXTI9_5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */
  MPU6050_Interrupt_Routine();
  /* USER CODE END EXTI9_5_IRQn 1 */
}
```
> *Remarque :* Les numéros des fonctions par défaut dépendant de la carte utilisée et de la configuration mise en place, et sont donc susceptibles de changer

# Câblage des modules et pinout configuration

Voici le câblage utilisé pour le projet, utilisant 1 capteur MPU6050 et une carte STM32L432KCU3 :

| MPU6050            | STM32L432KCU3                |
| ------------------ | ---------------------------- |
| GND (masse)        | GND (pin CN4-2 ou pin CN3-4) |
| SCL (serial clock) | PA9                          |
| SDA (serial data)  | PA10                         |
| VIN (alimentation) | +3.3V (pin CN4-14)           |

*Les pins situés sur la même ligne sont reliés entre eux*


> Pour configurer le bus I2C sur la carte STM32, il faut penser à activer les réglages de l'interruption du bus, dans le fichier **IOC du projet STM32**, dans le menu **Connectivity>I2C1>NVIC Settings** et cocher l'activation des interruptions **I2C1 event interrupt** et **I2C1 error interrupt** . Il faut ensuite se rendre dans le menu **System Core>GPIO>I2C** et de modifier les 2 lignes du bus I2C en réglant la valeur de **GPIO Pull-Up/Pull-down** sur **Pull-up** (il suffit de double cliquer sur chacune des deux lignes pour faire apparaitre le menu).
>
> Cela permet de ne pas mettre de résistances de Pull-up aux extrémités du bus I2C puisqu'elles sont en réalité internes dans la carte STM32.
> Le mode de l'I2C à utiliser est *I2C*
> Il faut ensuite utiliser une Pin non utilisée (PA6 sur l'IOC dans notre projet) et la régler sur "*GPIO_EXTI6*" afin de l'utiliser par la suite comme Pin d'interruption


Pinout configuration de la carte STM32 NUCLEO-L432KCU3 :

| Numéro de la PIN  | CN3 (partie gauche de la carte) | CN4 (partie droite de la carte) |
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

