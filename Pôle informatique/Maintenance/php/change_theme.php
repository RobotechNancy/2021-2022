<?php
/**
 * Page de traitement permettant de modifier la couleur du thème du site
 * 
 * **Date de création :** 14 janvier 2022
 * 
 * @author Manal FADIL & Ali LEHOUAL
 * @version 1.0
 * 
 * ```php
 * //Inclusion le fichier requis contenant la classe Web
 * require_once("web_class.php");
 *
 * //Test de la présence du paramètre retour dans l'URL 
 * if (isset($_GET["retour"])){
 *
 *      //Assainissement, sécurisation et récupération de la valeur brute du paramètre récupéré
 *      $retour = htmlspecialchars($_GET["retour"]);
 *
 *      //Découpage du chemin relatif de la page contenue dans la variable retour
 *      $retour = explode("/", $retour);
 *
 *       //Reconstruction du chemin relatif de la page contenue dans la variable retour
 *       $url_retour = "location: ../" . $retour[count($retour) - 1];
 *
 *       //Test de la présence du cookie du thème
 *       if(isset($_COOKIE["theme"])) {
 *
 *           //Récupération de la valeur du cookie de thème et stockage dans la variable $theme
 *           $theme = $_COOKIE["theme"];
 *
 *           //Test de la valeur contenue dans la variable $theme
 *           // + définition du nouveau thème à appliquer
 *           if($theme == "light") $new_theme = "dark";
 *           else $new_theme = "light";
 *
 *           //Mise à jour du cookie de thème contenant les nouveaux paramètres
 *           setcookie("theme", $new_theme, strtotime('+30 days'), "/", "localhost", false, false);
 *
 *       }
 *       //Si le cookie de thème n'existe pas 
 *       else {
 *           //Définition du nouveau thème comme étant le thème clair
 *           $new_theme = "light";
 *
 *           //Définition du cookie de thème contenant la valeur du thème clair
 *           setcookie("theme", $new_theme, strtotime('+30 days'), "/", "localhost", false, false);
 *       }
 *
 *       //Redirection vers la page d'appel du fichier
 *       header($url_retour);
 *
 *    //Si aucune valeur du paramètre retour n'est spécifiée
 *    }else{
 *       //Redirection vers la page d'acceuil du site
 *       header('location:index.php');
 *   }
 * 
 * ```
 * 
 * @link https://github.com/RobotechNancy/2021-2022
 */

/** Inclusion le fichier requis contenant la classe Web */
require_once("web_class.php");

/** Test de la présence du paramètre retour dans l'URL */
if (isset($_GET["retour"])){

    /** Assainissement, sécurisation et récupération de la valeur brute du paramètre récupéré */
    $retour = htmlspecialchars($_GET["retour"]);

    /** Découpage du chemin relatif de la page contenue dans la variable retour */
    $retour = explode("/", $retour);

    /** Reconstruction du chemin relatif de la page contenue dans la variable retour */
    $url_retour = "location: ../" . $retour[count($retour) - 1];

    /** Test de la présence du cookie du thème */
    if(isset($_COOKIE["theme"])) {

        /** Récupération de la valeur du cookie de thème et stockage dans la variable theme */
        $theme = $_COOKIE["theme"];

        /** Test de la valeur contenue dans la variable thème et définition du nouveau thème à appliquer */
        if($theme == "light") $new_theme = "dark";
        else $new_theme = "light";

        /** Mise à jour du cookie de thème contenant les nouveaux paramètres */
        setcookie("theme", $new_theme, strtotime('+30 days'), "/", "localhost", false, false);

    }
    /** Si le cookie de thème n'existe pas */ 
    else {
        /** Définition du nouveau thème comme étant le thème clair */
        $new_theme = "light";

        /** Définition du cookie de thème contenant la valeur du thème clair */
        setcookie("theme", $new_theme, strtotime('+30 days'), "/", "localhost", false, false);
    }

    /** Redirection vers la page d'appel du fichier */
    header($url_retour);

/** Si aucune valeur du paramètre retour n'est spécifiée */
}else{
    /** Redirection vers la page d'acceuil du site */
    header('location:index.php');
}