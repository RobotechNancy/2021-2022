<?php
/**
 * Page définissant la classe *Web* et les fonctions utilisées dans le site
 * 
 * Cette page est destinée à diviser le code de l'IHM en fonctions et méthodes de manière à utiliser une approche en POO pour l'ensemble de l'outil.
 * 
 * **Date de création :** 14 janvier 2022
 * 
 * @author Manal FADIL & Ali LEHOUAL
 * @version 1.0
 * @link https://github.com/RobotechNancy/2021-2022
 */


/**
 * Classe définissant les attributs, accésseurs et méthodes d'un objet de type Web
 * 
 * L'appel et l'utilisation des différents composants de la classe est effectué dans la page *index.php*
 * 
 * @example $web = new Web("Tableau de bord");
 */
class Web{
    /** L'en-tête de la page web */
    private string $head;

    /** Le corps de la page web */
    private string $body;

    /** Le titre de la page web */
    private string $title;

    /**
     * Constructeur de la classe Web
     * 
     * Permet d'instancier des objets de type Web
     * @param string $title  Titre de la page web
     * @return void 
     */
    public function __construct(string $title = ""){
        $this->title = $title;
        $this->head = "";
        $this->body = "";
    }

    /**
     * Accesseur de l'attribut head
     * @param none 
     * @return string $head  L'en-tête de la page web
     */
    public function getHead() : string{
        return $this->head;
    }

    /**
     * Accesseur de l'attribut body
     * @param none
     * @return string $body  Le corps du site
     */
    public function getBody() : string{
        return $this->body;
    }

    /**
     * Accesseur de l'attribut title
     * @param none
     * @return string $title  Le titre du site web 
     */
    public function getTitle() : string{
        return $this->title;
    }

    /**
     * Setter de l'attribut head 
     * 
     * Concatene l'attribut head
     * @param string $head  Suite de l'entête de la page web actuelle 
     * @return void
     */
    public function addToHead(string $head) : void{
        $this->head .= $head;
    }

    /**
     * Setter de l'attribut body 
     * 
     * Concatene l'attribut body
     * @param string $body  Suite du corps de la page web actuel
     * @return void
     * @example $web->addToBody("coucou");
     */
    public function addToBody(string $body) : void{
        $this->body .= $body;
    }

