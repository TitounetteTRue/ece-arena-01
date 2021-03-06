#include "biblioJeu.h"

/*----------------------------------------------------------*/
int main()
{
    //Déclarations
    int* nbJoueurs;
    t_joueur *tabJoueurs;   //Tableau de joueurs
    tabJoueurs = (t_joueur*) malloc(2*sizeof(t_joueur));
    BITMAP* map;
    BITMAP* page;
    BITMAP* spriteDresseur[4][16]; // 4 dresseurs et 16 postions par dresseur
    page=create_bitmap(1024,768);

     // Initialisation d'Allegro
    initialisationAllegro();

    // install_keyboard(); //Installation du clavier

    if (install_mouse() == -1)    //Installation de la souris
    {
        textprintf_ex(screen, font, 100, 10, makecol(255,0,0), -1, "Erreur installation de la souris");
        return 1;
    }

    show_mouse(screen); //Permet de montrer la souris à l'écran

    menuDemarrage(tabJoueurs,nbJoueurs);  //Appel Fonction début partie
    chargementDecorArene();

    return 0;  // Fin du main

}END_OF_MAIN();  //Macro pour quitter Allegro
/*-----------------------------------------------------------------------------------------------------*/
