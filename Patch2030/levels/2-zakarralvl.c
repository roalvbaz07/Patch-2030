#include "levels.h"

// Zakarraren baroiaren nibelaren funtzioa
int zakarralvl(SDL_Renderer *renderer, SDL_Window *window)
{
    int quitlvl = 0;
    int gameOver = 0;

    lumen.x = LUMEN_X_ZAKARRA;
    lumen.y = SUELO_ZAKARRA;
    lumen.bizitza = LUMEN_BIZITZA;

    zakarra.bizitza = 25;

    barraEsk.maxVida = zakarra.bizitza;
    barraEzk.maxVida = lumen.bizitza;

    SDL_ShowCursor(SDL_DISABLE);

    // Reset Balak
    balakHasieratu();

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
        pertsonaiaUpdate(SUELO_ZAKARRA);

        etsaiaUpdate();
        bossDisparar();

        balenKolisioa(&lumen, bossBala, 32, 32);
        balenKolisioa(&zakarra, lumenBala, 32, 32);
        bossKolisioa(&zakarra);

        balakEguneratu(1, bossBala, 1);
        balakEguneratu(1, lumenBala, 0);

        if (lumen.bizitza <= 0 && quitlvl != 1)
        {
            quitlvl = 1;
            gameOver = 1;
        }
        if (zakarra.bizitza <= 0 && quitlvl != 1 && lumen.bizitza > 0)
        {
            quitlvl = 1;
            gameOver = 0;
        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texturas.zakarraFont, NULL, NULL);

        pertsonaiaMarraztu(&lumen, renderer, texturas.lumen);
        pertsonaiaMarraztu(&zakarra, renderer, texturas.zakarra);

        balakMarraztu(renderer, texturas.zakarraBala, 32, 32, bossBala);
        balakMarraztu(renderer, texturas.lumenBala, 32, 32, lumenBala);

        BarraVida_Render(&barraEsk, texturas.aurpegiZakarra, renderer, zakarra.bizitza);
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