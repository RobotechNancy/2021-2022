# Le code permet de réaliser :

- la communication inter-robots via XBee (envoi/réception de trames)
- le paramétrage des modules XBee en UART via le port GPIO de la RaspberryPi


# Installation du code (sous Linux x86-64) :

```bash
sudo git clone https://github.com/RobotechNancy/2021-2022.git
```

[**Username** : votre nom d'utilisateur GitHub] 

[**Password** : vous devez générer un personal access token dans `Github -> Settings -> Developer Settings -> Personal Access Token -> Generate new token`]

```bash
cd 2021-2022/Pôle\ informatique/Communication/Communication\ inter-robots/xbee/  

sudo g++ *.cpp -o output

./output

```

# Câblage des modules XBee avec la RaspberryPi

### Points de vigilence :

- L'alimentation de la RaspberryPi, pour une RaspberryPi3B+ ou modèle antérieur : 5.5V / 2A max. (utilisez une alimentation de la salle C244)
> une sous-alimentation entraine une dégradation notoire de la communication UART !
> un câble USB/Micro USB de mauvaise qualité entraine un fonctionnement erroné

- Le câblage du module XBee :
> ne pas utiliser les 4 pins situés à l'arrière du support XBee !

- La compatibilité entre les modules XBee :
> 2 modules XBee ne sont compatibles que s'ils sont du même type (**Exemples :** les modules XBee et XBee Pro ne sont pas compatibles entre eux)

- En cas d'impossibilité d'accès au module XBee et pour vérifier s'il n'est pas endommagé :
> utiliser le logiciel propriétaire [XCTU](https://hub.digi.com/dp/path=/support/asset/xctu-v-658-windows-x86x64/) et connecter le module XBee au port USB de votre ordinateur à l'aide de l'[explorer board XBee](https://s2.qwant.com/thumbr/0x380/e/2/01204fd8c357d0dce8acc47a0934b507685351a3559f81f2ed4661b6b831aa/RPI-326222.jpg?u=https%3A%2F%2Fwww.rpibolt.hu%2Fimg%2F15922%2FRPI-326222%2FRPI-326222.jpg)
> dans le logiciel XCTU, cliquez sur l'icône avec la loupe et non celui avec le + pour ajouter un module

- Si vous rencontrez un autre problème, la **meilleure** solution est d'utiliser un analyseur numérique de signal (ou un oscilloscope), notamment les oscilloscopes digitaux Rohde & Schartz de la salle C244


### Schéma de câblage :


# Documentation du code :

- voir le PDF **refman.pdf** dans le dossier `doc -> latex -> refman.pdf`
