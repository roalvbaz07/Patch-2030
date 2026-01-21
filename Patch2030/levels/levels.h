#ifndef LEVEL_H
#define LEVEL_H

#include "../assets/assets.h"
#include "../boss/boss.h"
#include "../config/config.h"
#include "../fisikak/fisikak.h"
#include "../global.h"
#include "../hasiera/hasiera.h"
#include "../pertsonaiak/pertsonaia.h"
#include "../render/render.h"
#include <SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL_image.h>
#include <math.h>

void Intro(SDL_Renderer *renderer, SDL_Window *window);

void Menu(SDL_Renderer *renderer, SDL_Window *window);

int introBoss(SDL_Renderer *renderer, SDL_Window *window);

void mapa(SDL_Renderer *renderer, SDL_Window *window);

int kontsumistalvl(SDL_Renderer *renderer, SDL_Window *window);

int zakarralvl(SDL_Renderer *renderer, SDL_Window *window);

int sierralvl(SDL_Renderer *renderer, SDL_Window *window);

int bankolvl(SDL_Renderer *renderer, SDL_Window *window);

int smoglvl(SDL_Renderer *renderer, SDL_Window *window);

int gameOver(SDL_Renderer *renderer, SDL_Window *window);

void victory(SDL_Renderer *renderer, SDL_Window *window);

#endif