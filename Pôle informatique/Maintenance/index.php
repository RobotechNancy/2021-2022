<?php
/**
 * Page principale du site utilisant les fonctions de la classe *Web*
 * 
 * Cette page est la page d'accueil et d'affichage du site. Elle comprend l'ensemble des éléments visibles par l'utilisateur.
 * 
 * **Date de création :** 14 janvier 2022
 * 
 * @author Manal FADIL & Ali LEHOUAL
 * @version 1.0
 * 
 * @link https://github.com/RobotechNancy/2021-2022
 * @link web_class.php
 */

/** 
 * Inclusion du fichier web_class 
 */
require_once("php/web_class.php");  

/** 
 * @var object $web : Création d'un nouvel objet de type Web + définition du titre du site 
 */
$web = new Web("Tableau de bord");  

/** 
 * @var object $web : Ajout de la barre de navigation 
 */
$web->addNavBar($theme); 

/** 
 * @var object $web : Ajout du pied du page 
 */
$web->addFooter($theme); 

/** 
 * @var string $tile_1 : Ajout de la case diagnostic 
 */
$tile_1 = $web->addTile("primary", "Lancer diagnostic"); 

/** 
 * @var string $tile_2 : Ajout de la case mise sous tension 
 */
$tile_2 = $web->addTile("success", "Mise sous tension");

/** 
 * @var string $tile_3 : Ajout de la case mise hors tension 
 */
$tile_3 = $web->addTile("link", "Mise hors tension");

/** 
 * @var string $tile_4 : Ajout de la case fin de maintenance 
 */
$tile_4 = $web->addTile("warning", "Fin de maintenance", 35);

/** 
 * @var string $tile_5 : Ajout de la case arrêt d'urgence 
 */
$tile_5 = $web->addTile("danger", "Arrêt d'urgence", 45);

/** @var object $web : Ajout des élements du corps de la page */
$web->addToBody(<<<HTML
<div class="tile is-ancestor">
  {$tile_1}
  {$tile_2}
  {$tile_3}
  {$tile_4}
  {$tile_5}
</div>

<div class="tile is-ancestor">
  <div class="tile is-parent is-8">
    <article class="tile is-child box">
     <span class="tag is-info is-medium">Logs d'erreurs</span><hr>
      <div class="content">
          
      </div>
    </article>
  </div>
  <div class="tile is-parent">
    <article class="tile is-child box">
    <span class="tag is-info is-medium mb-2">Autotests</span>
      <div class="content">
        <span>Alimentation</span>
        <span class="is-pulled-right">...%</span>
        <progress class="progress is-small" value="15" max="100">15%</progress>
        <span>Micro processeur</span>
        <span class="is-pulled-right">...%</span>
        <progress class="progress is-small" value="15" max="100">15%</progress>
        <span>RAM</span>
        <span class="is-pulled-right">...%</span>
        <progress class="progress is-small" value="15" max="100">15%</progress>
        <span>Odométrie</span>
        <span class="is-pulled-right">...%</span>
        <progress class="progress is-small" value="15" max="100">15%</progress>
        <span>Base roulante</span>
        <span class="is-pulled-right">...%</span>
        <progress class="progress is-small" value="15" max="100">15%</progress>
      </div>
    </article>
  </div>
</div>
HTML);

/** 
 * Affichage du rendu de la page en HTML 
 */
echo $web->toHTML($theme);