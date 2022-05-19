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

    char pseudo[30];
    char choixClasse[30];
    int PV;
    int PM;
    int PA;
    int ligne;
    int colonne;
    int choixClasseVerif[3];  //Permet de ne pas choisir une classe déjà sélectionnée
    int vivant;
    int cpt;

}t_joueur;
/*----------------------------------------------*/


/*----------------------------------------------*/
///Prototypes
void initialisationAllegro();
void quitterAllegro();
void affichageBoutonExit();
void exitJeu();
void initialiserJoueurStats(t_joueur *tabJoueurs, int nbJoueurs);
void attributionClasseJoueur(t_joueur* tabJoueurs, int* nbJoueurs, int i);
void choixClasseJoueur(t_joueur *tabJoueurs, int* nbJoueurs);
void choixNbJoueurs(t_joueur *tabJoueurs, int* nbJoueurs);
void menuDemarrage(t_joueur *tabJoueurs, int* nbJoueurs);
void chargementDecorArene();

/*----------------------------------------------*/


#endif // MABIBLIOJEU_H_INCLUDED
