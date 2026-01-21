#ifndef GLOBAL_H
#define GLOBAL_H
// Fitxategia ondo joateko, includeak sartuko ditut
#include "assets/assets.h"
#include "config/config.h"
#include <SDL.h>

// Fitxategi hau, bariable globalak erabiltzeko sortu da

// GameTextures joateko
typedef struct GameTextures GameTextures;
// SDL-ko gauzak:
extern SDL_Event event;

// Gure pertsonaiak:
extern ENTITY lumen;
extern ENTITY kontsumista;
extern ENTITY zakarra;
extern ENTITY sierra;
extern ENTITY banko;
extern ENTITY smog;

// Gure balak:
extern BALAK bossBala[MAX_BALAK];
extern BALAK lumenBala[MAX_BALAK];
extern BALAK miniBala[3];

// Gure bizitza barra:
extern BIZITZABARRA barraEsk;
extern BIZITZABARRA barraEzk;

// Gure int-ak:
extern int coolDownDisparo;

// Gure jokoaren egoera:
extern GAMESTATE estadoActual;
extern BOSS bossAhora;

// Gure Texturak:
extern GameTextures texturas;

// Funtzioa:
void Limpieza(SDL_Renderer *renderer, SDL_Window *window);
#endif