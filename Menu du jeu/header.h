#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <unistd.h>

unsigned int sleep(unsigned int nb_sec);
void bouton_start(BITMAP *boutonStart, int posx, int posy, int pos2x, int pos2y);
void choix_player();


#endif // HEADER_H_INCLUDED
