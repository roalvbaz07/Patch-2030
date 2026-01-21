#include "levels.h"

int smoglvl(SDL_Renderer *renderer, SDL_Window *window)
{
    int quit = 0;
    int gameOver = 0;

    lumen.x = LUMEN_X_SMOG;
    lumen.y = SUELO_SMOG;
    lumen.saltoIndarra = 27;
    lumen.bizitza = LUMEN_BIZITZA;

    smog.bizitza = SMOG_BIZITZA;

    barraEzk.maxVida = smog.bizitza;
    barraEsk.maxVida = lumen.bizitza;

    balakHasieratu();

    SDL_ShowCursor(SDL_DISABLE);

    while (!quit)
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

        pertsonaiaUpdate(SUELO_SMOG);

        smogUpdate();
        SmogBizitzaDisparo();

        balenKolisioa(&lumen, bossBala, 64, 64);
        balenKolisioa(&smog, lumenBala, 32, 32);

        bossKolisioa(&smog);

        balakEguneratu(1, bossBala, 0);
        balakEguneratu(1, lumenBala, 0);
        if (lumen.bizitza <= 0)
        {
            // Lumen hila dago! Nibela amaitu da.
            quit = 1;
            gameOver = 1;
        }
        if (lumen.bizitza > 0 && !quit && smog.bizitza <= 0)
        {
            // Lumen hila dago! Nibela amaitu da.
            quit = 1;
            gameOver = 0;
        }

        // --- RENDERIZADO ---

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (texturas.zakarraFont != NULL)
        {
            SDL_RenderCopy(renderer, texturas.smogFont, NULL, NULL);
        }

        pertsonaiaMarraztu(&lumen, renderer, texturas.lumen);
        pertsonaiaMarraztu(&smog, renderer, texturas.smog);

        balakMarraztu(renderer, texturas.smogBala, 100, 80, bossBala);
        balakMarraztu(renderer, texturas.lumenBala, 32, 32, lumenBala);

        BarraVida_Render(&barraEzk, texturas.aurpegiSmog, renderer, smog.bizitza);
        BarraVida_Render(&barraEsk, texturas.aurpegiLumen, renderer, lumen.bizitza);

        SDL_RenderPresent(renderer);
        // Pasatako denbora kalkulatzen dugu
        int pasatakoDenbora = SDL_GetTicks() - hasierakoDenbora;

        // Azkarregi jun ba gea itxoiten dugu
        if (pasatakoDenbora < 33)
        {
            SDL_Delay(33 - pasatakoDenbora);
        }
    }
    lumen.Vx = 0;
    return gameOver;
}