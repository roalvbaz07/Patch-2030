#ifndef RENDER_H
#define RENDER_H

// ==== INCLUDEAK ====
#include "../config/config.h"
#include <SDL.h>
#include <stdio.h>

//==== ETXERN ====

// ==== FUNTZIOAK ====
void pertsonaiaMarraztu(ENTITY *p, SDL_Renderer *renderer, SDL_Texture *textura);
void balakMarraztu(SDL_Renderer *renderer, SDL_Texture *textura, int w, int h, BALAK *balak);
void BarraVida_Render(BIZITZABARRA *barra, SDL_Texture *textura, SDL_Renderer *renderer, int vida);

#endif