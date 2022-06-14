/*!
 * [General]
 * @file aireRectangle : permet de calculer et d'afficher l'aire d'un rectangle en fonction de sa longueur et de sa largeur
 * @author Samuel-Charles DITTE-DESTREE, <samueldittedestree@gmail.com>
 * @version 1.05R
 * @date 22/10/2021
 * @deprecated false
 * 
 * [Usage] 
 * @param double largeur : largeur du rectangle supérieure ou égale à 0
 * @param double longueur : longueur du rectangle supérieure ou égale à 0
 * @return int ERR : code erreur correspondant à l'état de sortie de la fonction - @see [Error list]
 * 
 * [Examples] 
 * @example Calcul de l'aire d'un rectangle de 3.7 mm de largeur et 12.2 mm de longueur 
 * ERR = aireRectangle(3.7, 12.2) 
 * // return ERR = 0 
 * // affiche "Rectangle de largeur 3.7 mm et de longueur 12.2 mm. Aire = 45.14 mm²"
 * 
 * @example Calcul de l'aire d'un rectangle de 75.9 mm de largeur et 23.6 mm de longueur 
 * ERR = aireRectangle(75.9, 23.6) 
 * // return ERR = -3
 * // n'affiche rien
 * 
 * [Output report] 
 * @exception ERR = 0 : les valeurs sont correctes, aucun problème lors de l'exécution
 * @exception ERR = -1 : la valeur de la largeur est éronnée car inf. à 0
 * @exception ERR = -2 : la valeur de la longueur est éronnée car inf. à 0
 * @exception ERR = -3 : les valeurs sont correctes, aucun problème lors de l'exécution
 *
 */

// C'est seulement après avoir écrit et configuré l'en-tête précédente qu'on peut commencer à écrire le code brut
int aireRectangle(double largeur, double longueur){
    int ERR;
    if (largeur < 0){ return ERR = -1; }
    else if (longueur < 0){ return ERR = -2; }
    else if (largeur > longueur){ return ERR = -3; }
    else {
        double aire = largeur * longueur;
        printf("Rectangle de largeur %f mm et de longueur %f mm. Aire = %f mm²\n", largeur, longueur, aire);
        return ERR = 0;
    }
}    

/*! Mode d'emploi du remplissage de l'en-tête ci-dessus
 * 
 * [General]
 * @file Nom du ficher ou de la fonction contenue dans le fichier : utilité principale de la fonction
 * @author Nom de l'auteur du programme contenu dans le fichier (si plusieurs auteurs, un auteur par ligne)
 * @version Version du programme contenu dans le fichier sous la forme XX.XXR
 * -> les deux premiers X indiquent la version actuelle dite 'majeure' du programme (une incrémentation de cette valeur indique un changement important au sein du programme)
 * -> les deux autres X indiquent la version actuelle dite 'mineure' du programme (une incrémentation de cette valeur indique un changement mineur au sein du programme)
 * -> la lettre R qui suit signifie 'RELEASE' et indique que la version actuelle du programme est susceptible d'évoluer fréquemment et/ou que la version n'est pas stable
 *
 * @date Date de dernière modification du programme au format JJ/MM/AAAA 
 * @deprecated Indique si le programme est déprécié (dans ce cas indiquer par quoi il a été remplacé) ou s'il est toujours utilisable et à jour
 *  
 * [Usage]
 * @param Renseigne la variable d'entrée de la fonction, son nom, son type, sa plage d'existance et sa signification (une ligne par variable d'entrée)
 * @return Indique la variable retournée par la fonction en sortie, son nom, son type et sa signification  
 * 
 * [Examples]
 * @example Fournit un exemple d'utilisation réaliste de la fonction en précisant la sortie et l'affichage attendu à la fin de l'exécution 
 * -> indiquez deux ou trois exemples par fonction en organisant les exemples à la suite les uns des autres
 * 
 * [Output report]
 * @exception Indique la signification de chacun des états que peut prendre la variable d'erreur/de sortie
 * 
 */