#include "header.h"

void start()
{
    show_mouse(screen);
    int i=0;

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
    for(i=0; i<1; i++){

        blit(imageMenu1,screen, 0, 0, 0, 0, 800, 800);
        textout_centre_ex(screen, font, "Chargement", 400, 300, makecol(0, 0, 0), -1);
        sleep(1);


        blit(imageMenu2,screen, 0, 0, 0, 0, 800, 800);
        textout_centre_ex(screen, font, "Chargement.", 400, 300, makecol(0, 0, 0), -1);
        sleep(1);


        blit(imageMenu3,screen, 0, 0, 0, 0, 800, 800);
        textout_centre_ex(screen, font, "Chargement..", 400, 300, makecol(0, 0, 0), -1);
        sleep(1);


        blit(imageMenu4,screen, 0, 0, 0, 0, 800, 800);
        textout_centre_ex(screen, font, "Chargement...", 400, 300, makecol(0, 0, 0), -1);
        sleep(1);


        blit(imageMenu5,screen, 0, 0, 0, 0, 800, 800);
        textout_centre_ex(screen, font, "Chargement.", 400, 300, makecol(0, 0, 0), -1);
        sleep(1);


        blit(imageMenu6,screen, 0, 0, 0, 0, 800, 800);
        textout_centre_ex(screen, font, "Chargement..", 400, 300, makecol(0, 0, 0), -1);
        sleep(1);

        blit(imageMenu7,screen, 0, 0, 0, 0, 800, 800);
        textout_centre_ex(screen, font, "Chargement...", 400, 300, makecol(0, 0, 0), -1);
        sleep(1);
    }

    blit(imageMenu7,screen, 0, 0, 0, 0, 800, 800);
    textout_centre_ex(screen, font, "Appyuez sur Start pour commencer.", 400, 300, makecol(255, 255, 255), -1);
    draw_sprite(screen, boutonStart, 300, 350);


    int clique = 0;
    while (clique == 0){
        //Si la souris est sur le bouton
        if(mouse_x>=300 && mouse_x<=470 && mouse_y>=350 && mouse_y<=448 && (mouse_b & 1))
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
    }
    destroy_bitmap(imageMenu7);
}




void choix_player()
{
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


    blit(imageMenu7,screen, 0, 0, 0, 0, 800, 800);
    textout_centre_ex(screen, font, "A combien voulez vous jouer ?", 400, 300, makecol(255, 255, 255), -1);

    //Affichage des 3 boutons pour le nombres de joueurs
    draw_sprite(screen, bouton2p, 90, 350);
    draw_sprite(screen, bouton3p, 300, 350);
    draw_sprite(screen, bouton4p, 510, 350);


    sleep(1);

    int clic = 0;
    while (clic == 0){
        //Si la souris est sur le bouton "2 joueurs" et qu'il y a un clic
        if (mouse_b & 1){
            if((mouse_x>=90) && (mouse_x<=290) && (mouse_y>=353) && (mouse_y<=422))
            {
                blit(imageMenu7,screen, 0, 0, 0, 0, 800, 800);
                destroy_bitmap(bouton2p);
                destroy_bitmap(bouton3p);
                destroy_bitmap(bouton4p);
                draw_sprite(screen, casenomjoueur, 100, 150);
                draw_sprite(screen, casenomjoueur, 100, 350);
                textout_centre_ex(screen, font, "Entrez le nom du premier joueur :", 260, 170, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du deuxieme joueur :", 260, 370, makecol(255, 255, 255), -1);
                clic=1;
                sleep(50);
            }
            if(mouse_x>=300 && mouse_x<=500 && mouse_y>=350 && mouse_y<=422)
            {
                blit(imageMenu7,screen, 0, 0, 0, 0, 800, 800);
                destroy_bitmap(bouton2p);
                destroy_bitmap(bouton3p);
                destroy_bitmap(bouton4p);
                draw_sprite(screen, casenomjoueur, 100, 75);
                draw_sprite(screen, casenomjoueur, 100, 250);
                draw_sprite(screen, casenomjoueur, 100, 425);
                textout_centre_ex(screen, font, "Entrez le nom du premier joueur :", 260, 95, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du deuxieme joueur :", 260, 270, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du troisieme joueur :", 260, 445, makecol(255, 255, 255), -1);
                clic=1;
                sleep(50);
            }
            if(mouse_x>=510 && mouse_x<=710 && mouse_y>=350 && mouse_y<=422)
            {
                blit(imageMenu7,screen, 0, 0, 0, 0, 800, 800);
                destroy_bitmap(bouton2p);
                destroy_bitmap(bouton3p);
                destroy_bitmap(bouton4p);
                draw_sprite(screen, casenomjoueur, 100, 0);
                draw_sprite(screen, casenomjoueur, 100, 150);
                draw_sprite(screen, casenomjoueur, 100, 300);
                draw_sprite(screen, casenomjoueur, 100, 450);
                textout_centre_ex(screen, font, "Entrez le nom du premier joueur :", 260, 20, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du deuxieme joueur :", 260, 170, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du troisieme joueur :", 260, 320, makecol(255, 255, 255), -1);
                textout_centre_ex(screen, font, "Entrez le nom du quatrieme joueur :", 260, 470, makecol(255, 255, 255), -1);
                clic=1;
                sleep(50);
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
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("Probl%cme graphique", 138);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    start();

    return 0;

}END_OF_MAIN();
