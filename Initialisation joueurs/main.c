#include "maBiblioJeu.h"

/*----------------------------------------------*/
///Programme principal
int main()
{
    int nbJoueurs;    //Déclarations
    int i;
    t_joueur *tabJoueurs;

    srand(time(NULL));   //Utilisation aléatoire plus tard

    while (nbJoueurs<2 || nbJoueurs>4)   //Boucle (blindage)
    {
        printf("Combien de joueurs ? \n");   //On demande Nb de joueurs
        scanf("%d", & nbJoueurs);
        fflush(stdin);

        if(nbJoueurs<2 || nbJoueurs>4)
            printf("Erreur: choisir entre 2 et 4 joueurs \n\n");    //Message d'erreur
    }

    tabJoueurs = (t_joueur*) malloc(nbJoueurs*sizeof(t_joueur));    //Déclaration tableau de joueurs (alloc dynamique)

    initialiserJoueur(tabJoueurs,nbJoueurs,i);    //Appel fonction

    printf("%s en x: %d\n",tabJoueurs[1].pseudo, tabJoueurs[1].ligne);   //Exemple: coordonnées du joueur 2
    printf("%s en y: %d\n",tabJoueurs[1].pseudo, tabJoueurs[1].colonne);

    return 0;
}
/*----------------------------------------------*/


/*----------------------------------------------*/
///Initialisation des joueurs au début de la partie
void initialiserJoueur(t_joueur *tabJoueurs, int nbJoueurs, int i)   //Paramètres: tableau de joueurs, nb de joueurs, "i" pour le numéro du joueur
{

    for(i=0; i<nbJoueurs; i++)  //Boucle pour initialiser tous les joueurs
    {
        tabJoueurs[i].PV = 500;   //Initialisation des stats
        tabJoueurs[i].PM = 3;
        tabJoueurs[i].PA = 20;
        tabJoueurs[i].ligne = rand()% (12-1 +1) + 1;   //Placement aléatoire entre 1 et 12
        tabJoueurs[i].colonne = rand()% (16-1 +1) + 1;   //Placement aléatoire entre 1 et 16

        printf("Nom du joueur ? \n");
        gets(tabJoueurs[i].pseudo);
        printf("Pseudo joueur %d: %s \n\n", i+1, tabJoueurs[i].pseudo);   //Affichage pseudo
    }

}
/*----------------------------------------------*/
