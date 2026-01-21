#include "hasiera.h"

void hasiera(SDL_Window **window, SDL_Renderer **renderer)
{

    // 1. SDL Hasieratu
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        // SDL no pudo inicializarse.
        return;
    }

    // 2. Lehioa sortzen dugu
    *window = SDL_CreateWindow("Patch 2030", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
                               SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (*window == NULL)
    {
        // No se pudo crear la ventana.
        SDL_Quit();
        return;
    }

    // 3. Renderizatzailea sortzen dugu
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC);

    if (*renderer == NULL)
    {
        // No se pudo crear el renderer.
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return;
    }

    // 4. Argazkien libreria arrankatzen dugu
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {

        // No se pudo inicializar SDL_image
    }
}