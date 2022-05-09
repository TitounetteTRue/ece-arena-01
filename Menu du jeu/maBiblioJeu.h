#ifndef MABIBLIOJEU_H_INCLUDED
#define MABIBLIOJEU_H_INCLUDED

/*----------------------------------------------*/
///Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <allegro.h>
/*----------------------------------------------*/


/*----------------------------------------------*/
///Structures
typedef struct joueur{

    char pseudo[50];
    int PV;
    int PM;
    int PA;
    int ligne;
    int colonne;
    int choixClasse;

}t_joueur;
/*----------------------------------------------*/


/*----------------------------------------------*/
///Prototypes
void bouton_start(BITMAP *boutonStart, int posx, int posy, int pos2x, int pos2y);
void choix_player();
void initialiserJoueur(t_joueur *tabJoueurs, int nbJoueurs, int i);



/*----------------------------------------------*/



#endif // MABIBLIOJEU_H_INCLUDED
