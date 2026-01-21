#include "levels.h"

int sierralvl(SDL_Renderer *renderer, SDL_Window *window)
{
    int quitlvl = 0;
    int GameOver = 0;

    SDL_ShowCursor(SDL_DISABLE);

    lumen.bizitza = 3;
    lumen.x = LUMEN_X_SIERRA;
    lumen.y = SUELO_SIERRA;
    lumen.saltoIndarra = LUMEN_SALTO_SIERRA;

    sierra.bizitza = 25;
    sierra.internalTimer = 0;
    sierra.unekoEgoera = MUGITZEN;

    barraEsk.maxVida = sierra.bizitza;
    barraEzk.maxVida = lumen.bizitza;

    // Reset Balak
    balakHasieratu();

    SDL_ShowCursor(SDL_DISABLE);

    while (quitlvl != 1)
    {
        // Hasierako denbora lortuko dugu
        int hasierakoDenbora = SDL_GetTicks();

        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                Limpieza(renderer, window);
            }
            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
            {
                Limpieza(renderer, window);
            }
            pertsonaiaHandleEvent();
        }

        // UPDATE
        sierraUpdate();
        pertsonaiaUpdate(SUELO_SIERRA);
        sierraDisparar();

        balenKolisioa(&lumen, bossBala, 32, 32);
        balenKolisioa(&sierra, lumenBala, 32, 32);
        bossKolisioa(&sierra);

        eguneratuAizkorak();
        balakEguneratu(1, lumenBala, 0);

        // BUKAERAK
        if (lumen.bizitza <= 0 && quitlvl != 1)
        {
            // GAME OVER
            quitlvl = 1;
            GameOver = 1;
        }
        if (sierra.bizitza <= 0 && quitlvl != 1 && lumen.bizitza > 0)
        {
            // YOU WIN

            quitlvl = 1;
            GameOver = 0;
        }
        // RENDER
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (texturas.sierraFont != NULL)
        {
            SDL_RenderCopy(renderer, texturas.sierraFont, NULL, NULL);
        }

        pertsonaiaMarraztu(&lumen, renderer, texturas.lumen);
        pertsonaiaMarraztu(&sierra, renderer, texturas.sierra);

        // GARRANTZITSUA: Ziurtatu balakMarraztu-k frame-a erabiltzen duela
        balakMarraztu(renderer, texturas.sierraBala, 64, 64, bossBala);
        balakMarraztu(renderer, texturas.lumenBala, 32, 15, lumenBala);

        BarraVida_Render(&barraEsk, texturas.aurpegiSierra, renderer, sierra.bizitza);
        BarraVida_Render(&barraEzk, texturas.aurpegiLumen, renderer, lumen.bizitza);

        SDL_RenderPresent(renderer);
        // Pasatako denbora kalkulatzen dugu
        int pasatakoDenbora = SDL_GetTicks() - hasierakoDenbora;

        // Azkarregi jun ba gea itxoiten dugu
        if (pasatakoDenbora < 33)
        {
            SDL_Delay(33 - pasatakoDenbora);
        }
    }
    return GameOver;
}