    /**
     * Ajout du lien dans le head vers la page de style 
     * 
     * Transforme le lien en balise html et concatene le tout 
     * @param string $link  Lien vers la page de style CSS
     * @return void
     */
    public function addCSSlink(string $link) : void{
        $this->addToHead(<<<HTML
        <link rel="stylesheet" type="text/css" href="{$link}"><br>
        HTML);
    }
    /**
     * Ajout du lien dans le head vers la page de java script 
     * 
     * Transforme le lien en balise html et concatene le tout 
     * @param string $link  Lien vers la page de script JS
     * @return void
     */
    public function addJSlink(string $link) : void{
        $this->addToBody(<<<HTML
        <script src="{$link}"></script>
        HTML);
    }
    /**
     * Ajout une icone du site  
     * 
     * Transforme le nom d'image en balise html et concatène le tout 
     * @param string $link  Lien du chemin relatif vers l'image d'illustration de la page web
     * @return void
     */
    public function addIcon(string $link) : void{
        $this->addToHead(<<<HTML
        <link rel="icon" type="image/png" href="{$link}">
        HTML);
    }
    /**
     * Ajout du pied de page au site suivant le thème du site + concaténation avec le body   
     * @param string $color  La couleur de thème du site
     * @return void
     * @example $web->addFooter($theme);
     */
    public function addFooter(string $color = "dark") : void{
        $this->addToBody(<<<HTML
        <footer class="footer is-{$color}" style="bottom: -60px !important; position: fixed !important; width: 100% !important;">
        <div class="content has-text-centered" style="margin-top: -30px !important;">
            <nav class="breadcrumb has-arrow-separator" aria-label="breadcrumbs" style="margin-left: 28% !important;">
            <ul>
                <li class="mt-1">
                    <button class="button is-info">
                        <span class="icon is-small">
                            <i class="fas fa-power-off" aria-hidden="true"></i>
                        </span>
                        <span>Diagnostic</span>
                    </button>
                </li>
                <li>
                    <button class="button is-info">
                        Alimentation
                    </button>
                </li>
                <li>
                    <button class="button is-info is-light">
                        Cartes et processeur
                    </button>
                </li>
                <li class="is-active">
                    <button class="button is-info is-light">
                        Base roulante
                    </button>
                </li>
                <li class="is-active">
                    <button class="button is-info is-light">
                        <span class="icon is-small">
                            <i class="fas fa-flag-checkered"></i>
                        </span>
                        <span>Fin</span>
                    </button>
                </li>
            </ul>
            </nav>
        </div>
        </footer>
        HTML);
    }
    /**
     * Ajout d'un bloc de type tuile    
     * @param string $color  La couleur du fond de la tuile
     * @param string $title  Le titre de la tuile
     * @param int $margin  Le nombre, en pixels, du décalage du titre de la tuile vers la droite de l'écran
     * @return string $html  Le contenu de la page web
     * @example $tile_1 = $web->addTile("primary", "Lancer diagnostic"); 
     */
    public function addTile(string $color, string $title, int $margin = 40) : string{
        $html = <<<HTML
        <div class="tile is-parent">
            <article class="tile is-child box message is-{$color}">
                <div class="message-header">
                    <p style="margin-left: {$margin}px;">$title</p>
                </div>
                <div class="message-body">
                    <button class="button is-medium is-white is-rounded is-fullwidth">
                        <span class="icon is-small">
                            <i class="far fa-circle" aria-hidden="true"></i>
                        </span>
                    </button>
                </div>
            </article>
        </div>
        HTML;

        return $html;
    }
    /**
     * Ajout de la barre de navigation    
     * @param string $color  Couleur de thème de la page web
     * @return void
     * @example $web->addNavBar($theme); 
     */
    public function addNavBar(string $color = "dark") : void{
        if($color == "dark"){
            $logo = "white";
            $icon = "moon";
        }else if($color == "light"){
            $logo = "dark";
            $icon = "sun";
        }
        $this->addToBody(<<<HTML
        <nav class="navbar is-{$color} has-shadow" role="navigation" aria-label="main navigation">
        <div class="navbar-brand">
            <div class="pt-2 pl-2 pb-2">
                <span><img src="img/logo_court_couleur.jpg" width="60px"></span>
                <span style="position: absolute !important; margin-top: 5px; margin-left: 8px;"><strong>Robotech Nancy</strong><br>Equipe 2021-2022</span>
            </div>
        </div>
        <div class="navbar-start has-text-centered" style="margin-left: 30%; margin-top: 20px;">
        <span>
            <div class="control">
                <div class="tags has-addons">
                    <span class="tag is-primary is-large is-rounded">Temps restant :</span>
                    <span class="tag is-info is-large is-rounded"><strong>1</strong></span>
                    <span class="tag is-warning is-medium is-rounded">minute</span>
                    <span class="tag is-info is-large is-rounded"><strong>00</strong></span>
                    <span class="tag is-danger is-medium is-rounded">secondes</span>
                </div>
            </div>
            </span>
        </div>
        <div class="navbar-end">
                <a class="navbar-item">
                    <span class="icon-text">
                        <span class="icon">
                            <i class="fas fa-wifi"></i>
                        </span>
                        <span class="tag is-success">Bonne</span>
                    </span>
                </a>
                <a class="navbar-item">
                    <span class="icon-text">
                        <span class="icon">
                            <i class="fas fa-battery-quarter"></i>
                        </span>
                        <span class="tag is-danger">25%</span>
                    </span>
                </a>
                <a class="navbar-item" href="php/change_theme.php?retour={$_SERVER['REQUEST_URI']}">
                    <span class="icon-text">
                        <span class="icon">
                            <i class="fas fa-{$icon}"></i>
                        </span>
                        <span class="tag is-{$logo}">Theme</span>
                    </span>
                </a>
            </div>
        </div>
        </nav>
        HTML);
    }
    /**
     * Ajout de toutes les balises html de la page     
     * @param string $color  Couleur de thème de la page web
     * @return string $html  Le contenu de la page web
     * @example echo $web->toHTML($theme);
     */
    public function toHTML(string $color = "dark") : string{
        if($color == "dark"){
            $logo = "blanc";
            $add_on = "<link rel=\"stylesheet\" type=\"text/css\" href=\"https://unpkg.com/bulma-prefers-dark\" />";
        }else if($color == "light"){
            $logo = "couleur";
            $add_on  = "";
        }
        $html = <<<HTML
        <!DOCTYPE html>
        <html lang="fr">
            <head>
                {$this->getHead()}
                <title>{$this->getTitle()}</title>
                <meta charset="utf-8">
                <meta http-equiv="X-UA-Compatible" content="IE=edge">
                <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
                <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.3/css/bulma.min.css">
                {$add_on}
                <link rel="icon" type="image/jpg" href="img/logo_court_couleur.jpg">
                <script src="https://kit.fontawesome.com/602d3eba54.js"></script>
                <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
            </head>
            <body class="has-navbar-fixed-bottom">
                {$this->getBody()}
            </body>
        </html>
        HTML;

        return $html;
    }
}