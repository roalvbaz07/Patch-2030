#include "levels.h"

int bankolvl(SDL_Renderer *renderer, SDL_Window *window)
{

    int quitlvl = 0;
    int gameOver = 0;

    // Hasierako posizioa
    lumen.x = 200;
    lumen.y = LUMEN_SUELO_BANKO;
    lumen.aireanDago = 0; // Erori dadin
    lumen.Vy = 0;

    barraEsk.maxVida = banko.bizitza;
    barraEzk.maxVida = lumen.bizitza;

    // Reset Balak
    balakHasieratu();

    SDL_ShowCursor(SDL_DISABLE);
    while (quitlvl != 1)
    {
        banko.internalTimer++;
        // Hasierako denbora lortuko dugu
        int hasierakoDenbora = SDL_GetTicks();

        while (SDL_PollEvent(&event) != 0)
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
            pertsonaiaHandleEvent();
        }
        etsaiaUpdateBanko();
        pertsonaiaUpdate(LUMEN_SUELO_BANKO);
        bossDispararBanko();

        balenKolisioa(&lumen, bossBala, 32, 32);
        balenKolisioa(&lumen, miniBala, 32, 32);
        balenKolisioa(&banko, lumenBala, 32, 32);
        bossKolisioa(&banko);

        balakEguneratuBanko();
        balakEguneratu(1, lumenBala, 0);

        if (lumen.bizitza <= 0 && quitlvl != 1)
        {
            // GAME OVER
            quitlvl = 1;
            gameOver = 1;
        }
        if (banko.bizitza <= 0 && quitlvl != 1 && lumen.bizitza > 0)
        {
            // BOSSA GAINDITU DUZU!
            quitlvl = 1;
        }

        // --- RENDERIZADO ---
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // FONDOA MARRAZTU

        if (texturas.bankoFont != NULL)
        {
            SDL_RenderCopy(renderer, texturas.bankoFont, NULL, NULL);
        }

        // PERTSONAIAK MARRAZTU

        pertsonaiaMarraztu(&lumen, renderer, texturas.lumen);
        pertsonaiaMarraztu(&banko, renderer, texturas.banko);

        balakMarraztu(renderer, texturas.bankoBala, 120, 130, bossBala);
        balakMarraztu(renderer, texturas.bankoMiniBala, 140, 50, miniBala);
        balakMarraztu(renderer, texturas.lumenBala, 32, 15, lumenBala);

        BarraVida_Render(&barraEsk, texturas.aurpegiBanko, renderer, banko.bizitza);
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

    return gameOver;
}