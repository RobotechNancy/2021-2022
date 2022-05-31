# Tutoriel pour implémenter un point d'accès sans fil sur une RaspberryPi

##### Utilité du point d'accès :

Le point d'accès d'une RaspberryPi permet de pouvoir créer un réseau sans fil directement sur la carte sans avoir besoin qu'elle se connecte à un partage de connexion distant pour y accéder.

Cette fonction est particulièrement utile lorsqu'on a besoin de se connecter à plusieurs à une RaspberryPi ou lorsqu'on se trouve dans un endroit sans possibilité d'effectuer un point d'accès autre.

```
/!\ Attention : Ce tutoriel ne permet pas d'effectuer le routage de la connexion internet via la RaspberryPi. 
Le point d'accès sans fil ainsi créé ne permettra pas d'accéder à internet ! 
Une solution est de mettre en place un partage de connexion via USB en branchant son téléphone à la RaspberryPi via USB et en sélectionnant l'option "Modem USB" dans les paramètres de connexion.
```


##### Mise en place du point d'accès :

On vérifie tout d'abord que le système est bien à jour, et on installe les paquets nécessaires :
