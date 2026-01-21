#ifndef ASSETS_H
#define ASSETS_H

#include "../global.h"
#include <SDL.h>
// Estructura que agrupa todas tus texturas
typedef struct GameTextures
{

    SDL_Texture *fondomenu; // 0
    SDL_Texture *lumen;     // 1
    SDL_Texture *lumenBala; // 2

    SDL_Texture *mapaKontsumista;  // 3
    SDL_Texture *menuKontsumista;  // 4
    SDL_Texture *kontsumistaFont;  // 5
    SDL_Texture *kontsumista;      // 6
    SDL_Texture *kontsumista2;     // 7
    SDL_Texture *kontsumistaBala;  // 8
    SDL_Texture *kontsumistaBala2; // 9
    SDL_Texture *kontsumistaV;     // 10
    SDL_Texture *kontsumistaD;     // 11

    SDL_Texture *mapaZakarra; // 12
    SDL_Texture *menuZakarra; // 13
    SDL_Texture *zakarraFont; // 14
    SDL_Texture *zakarra;     // 15
    SDL_Texture *zakarraBala; // 16
    SDL_Texture *zakarraV;    // 17
    SDL_Texture *zakarraD;    // 18

    SDL_Texture *mapaSierra; // 19
    SDL_Texture *menuSierra; // 20
    SDL_Texture *sierraFont; // 21
    SDL_Texture *sierra;     // 22
    SDL_Texture *sierraBala; // 23
    SDL_Texture *sierraV;    // 24
    SDL_Texture *sierraD;    // 25

    SDL_Texture *mapaBanko;     // 26
    SDL_Texture *menuBanko;     // 27
    SDL_Texture *bankoFont;     // 28
    SDL_Texture *banko;         // 29
    SDL_Texture *bankoBala;     // 30
    SDL_Texture *bankoMiniBala; // 31
    SDL_Texture *bankoV;        // 32
    SDL_Texture *bankoD;        // 33

    SDL_Texture *mapaSmog; // 34
    SDL_Texture *menuSmog; // 35
    SDL_Texture *smogFont; // 36
    SDL_Texture *smog;     // 37
    SDL_Texture *smogBala; // 38
    SDL_Texture *smogV;    // 39
    SDL_Texture *smogD;    // 40

    SDL_Texture *mapaFinal; // 41

    SDL_Texture *aurpegiKontsumista; // 42
    SDL_Texture *aurpegiZakarra;     // 43
    SDL_Texture *aurpegiSierra;      // 44
    SDL_Texture *aurpegiBanko;       // 45
    SDL_Texture *aurpegiSmog;        // 46
    SDL_Texture *aurpegiLumen;       // 47

    SDL_Texture *story;     // 48
    SDL_Texture *kontrolak; // 49

} GameTextures;

// funciones
void texturas_Cargar_Con_Pantalla(SDL_Renderer *renderer, SDL_Texture *fondoIntro);
void DibujarBarraProgreso(SDL_Renderer *renderer, SDL_Texture *fondo, int paso, int total);
void texturas_Limpiar();

#endif