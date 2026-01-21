#include "levels.h"

void victory(SDL_Renderer *renderer, SDL_Window *window)
{
    int running = 1;

    SDL_ShowCursor(SDL_ENABLE);
    // Definimos botones
    SDL_Rect btnSiguiente = {805, 710, 400, 350};

    while (running)
    {
        int mx, my;
        SDL_GetMouseState(&mx, &my);
        // --- INPUT ---
        while (SDL_PollEvent(&event))
        {

            if (event.type == SDL_QUIT)
            {
                Limpieza(renderer, window); // Jokoa osorik ixten dugu
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    Limpieza(renderer, window); // Jokoa osorik ixten dugu
                }
            }

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    // Click en RETRY
                    if (mx >= btnSiguiente.x && mx <= (btnSiguiente.x + btnSiguiente.w) && my >= btnSiguiente.y &&
                        my <= (btnSiguiente.y + btnSiguiente.h))
                    {
                        running = 0;
                    }
                }
            }
        }
        // --- RENDER ---
        // 1. Fondo Rojo semitransparente (simulado con gris rojizo)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        switch (bossAhora)
        {
        case BOSS_KONTSUMO:
            SDL_RenderCopy(renderer, texturas.kontsumistaV, NULL, NULL);
            break;
        case BOSS_ZAKARRA:
            SDL_RenderCopy(renderer, texturas.zakarraV, NULL, NULL);
            break;
        case BOSS_SIERRA:
            SDL_RenderCopy(renderer, texturas.sierraV, NULL, NULL);
            break;
        case BOSS_BANKO:
            SDL_RenderCopy(renderer, texturas.bankoV, NULL, NULL);
            break;
        case BOSS_SMOG:
            SDL_RenderCopy(renderer, texturas.smogV, NULL, NULL);
            break;
        case BOSS_FINAL:
            break;
        }

        SDL_RenderPresent(renderer);
    }
}
