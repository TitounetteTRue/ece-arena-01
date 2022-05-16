#include "maBiblioJeu.h"

void start()
{
    show_mouse(screen);

    BITMAP* imageMenu1;
    imageMenu1 = load_bitmap("Image menu chargement 1.bmp",NULL);

    if (!imageMenu1)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 1.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    BITMAP* imageMenu2;
    imageMenu2 = load_bitmap("Image menu chargement 2.bmp",NULL);

    if (!imageMenu2)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 2.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    BITMAP* imageMenu3;
    imageMenu3 = load_bitmap("Image menu chargement 3.bmp",NULL);

    if (!imageMenu3)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 3.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    BITMAP* imageMenu4;
    imageMenu4 = load_bitmap("Image menu chargement 4.bmp",NULL);

    if (!imageMenu4)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 4.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    BITMAP* imageMenu5;
    imageMenu5 = load_bitmap("Image menu chargement 5.bmp",NULL);

    if (!imageMenu5)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 5.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    BITMAP* imageMenu6;
    imageMenu6 = load_bitmap("Image menu chargement 6.bmp",NULL);

    if (!imageMenu6)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 6.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    BITMAP* imageMenu7;
    imageMenu7 = load_bitmap("Image menu chargement 7.bmp",NULL);

    if (!imageMenu7)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 7.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    BITMAP* boutonStart;
    boutonStart = load_bitmap("Bouton start.bmp",NULL);

    if (!boutonStart)
    {
        allegro_message("Nous n'avons pas pu charger \"Bouton start.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    blit(imageMenu1,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);


    blit(imageMenu2,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement.", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);


    blit(imageMenu3,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement..", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);


    blit(imageMenu4,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement...", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);


    blit(imageMenu5,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement.", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);


    blit(imageMenu6,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement..", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    blit(imageMenu7,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Chargement...", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);


    blit(imageMenu7,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "Appyuez sur Start pour commencer.", 512, 384, makecol(255, 255, 255), -1);
    draw_sprite(screen, boutonStart, 415, 434);
    rectfill(screen,0,0,40,20,makecol(255,255,0));
    textprintf_ex(screen,font,4,6,makecol(0,0,0),makecol(255,0,0),"EXIT");


    int clique = 0;
    while (clique == 0){
        //Si la souris est sur le bouton
        if (mouse_b & 1)
        {
            if(mouse_x>=415 && mouse_x<=585 && mouse_y>=434 && mouse_y<=532 && (mouse_b & 1))
            {
                //Suppresion des anciennes bitmaps sauf la 7 qui reste pour le fond d'écran
                destroy_bitmap(imageMenu1);
                destroy_bitmap(imageMenu2);
                destroy_bitmap(imageMenu3);
                destroy_bitmap(imageMenu4);
                destroy_bitmap(imageMenu5);
                destroy_bitmap(imageMenu6);
                destroy_bitmap(boutonStart);
                //Appel de la fonction pour le choix du nombre de joueurs
                choix_player();
                clique=1;
            }
            if (mouse_x<=40 && mouse_y<=20)
            {
                // prise en compte effective de la zone cliquable EXIT :
                // clic gauche en haut à gauche de l'écran -> fin du programme
                allegro_message("QUOIIIII !!! Tu quittes notre jeu ?? Nahhhh ca doit etre une erreur tu as mal clique aller revient jouer (c'est un ordre).");
                allegro_exit();
                exit(EXIT_FAILURE);
            }
        }
    }
    destroy_bitmap(imageMenu7);
}




void choix_player()
{
    int nombreJoueurs;
    ///CHARGEMENT DES BITMAPS
    BITMAP* imageMenu7;
    imageMenu7 = load_bitmap("Image menu chargement 7.bmp",NULL);

    if (!imageMenu7)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 7.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    BITMAP* bouton2p;
    bouton2p = load_bitmap("Bouton 2p.bmp",NULL);

    if (!bouton2p)
    {
        allegro_message("Nous n'avons pas pu charger \"Bouton 2p.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    BITMAP* bouton3p;
    bouton3p = load_bitmap("Bouton 3p.bmp",NULL);

    if (!bouton3p)
    {
        allegro_message("Nous n'avons pas pu charger \"Bouton 3p.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    BITMAP* bouton4p;
    bouton4p = load_bitmap("Bouton 4p.bmp",NULL);

    if (!bouton4p)
    {
        allegro_message("Nous n'avons pas pu charger \"Bouton 4p.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/
    BITMAP* casenomjoueur;
    casenomjoueur = load_bitmap("Nom banniere joueur basique2.bmp",NULL);

    if (!casenomjoueur)
    {
        allegro_message("Nous n'avons pas pu charger \"Nom banniere joueur basique2.bmp\"");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /******************************************************************************/

    blit(imageMenu7,screen, 0, 0, 0, 0, 1024, 768);
    textout_centre_ex(screen, font, "A combien voulez vous jouer ?", 512, 384, makecol(255, 255, 255), -1);

    //Affichage des 3 boutons pour le nombres de joueurs
    draw_sprite(screen, bouton2p, 106, 440);
    draw_sprite(screen, bouton3p, 412, 440);
    draw_sprite(screen, bouton4p, 718, 440);

    rectfill(screen,0,0,40,20,makecol(0,0,0));
    textprintf_ex(screen,font,4,6,makecol(255,255,0),makecol(255,0,0),"EXIT");

    sleep(1);

    int clic = 0;
    while (clic == 0){
        //Si la souris est sur le bouton "2 joueurs" et qu'il y a un clic
        if (mouse_b & 1)
        {
            if(mouse_x>=106 && mouse_x<=306 && mouse_y>=440 && mouse_y<=517)
            {
                blit(imageMenu7,screen, 0, 0, 0, 0, 1024, 768);
                destroy_bitmap(bouton2p);
                destroy_bitmap(bouton3p);
                destroy_bitmap(bouton4p);
                draw_sprite(screen, casenomjoueur, 100, 160);
                draw_sprite(screen, casenomjoueur, 100, 440);
                textout_centre_ex(screen, font, "Entrez le nom du premier joueur :", 260, 180, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du deuxieme joueur :", 260, 460, makecol(255, 255, 255), -1);
                clic=1;
                nombreJoueurs=2;
                sleep(50);
            }
            if(mouse_x>=412 && mouse_x<=612 && mouse_y>=440 && mouse_y<=517)
            {
                blit(imageMenu7,screen, 0, 0, 0, 0, 1024, 768);
                destroy_bitmap(bouton2p);
                destroy_bitmap(bouton3p);
                destroy_bitmap(bouton4p);
                draw_sprite(screen, casenomjoueur, 100, 110);
                draw_sprite(screen, casenomjoueur, 100, 310);
                draw_sprite(screen, casenomjoueur, 100, 510);
                textout_centre_ex(screen, font, "Entrez le nom du premier joueur :", 260, 130, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du deuxieme joueur :", 260, 330, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du troisieme joueur :", 260, 530, makecol(255, 255, 255), -1);
                clic=1;
                nombreJoueurs=3;
                sleep(50);
            }
            if(mouse_x>=718 && mouse_x<=918 && mouse_y>=440 && mouse_y<=517)
            {
                blit(imageMenu7,screen, 0, 0, 0, 0, 1024, 768);
                destroy_bitmap(bouton2p);
                destroy_bitmap(bouton3p);
                destroy_bitmap(bouton4p);
                draw_sprite(screen, casenomjoueur, 100, 70);
                draw_sprite(screen, casenomjoueur, 100, 245);
                draw_sprite(screen, casenomjoueur, 100, 425);
                draw_sprite(screen, casenomjoueur, 100, 590);
                textout_centre_ex(screen, font, "Entrez le nom du premier joueur :", 260, 90, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du deuxieme joueur :", 260, 265, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du troisieme joueur :", 260, 445, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du quatrieme joueur :", 260, 610, makecol(255, 255, 255), -1);
                clic=1;
                nombreJoueurs=4;
                sleep(50);
            }
            if (mouse_x<=40 && mouse_y<=20)
            {
                allegro_message("QUOIIIII !!! Tu quittes notre jeu ?? Nahhhh ca doit etre une erreur tu as mal clique aller revient jouer (c'est un ordre)");
                allegro_exit();
                exit(EXIT_FAILURE);
            }
        }
    }
}


int main()
{
    allegro_init();     ///Lancer allegro et le mode graphique
    install_keyboard(); ///Installation du clavier
    if (install_mouse() == -1)    ///Installation de la souris
    {
        printf("%ca marche pas, demande %c Cyrk%c5391 sur Discord", 128 ,133, 23);
        return 1;
    }
    show_mouse(screen); ///Permet de montrer la souris à l'écran

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0)!=0)
    {
        allegro_message("Probl%cme graphique", 138);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    start();

    return 0;
}END_OF_MAIN();
