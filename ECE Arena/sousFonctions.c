#include "biblioJeu.h"

/*-----------------------------------------------------------------------------------------------------*/
///Petits sous-programmes pour éviter les répétitions

//Fonction pour quitter Allegro (pour éviter de réécrire à chaque fois)
void initialisationAllegro()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0)!=0)
    {
        allegro_message("Probl%cme graphique", 138);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}
/*----------------------------------------------------------------------------*/
//Fonction pour quitter Allegro
void quitterAllegro()
{
    allegro_exit();
    exit(EXIT_FAILURE);
}
/*----------------------------------------------------------------------------*/
//Affichage du bouton 'exit' en haut à gauche
void affichageBoutonExit()
{  //Dessin du bouton 'exit'
      rectfill(screen,0,0,40,20,makecol(255,255,0));
      textprintf_ex(screen,font,4,6,makecol(0,0,0),makecol(255,0,0),"EXIT");
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
///Fonction pour quitter le jeu à tout moment
void exitJeu()
{
    int clic=0;
    clear_bitmap(screen);

    //Création double buffer fond noir
    /******************************************************************************/
    BITMAP* bitmapFondNoir;
    bitmapFondNoir = create_bitmap(SCREEN_W,SCREEN_H);

    clear_bitmap(bitmapFondNoir);

    /******************************************************************************/

    //Affichage boutons quitter 'oui' ou 'non'
    /******************************************************************************/
    BITMAP* boutonOui;
    boutonOui = load_bitmap("BoutonOui.bmp",NULL);

    if (!boutonOui)
    {
        allegro_message("Nous n'avons pas pu charger \"BoutonOui.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* boutonNon;
    boutonNon = load_bitmap("BoutonNon.bmp",NULL);

    if (!boutonNon)
    {
        allegro_message("Nous n'avons pas pu charger \"BoutonNon.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/

    //Affichage sur la bitmap choisie
      textout_centre_ex(bitmapFondNoir, font, "Es-tu sur de vouloir quitter notre superbe jeu ?", 510, 200, makecol(255, 255, 255), -1);
      draw_sprite(bitmapFondNoir, boutonOui, 415, 300);
      // draw_sprite(bitmapFondNoir, boutonNon, 600, 300);

    //On copie le double buffer dans screen
      blit(bitmapFondNoir,screen, 0, 0, 0, 0, 1024, 768);

    while (clic == 0){

        if (mouse_b & 1)   //Si clic gauche souris cliqué
            {
                //Si bouton 'Oui' cliqué -> quitte le jeu
                if(mouse_x>=400 && mouse_x<=639 && mouse_y>=305 && mouse_y<=515)
                {
                    //allegro_message("Dommage! A la prochaine");
                    quitterAllegro();
                }

            ///Annuler 'quitter la partie' ne marche pas
            /*
                //Si bouton 'Non' cliqué -> partie reprend
                if(mouse_x>=600 && mouse_x<=859 && mouse_y>=305 && mouse_y<=515)
                {
                    sleep(3);
                    clear_bitmap(screen);
                }
            }
            */
            }
    }
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
///Initialisation des joueurs au début de la partie
void initialiserJoueurStats(t_joueur *tabJoueurs, int nbJoueurs)   //Paramètres: tableau de joueurs, nb de joueurs, "i" pour le numéro du joueur
{
    int i=0, j=0;

    for(i=0; i<nbJoueurs; i++)  //Boucle pour initialiser tous les joueurs
    {
        tabJoueurs[i].PV = 500;   //Initialisation des stats
        tabJoueurs[i].PM = 3;
        tabJoueurs[i].PA = 20;
        tabJoueurs[i].ligne = rand()% (12-1 +1) + 1;   //Placement aléatoire entre 1 et 12
        tabJoueurs[i].colonne = rand()% (16-1 +1) + 1;   //Placement aléatoire entre 1 et 16

        for(j=0;j<4;j++)
            tabJoueurs[i-1].choixClasseVerif[j] = 0;  //0 si le joueur a choisi une classe, 1 si classe choisie
    }
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
///Attribution de la classe en fonction des joueurs
void attributionClasseJoueur(t_joueur* tabJoueurs, int* nbJoueurs, int i)
{
    //Déclarations d'un double buffer pour stats de chaque joueur
    /******************************************************************************/
    BITMAP* fondCadreJoueur1;
    fondCadreJoueur1 = load_bitmap("fondCadreJoueur.bmp",NULL);

    if (!fondCadreJoueur1)
    {
        allegro_message("Nous n'avons pas pu charger \"fondCadreJoueur.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* fondCadreJoueur2;
    fondCadreJoueur2 = load_bitmap("fondCadreJoueur.bmp",NULL);

    if (!fondCadreJoueur2)
    {
        allegro_message("Nous n'avons pas pu charger \"fondCadreJoueur.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* fondCadreJoueur3;
    fondCadreJoueur3 = load_bitmap("fondCadreJoueur.bmp",NULL);

    if (!fondCadreJoueur3)
    {
        allegro_message("Nous n'avons pas pu charger \"fondCadreJoueur.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* fondCadreJoueur4;
    fondCadreJoueur4 = load_bitmap("fondCadreJoueur.bmp",NULL);

    if (!fondCadreJoueur4)
    {
        allegro_message("Nous n'avons pas pu charger \"fondCadreJoueur.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/

    //Switch case pour savoir à quel joueur de jouer
        switch (i){
            //Joueur 1
            case 0:
                textprintf_ex(fondCadreJoueur1, font, 300, 5, makecol(255,255,255), -1,  "             |        STATS       |");
                textprintf_ex(fondCadreJoueur1, font, 300, 25, makecol(255,255,255), -1, "             | Nombre PV = %d    |", tabJoueurs[i].PV);
                textprintf_ex(fondCadreJoueur1, font, 300, 45, makecol(255,255,255), -1, "             | Nombre PA = %d     |", tabJoueurs[i].PA);
                textprintf_ex(fondCadreJoueur1, font, 300, 65, makecol(255,255,255), -1, "             | Nombre PM = %d      |", tabJoueurs[i].PM);
                textprintf_ex(fondCadreJoueur1, font, 150, 35, makecol(255,255,255), -1,  "Joueur 1:");
                textprintf_ex(fondCadreJoueur1, font, 240, 35, makecol(255,128,192), -1, "%s",tabJoueurs[i].pseudo);
                textprintf_ex(fondCadreJoueur1, font, 700, 35, makecol(255,255,255), -1,  "---> %s",tabJoueurs[i].choixClasse);

                blit(fondCadreJoueur1,screen, 0, 0, 30, 650, 1024, 768);  //Affichage stats Joueur 1

                break;

            //Joueur 2
            case 1:
                textprintf_ex(fondCadreJoueur2, font, 300, 5, makecol(255,255,255), -1,  "             |        STATS       |");
                textprintf_ex(fondCadreJoueur2, font, 300, 25, makecol(255,255,255), -1, "             | Nombre PV = %d    |", tabJoueurs[i].PV);
                textprintf_ex(fondCadreJoueur2, font, 300, 45, makecol(255,255,255), -1, "             | Nombre PA = %d     |", tabJoueurs[i].PA);
                textprintf_ex(fondCadreJoueur2, font, 300, 65, makecol(255,255,255), -1, "             | Nombre PM = %d      |", tabJoueurs[i].PM);
                textprintf_ex(fondCadreJoueur2, font, 150, 35, makecol(255,255,255), -1,  "Joueur 2:");
                textprintf_ex(fondCadreJoueur2, font, 240, 35, makecol(255,128,192), -1, "%s",tabJoueurs[i].pseudo);
                textprintf_ex(fondCadreJoueur2, font, 700, 35, makecol(255,255,255), -1,  "---> %s",tabJoueurs[i].choixClasse);

                blit(fondCadreJoueur2,screen, 0, 0, 30, 650, 1024, 768);  //Affichage stats Joueur 2

                break;

            //Joueur 3
            case 2:
                textprintf_ex(fondCadreJoueur3, font, 300, 5, makecol(255,255,255), -1,  "             |        STATS       |");
                textprintf_ex(fondCadreJoueur3, font, 300, 25, makecol(255,255,255), -1, "             | Nombre PV = %d    |", tabJoueurs[i].PV);
                textprintf_ex(fondCadreJoueur3, font, 300, 45, makecol(255,255,255), -1, "             | Nombre PA = %d     |", tabJoueurs[i].PA);
                textprintf_ex(fondCadreJoueur3, font, 300, 65, makecol(255,255,255), -1, "             | Nombre PM = %d      |", tabJoueurs[i].PM);
                textprintf_ex(fondCadreJoueur3, font, 150, 35, makecol(255,255,255), -1,  "Joueur 3:");
                textprintf_ex(fondCadreJoueur3, font, 240, 35, makecol(255,128,192), -1, "%s",tabJoueurs[i].pseudo);
                textprintf_ex(fondCadreJoueur3, font, 700, 35, makecol(255,255,255), -1,  "---> %s",tabJoueurs[i].choixClasse);

                blit(fondCadreJoueur3,screen, 0, 0, 30, 650, 1024, 768);  //Affichage stats Joueur 3

                break;

            //Joueur 4
            case 3:
                textprintf_ex(fondCadreJoueur4, font, 300, 5, makecol(255,255,255), -1,  "             |        STATS       |");
                textprintf_ex(fondCadreJoueur4, font, 300, 25, makecol(255,255,255), -1, "             | Nombre PV = %d    |", tabJoueurs[i].PV);
                textprintf_ex(fondCadreJoueur4, font, 300, 45, makecol(255,255,255), -1, "             | Nombre PA = %d     |", tabJoueurs[i].PA);
                textprintf_ex(fondCadreJoueur4, font, 300, 65, makecol(255,255,255), -1, "             | Nombre PM = %d      |", tabJoueurs[i].PM);
                textprintf_ex(fondCadreJoueur4, font, 150, 35, makecol(255,255,255), -1,  "Joueur 4:");
                textprintf_ex(fondCadreJoueur4, font, 240, 35, makecol(255,128,192), -1, "%s",tabJoueurs[i].pseudo);
                textprintf_ex(fondCadreJoueur4, font, 700, 35, makecol(255,255,255), -1,  "---> %s",tabJoueurs[i].choixClasse);

                blit(fondCadreJoueur4,screen, 0, 0, 30, 650, 1024, 768);  //Affichage stats Joueur 4

                break;

            //Par défaut
            default:
                allegro_message("Erreur nbJoueurs faux !");
                break;
            }
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
///Choix de la classe(personnage) des joueurs
void choixClasseJoueur(t_joueur *tabJoueurs, int* nbJoueurs)
{
    int i=0;
    int clic=0;

    //Création double buffer (arriere-plan)
    /******************************************************************************/
    BITMAP* arrierePlanChoix;
    arrierePlanChoix = load_bitmap("arrierePlanChoix.bmp",NULL);

    if (!arrierePlanChoix)
    {
        allegro_message("Nous n'avons pas pu charger \"arrierePlanChoix.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/

    //Création double buffer (tour du joueur)
    /******************************************************************************/
    BITMAP* fondCadreJoueur;
    fondCadreJoueur = load_bitmap("fondCadreJoueur.bmp",NULL);

    if (!fondCadreJoueur)
    {
        allegro_message("Nous n'avons pas pu charger \"fondCadreJoueur.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/

    //Création cadre
    /******************************************************************************/
    BITMAP* cadreJoueur;
    cadreJoueur = load_bitmap("cadreJoueur.bmp",NULL);

    if (!cadreJoueur)
    {
        allegro_message("Nous n'avons pas pu charger \"cadreJoueur.bmp\"");
        quitterAllegro();
    }

    draw_sprite(arrierePlanChoix, cadreJoueur, 25, 640); //Affichage cadre
    /******************************************************************************/

    //Logo classes
    /******************************************************/
    //Classe feu
    BITMAP* logoFeu;
    logoFeu = load_bitmap("logoFeu.bmp",NULL);

    if (!logoFeu)
    {
        allegro_message("Nous n'avons pas pu charger \"logoFeu.bmp\"");
        quitterAllegro();
    }
    /******************************************************/
    //Classe électricité
    BITMAP* logoElec;
    logoElec = load_bitmap("logoElec.bmp",NULL);

    if (!logoElec)
    {
        allegro_message("Nous n'avons pas pu charger \"logoElec.bmp\"");
        quitterAllegro();
    }
    /******************************************************/
    //Classe Plante
    BITMAP* logoPlante;
    logoPlante = load_bitmap("logoPlante.bmp",NULL);

    if (!logoPlante)
    {
        allegro_message("Nous n'avons pas pu charger \"logoPlante.bmp\"");
        quitterAllegro();
    }
    /******************************************************/
    //Classe eau
    BITMAP* logoEau;
    logoEau= load_bitmap("logoEau.bmp",NULL);

    if (!logoEau)
    {
        allegro_message("Nous n'avons pas pu charger \"logoEau.bmp\"");
        quitterAllegro();
    }
    /******************************************************/


    //Création Dresseurs
    /******************************************************/
    //Dresseur 1
    BITMAP* Dresseur1;
    Dresseur1 = load_bitmap("Dresseur1.bmp",NULL);

    if (!Dresseur1)
    {
        allegro_message("Nous n'avons pas pu charger \"Dresseur1.bmp\"");
        quitterAllegro();
    }

    //Affichage
    draw_sprite(arrierePlanChoix, Dresseur1, 80, 140);
    draw_sprite(arrierePlanChoix, logoFeu, 135, 375);
    textprintf_ex(arrierePlanChoix, font, 80, 125, makecol(190,0,0), -1, "Sacha");
    /******************************************************/
    //Dresseur 2
    BITMAP* Dresseur2;
    Dresseur2 = load_bitmap("Dresseur2.bmp",NULL);

    if (!Dresseur2)
    {
        allegro_message("Nous n'avons pas pu charger \"Dresseur2.bmp\"");
        quitterAllegro();
    }

    //Affichage
    draw_sprite(arrierePlanChoix, Dresseur2, 330, 140);
    draw_sprite(arrierePlanChoix, logoElec, 385, 375);
    textprintf_ex(arrierePlanChoix, font, 330, 125, makecol(244,223,0), -1, "Clem");
    /******************************************************/
    //Dresseur 3
    BITMAP* Dresseur3;
    Dresseur3 = load_bitmap("Dresseur3.bmp",NULL);

    if (!Dresseur3)
    {
        allegro_message("Nous n'avons pas pu charger \"Dresseur3.bmp\"");
        quitterAllegro();
    }

    //Affichage
    draw_sprite(arrierePlanChoix, Dresseur3, 580, 140);
    draw_sprite(arrierePlanChoix, logoPlante, 635, 375);
    textprintf_ex(arrierePlanChoix, font, 580, 125, makecol(0,194,21), -1, "Pierre");
    /******************************************************/
    //Dresseur 4
    BITMAP* Dresseur4;
    Dresseur4 = load_bitmap("Dresseur4.bmp",NULL);

    if (!Dresseur4)
    {
        allegro_message("Nous n'avons pas pu charger \"Dresseur4.bmp\"");
        quitterAllegro();
    }

    //Affichage
    draw_sprite(arrierePlanChoix, Dresseur4, 830, 140);
    draw_sprite(arrierePlanChoix, logoEau, 885, 375);
    textprintf_ex(arrierePlanChoix, font, 830, 125, makecol(0,78,202), -1, "Flora");
    /******************************************************/

    //Affichages
    textprintf_ex(arrierePlanChoix, font, 450, 50, makecol(202,112,0),-1, "Choix du dresseur:");
    textprintf_ex(arrierePlanChoix, font, 20, 80, makecol(128,0,128), -1, "Nombre joueurs: %d", *nbJoueurs);
    rect(arrierePlanChoix, 445,46,600,61, makecol(202,112,0));
    line(arrierePlanChoix,23,93,149,93, makecol(128,0,128));

    //On affiche tout sur le screen
    blit(arrierePlanChoix,screen, 0, 0, 0, 0, 1024, 768);
    affichageBoutonExit();  //On affiche le bouton exit

    sleep(1); //Pause de 2sec

    clear(fondCadreJoueur);
    textprintf_ex(fondCadreJoueur, font, 360, 30, makecol(255,255,255), -1, "Choisissez votre dresseur !");  //On affiche à chaque tour

    //Boucle des choix de classe
    while(i < *nbJoueurs)
    {

        clear(fondCadreJoueur);
        textprintf_ex(fondCadreJoueur, font, 360, 30, makecol(255,255,255), -1, "Choisissez votre dresseur !");  //On affiche à chaque tour
        blit(fondCadreJoueur,screen, 0, 0, 30, 650, 1024, 768);  //Double buffer sur le cadre

        while(clic == 0)  //Boucle pour pouvoir choisir en cliquant sur les 'cases' des dresseurs
        {
            //Si clic gauche souris cliqué
            if (mouse_b & 1)
            {
                //Choix du dresseur 1
                if(mouse_x>=83 && mouse_x<=235 && mouse_y>=142 && mouse_y<=362) //Si souris clique 'case' du dresseur
                {
                    tabJoueurs[i].choixClasseVerif[0] = 1;  //Le joueur "i" a choisi le dresseur 1 (donc plus disponible)

                    if (tabJoueurs[i-1].choixClasseVerif[0] == 0)   //Si dresseur non pris par un joueur
                    {
                        clic=1;

                        strcpy(tabJoueurs[i].pseudo,"Sacha");     //On affecte le nom du dresseur au joueur
                        strcpy(tabJoueurs[i].choixClasse,"Classe: FEU");

                        attributionClasseJoueur(tabJoueurs,nbJoueurs,i); //Appel sous fonction attribution

                        rectfill(screen, 80, 140, 235, 362, makecol(195,195,195));  //Colorise 'case' dresseur choisi
                    }
                }

                //Choix du dresseur 2
                if(mouse_x>=331 && mouse_x<=486 && mouse_y>=142 && mouse_y<=362)
                {
                    tabJoueurs[i].choixClasseVerif[1] = 1;

                    if (tabJoueurs[i-1].choixClasseVerif[1] == 0)   //Si souris clique 'case' du dresseur & dresseur non pris
                    {

                        clic=1;

                        strcpy(tabJoueurs[i].pseudo,"Clem");
                        strcpy(tabJoueurs[i].choixClasse,"Classe: ELECTRIQUE");

                        attributionClasseJoueur(tabJoueurs,nbJoueurs,i);

                        rectfill(screen, 330, 140, 486, 362, makecol(195,195,195));
                    }
                }

                //Choix du dresseur 3
                if(mouse_x>=581 && mouse_x<=731 && mouse_y>=142 && mouse_y<=362)
                {
                    tabJoueurs[i].choixClasseVerif[2] = 1;

                    if (tabJoueurs[i-1].choixClasseVerif[2] == 0)   //Si souris clique 'case' du dresseur & dresseur non pris
                    {
                        clic=1;

                        strcpy(tabJoueurs[i].pseudo,"Pierre");
                        strcpy(tabJoueurs[i].choixClasse,"Classe: PLANTE");

                        attributionClasseJoueur(tabJoueurs,nbJoueurs,i);

                        rectfill(screen, 580, 140, 730, 362, makecol(195,195,195));
                    }
                }

                //Choix du dresseur 4
                if(mouse_x>=831 && mouse_x<=987 && mouse_y>=142 && mouse_y<=362)
                {
                    tabJoueurs[i].choixClasseVerif[3] = 1;

                    if (tabJoueurs[i-1].choixClasseVerif[3] == 0)   //Si souris clique 'case' du dresseur & dresseur non pris
                    {

                        clic=1;

                        strcpy(tabJoueurs[i].pseudo,"Flora");
                        strcpy(tabJoueurs[i].choixClasse,"Classe: EAU");

                        attributionClasseJoueur(tabJoueurs,nbJoueurs,i);

                        rectfill(screen, 830, 140, 987, 362, makecol(195,195,195));
                    }
                }

                //Quitter le jeu
                if (mouse_x<=40 && mouse_y<=20)
                {
                    exitJeu();
                }

            }  //Fin boucle 'clic gauche'

        } //Fin boucle choix classe pour 1 tour

        i++; //On passe au tour suivant
        clic=0; // Condition réinitialisée pour re-rentrer dans la 2e boucle while

        sleep(3);

        /*------------------------------------------------*/   ///Passage au joueur suivant
        if (i == *nbJoueurs)
            allegro_message("Lancer la partie");
        else
            allegro_message("--> Passer au 'Joueur %d'", i+1);
        /*------------------------------------------------*/

    }//Fin boucle while (choix des classes jusqu'à NbJoueurs)

    clear_bitmap(screen);
    sleep(0.5);
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
///Choix du nb de joueurs (avec affichage des boutons)
void choixNbJoueurs(t_joueur *tabJoueurs, int* nbJoueurs)
{
    int clic=0;

    //Création double buffer
    /******************************************************************************/     //Création / chargement bitmaps
    BITMAP* arrierePlanMenu;
    arrierePlanMenu = load_bitmap("choixJoueurs.bmp",NULL);

    if (!arrierePlanMenu)
    {
        allegro_message("Nous n'avons pas pu charger \"choixJoueurs.bmp\"");
        quitterAllegro();
    }

    //Création boutons choix du nb de joueurs
    /******************************************************************************/
    BITMAP* bouton2p;
    bouton2p = load_bitmap("Bouton 2p.bmp",NULL);

    if (!bouton2p)
    {
        allegro_message("Nous n'avons pas pu charger \"Bouton 2p.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* bouton3p;
    bouton3p = load_bitmap("Bouton 3p.bmp",NULL);

    if (!bouton3p)
    {
        allegro_message("Nous n'avons pas pu charger \"Bouton 3p.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* bouton4p;
    bouton4p = load_bitmap("Bouton 4p.bmp",NULL);

    if (!bouton4p)
    {
        allegro_message("Nous n'avons pas pu charger \"Bouton 4p.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/

    //Affichages sur le buffer
    textout_centre_ex(arrierePlanMenu, font, "Combien de joueurs ?", 512, 280, makecol(128,0,128), -1);
    rect(arrierePlanMenu,421,273,603,291, makecol(255,0,0));
    draw_sprite(arrierePlanMenu, bouton2p, 106, 310);   //Affichage des 3 boutons pour le nombres de joueurs
    draw_sprite(arrierePlanMenu, bouton3p, 412, 310);
    draw_sprite(arrierePlanMenu, bouton4p, 718, 310);

    //On copie le buffer sur le screen
    blit(arrierePlanMenu,screen, 0, 0, 0, 0, 1024, 768);
    affichageBoutonExit();

    sleep(1);  //Pause de 1s

    while (clic == 0){
        ////Si clic gauche souris cliqué
        if (mouse_b & 1)
        {
            //Si bouton '2 joueurs' cliqué -> initialisation pour 2 joueurs
            if(mouse_x>=106 && mouse_x<=306 && mouse_y>=310&& mouse_y<=387)
            {
                clic=1;
                initialiserJoueurStats(tabJoueurs,2); // initialisation stats de 2 joueurs
                *nbJoueurs=2;
                clear_bitmap(screen);
                choixClasseJoueur(tabJoueurs,nbJoueurs);   //Appel choix des classes
            }

            //Si bouton '3 joueurs' cliqué -> initialisation pour 3 joueurs
            if(mouse_x>=412 && mouse_x<=612 && mouse_y>=310&& mouse_y<=387)
            {
                clic=1;
                initialiserJoueurStats(tabJoueurs,3); // initialisation stats de 3 joueurs
                *nbJoueurs=3;
                clear_bitmap(screen);
                choixClasseJoueur(tabJoueurs,nbJoueurs);
            }

            //Si bouton '4 joueurs' cliqué -> initialisation pour 4 joueurs
            if(mouse_x>=718 && mouse_x<=918 && mouse_y>=310&& mouse_y<=387)
            {
                clic=1;
                initialiserJoueurStats(tabJoueurs,4); // initialisation stats de 4 joueurs
                *nbJoueurs=4;
                clear_bitmap(screen);
                choixClasseJoueur(tabJoueurs,nbJoueurs);
            }

            ////Si bouton 'exit' cliqué -> quitte le jeu
            if (mouse_x<=40 && mouse_y<=20)
            {
                exitJeu();
            }
        }
    }
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
///Lancement du jeu (chargement, choix des joueurs,...)
void menuDemarrage(t_joueur *tabJoueurs, int* nbJoueurs)
{
    int clic = 0;
    show_mouse(screen);   //Affichage curseur souris

    /******************************************************************************/   //Création / chargement bitmaps
    BITMAP* imageMenu1;
    imageMenu1 = load_bitmap("Image menu chargement 1.bmp",NULL);

    if (!imageMenu1)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 1.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu2;
    imageMenu2 = load_bitmap("Image menu chargement 2.bmp",NULL);

    if (!imageMenu2)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 2.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu3;
    imageMenu3 = load_bitmap("Image menu chargement 3.bmp",NULL);

    if (!imageMenu3)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 3.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu4;
    imageMenu4 = load_bitmap("Image menu chargement 4.bmp",NULL);

    if (!imageMenu4)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 4.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu5;
    imageMenu5 = load_bitmap("Image menu chargement 5.bmp",NULL);

    if (!imageMenu5)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 5.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu6;
    imageMenu6 = load_bitmap("Image menu chargement 6.bmp",NULL);

    if (!imageMenu6)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 6.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu7;
    imageMenu7 = load_bitmap("Image menu chargement 7.bmp",NULL);

    if (!imageMenu7)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 7.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* boutonStart;
    boutonStart = load_bitmap("Bouton start.bmp",NULL);

    if (!boutonStart)
    {
        allegro_message("Nous n'avons pas pu charger \"Bouton start.bmp\"");
        quitterAllegro();;
    }
    /******************************************************************************/
    BITMAP* menuStart;
    menuStart = load_bitmap("menuStart.bmp",NULL);

    if (!menuStart)
    {
        allegro_message("Nous n'avons pas pu charger \"menuStart.bmp\"");
        quitterAllegro();;
    }
    /******************************************************************************/


    //******************************************************************************//
    //Affichage bitmaps
    blit(imageMenu1,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);  //Pause de 1s

    clear_bitmap(screen);
    blit(imageMenu2,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement.", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    clear_bitmap(screen);
    blit(imageMenu3,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement..", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    clear_bitmap(screen);
    blit(imageMenu4,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement...", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    clear_bitmap(screen);
    blit(imageMenu5,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement.", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    clear_bitmap(screen);
    blit(imageMenu6,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement..", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    clear_bitmap(screen);
    blit(imageMenu7,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement...", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    clear_bitmap(screen);
    blit(menuStart,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Appuyez sur 'Start' pour commencer.", 512, 400, makecol(255, 255, 255), -1);
    draw_sprite(screen, boutonStart, 415, 434);
    //******************************************************************************//

   //Utilisation de la souris sur les boutons (boucle)
    while (clic == 0){
        //Si clic gauche souris cliqué
        if (mouse_b & 1)
        {
            //Si bouton 'start' cliqué -> lancement choix des joueurs
            if(mouse_x>=415 && mouse_x<=585 && mouse_y>=434 && mouse_y<=532 && (mouse_b & 1))
            {
                clic=1;
                //Suppresion des anciennes bitmaps sauf la 7 qui reste pour le fond d'écran
                destroy_bitmap(imageMenu1);
                destroy_bitmap(imageMenu2);
                destroy_bitmap(imageMenu3);
                destroy_bitmap(imageMenu4);
                destroy_bitmap(imageMenu5);
                destroy_bitmap(imageMenu6);
                destroy_bitmap(imageMenu7);
                destroy_bitmap(boutonStart);

                clear_bitmap(screen);

                //Appel de la fonction pour le choix du nombre de joueurs
                choixNbJoueurs(tabJoueurs,nbJoueurs);

            }
        }
    }
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
void chargementDecorArene()
{
    clear_bitmap(screen);

    int clic=0;

    //Déclaration bitmap arene
    /******************************************************************************/
    BITMAP* mapJeu;
    mapJeu = load_bitmap("mapJeu.bmp",NULL);

    if (!mapJeu)
    {
        allegro_message("Nous n'avons pas pu charger \"mapJeu.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/

    blit(mapJeu,screen, 0, 0, 0, 0, 1024, 768);  //Affichage arene
    affichageBoutonExit();

     while (clic == 0){

        //Si clic gauche souris cliqué
        if (mouse_b & 1)
        {
            //Si bouton 'exit' cliqué -> quitte le jeu
            if (mouse_x<=40 && mouse_y<=20)
            {
                exitJeu();
            }
        }
    }
}
/*-----------------------------------------------------------------------------------------------------*/
