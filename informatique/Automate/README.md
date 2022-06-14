# Ce code permet de :

- Commander un actionneur type servomoteur à angle
- Commander un actionneur type TOR (electroaimant,pompe,etc)
- Commander un actionneur type moteur PAP 

### L'entièreté des codes sont réalisés sur STM32CUBEIDE Version: 1.9.0    Build: 12015_20220302_0855 (UTC) en langage C/C++


### Pour commander un actionneur type servomoteur à angle : 

1. Créer le projet STM sur LA BONNE VERSION de la carte !!
2. Commencer par configurer les pins de la carte sur le .ioc (pin d'envoie de signal et autres si besoin)
> Un servomoteur à angle à besoin en plus du signal d'être (en général) relié à la masse et au 5V (vérifier sur datasheet si la STM suffit pour l'alimenter ou si il faut rajouter une alimentation externe)
3. Regler ensuite les timers pour bien les calibrer (adapter les valeurs des timers en fonction de la valeur de la clock de l'année)
4. Une fois ces 3 actions effectuer, pour faire fonctionner le servomoteur il faut :
    1. Activer la pin configurée précédemment
    2. Régler la valeur du CCR associé au timer en fonctione de l'angle que l'on veut (faire des tests pour trouver la bonne valeur)
    3. Désactiver la pin une fois l'action du servomoteur effectuée
> Attention une fois une commande d'angle lancée, ne pas bloquer et/ou pousser le servomoteur dans le sens inverse cela risque de le casser/dérégler
> Si il y à besoin d'une fonction d'attente, regarder la fonction faite  à la main dans le projet STM et ne pas utiliser la fonction HAL_DELAY de STM, pendant son utilisation, plus rien d'autre ne se passe.


### Pour commander un actionneur type TOR : 

1. Créer le projet STM sur LA BONNE VERSION de la carte !!
2. Commencer par configurer les pins de la carte sur le .ioc (pin d'envoie de signal et autres si besoin)
> Pour un actionneur TOR, il faut configurer dans GPIO output le GPIO mode en Push Pull sans pull-up ni pull-down (voir avec le pole electronique si la carte alimente l'actionneur en push/pull ou en open-drain)
3. Une fois cela configuré, il suffit d'écrire sur la PIN 1 ou 0 (SET ou RESET) pour activer/désactiver l'actionneur (si en open drain, les commandes sont inversées)
> Pour un actionneur TOR, il faudra très souvent brancher l'actionneur sur une alimentation  externe car la STM ne suffira probablement pas


### Pour commander un actionneur type PAP :





Si besoin d'aide supplémentaire sur les  actionneurs, me contacter par mail rey.thibault@orange.fr ou par discord Thibolt#3886 (voir le discord robotech si besoin).