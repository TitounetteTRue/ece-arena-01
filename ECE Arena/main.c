#include "biblioJeu.h"

/*----------------------------------------------------------*/
int main()
{
    //D�clarations
    int* nbJoueurs;
    t_joueur *tabJoueurs;   //Tableau de joueurs
    tabJoueurs = (t_joueur*) malloc(2*sizeof(t_joueur));

     // Initialisation d'Allegro
    initialisationAllegro();

    // install_keyboard(); //Installation du clavier

    if (install_mouse() == -1)    //Installation de la souris
    {
        textprintf_ex(screen, font, 100, 10, makecol(255,0,0), -1, "Erreur installation de la souris");
        return 1;
    }

    show_mouse(screen); //Permet de montrer la souris � l'�cran

    menuDemarrage(tabJoueurs,nbJoueurs);  //Appel Fonction d�but partie
    chargementDecorArene();

    return 0;  // Fin du main

}END_OF_MAIN();  //Macro pour quitter Allegro
/*-----------------------------------------------------------------------------------------------------*/
