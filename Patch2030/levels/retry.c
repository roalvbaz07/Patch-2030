#include "levels.h"
#include <stdio.h>

int gameOver(SDL_Renderer *renderer, SDL_Window *window)
{
    int running = 1;
    int opcion = 0; // 0 = Salir, 1 = Retry

    SDL_ShowCursor(SDL_ENABLE);
    // Definimos botones
    SDL_Rect btnRetry = {800, 850, 330, 200};

    while (running)
    {
        int mx, my;
        SDL_GetMouseState(&mx, &my);
        // --- INPUT ---
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
            }

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {

                    // Click en RETRY
                    if (mx >= btnRetry.x && mx <= (btnRetry.x + btnRetry.w) && my >= btnRetry.y &&
                        my <= (btnRetry.y + btnRetry.h))
                    {
                        opcion = 1;
                        running = 0;
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        switch (bossAhora)
        {
        case BOSS_KONTSUMO:
            SDL_RenderCopy(renderer, texturas.kontsumistaD, NULL, NULL);
            break;
        case BOSS_ZAKARRA:
            SDL_RenderCopy(renderer, texturas.zakarraD, NULL, NULL);
            break;
        case BOSS_SIERRA:
            SDL_RenderCopy(renderer, texturas.sierraD, NULL, NULL);
            break;
        case BOSS_BANKO:
            SDL_RenderCopy(renderer, texturas.bankoD, NULL, NULL);
            break;
        case BOSS_SMOG:
            SDL_RenderCopy(renderer, texturas.smogD, NULL, NULL);
            break;
        case BOSS_FINAL:
            break;
        }

        SDL_RenderPresent(renderer);
    }

    return opcion;
}