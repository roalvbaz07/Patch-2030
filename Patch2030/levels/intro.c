#include "levels.h"

void Intro(SDL_Renderer *renderer, SDL_Window *window)
{
    int running = 1;
    int argazki = 1;

    // 1. VERIFICACIÓN DE CARGA (Importante)
    if (texturas.story == NULL)
    {
        // ERROR: La textura 'story' (1) es NULL.
    }
    if (texturas.kontrolak == NULL)
    {
        // ERROR: La textura 'kontrolak' (2) es NULL.
    }

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                Limpieza(renderer, window);
            }

            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    Limpieza(renderer, window);
                }

                if (event.key.keysym.sym == SDLK_RETURN)
                {
                    // Solo actuar si no es un "eco" de la tecla (evita saltos dobles)
                    if (event.key.repeat == 0)
                    {
                        argazki += 1;
                        // Tecla pulsada. Nuevo valor de argazki

                        // Si ya pasamos la foto 2, salimos
                        if (argazki > 2)
                        {
                            // Saliendo del Intro...
                            running = 0;
                        }
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // --- RENDER ---
        if (argazki == 1)
        {
            if (texturas.story != NULL)
            {
                SDL_RenderCopy(renderer, texturas.story, NULL, NULL);
            }
        }
        else if (argazki == 2)
        {
            // Aquí es donde probablemente falla si la textura no existe
            if (texturas.kontrolak != NULL)
            {
                SDL_RenderCopy(renderer, texturas.kontrolak, NULL, NULL);
            }
            else
            {
                // INTENTO DE RENDERIZAR IMAGEN 2 PERO ES NULL
            }
        }

        SDL_RenderPresent(renderer);
    }
    SDL_ShowCursor(SDL_DISABLE);
}