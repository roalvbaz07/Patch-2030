#ifndef BOSS2_H
#define BOSS2_H

// ==== INCLUDEAK ====

#include "../config/config.h"
#include "../global.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

// ==== FUNTZIOAK ====

// KONTSUMISTAREN FUNTZIOAK
void kontsumistaDisparar();
void kontsumistaUpdate();

// ZAKARRAREN FUNTZIOAK
void etsaiaUpdate();
void bossDisparar();

// SIERRAREN FUNTZIOAK
void sierraUpdate();
void sierraDisparar();
void eguneratuAizkorak();

// BANKOREN FUNTZIOAK
void etsaiaUpdateBanko();
void bossDispararBanko();
void balakEguneratuBanko();
// SMOG-REN FUNTZIOAK
void SmogBizitzaDisparo();
void SmogDisparo(float abiadura);
void smogUpdate();

#endif
