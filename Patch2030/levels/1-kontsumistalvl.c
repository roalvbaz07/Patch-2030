#include "levels.h"

int kontsumistalvl(SDL_Renderer *renderer, SDL_Window *window)
{
    int quitlvl = 0;
    int gameOver = 0;

    lumen.y = SUELO_KONTSUMISTA;

    kontsumista.unekoEgoera = GELDIK;

    barraEsk.maxVida = kontsumista.bizitza;
    barraEzk.maxVida = lumen.bizitza;

    balakHasieratu();
    SDL_ShowCursor(SDL_DISABLE);

    while (quitlvl != 1)
    {
        while (kontsumista.fasea == 1 && !quitlvl)
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
            // --- UPDATE ---
            kontsumistaUpdate();
            pertsonaiaUpdate(SUELO_KONTSUMISTA);

            // --- DISPAROS kontsumista (KONTSUMISTA) ---
            // 1. Crear balas
            kontsumistaDisparar();

            // 2. ColisiónbossBala -> Lumen

            balenKolisioa(&lumen, bossBala, 24, 24);
            balenKolisioa(&kontsumista, lumenBala, 32, 15);
            bossKolisioa(&kontsumista);

            balakEguneratu(1, bossBala, 0);
            balakEguneratu(1, lumenBala, 0);

            if (kontsumista.bizitza <= 0 && kontsumista.fasea == 1)
            {
                kontsumista.fasea = 2;
                kontsumista.bizitza = 400;
                balakHasieratu();
            }
            if (lumen.bizitza <= 0)
            {
                quitlvl = 1;
                gameOver = 1;
            }
            // --- RENDERIZADO (DIBUJAR) ---
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            // Fondoa marraztu
            SDL_RenderCopy(renderer, texturas.kontsumistaFont, NULL, NULL);
            // 2. DIBUJAR PERSONAJES
            pertsonaiaMarraztu(&lumen, renderer, texturas.lumen);
            pertsonaiaMarraztu(&kontsumista, renderer, texturas.kontsumista);

            balakMarraztu(renderer, texturas.kontsumistaBala, 32, 32, bossBala);
            balakMarraztu(renderer, texturas.lumenBala, 32, 15, lumenBala);

            BarraVida_Render(&barraEsk, texturas.aurpegiKontsumista, renderer, kontsumista.bizitza);
            BarraVida_Render(&barraEzk, texturas.aurpegiLumen, renderer, lumen.bizitza);

            SDL_RenderPresent(renderer);

            // Pasatako denbora kalkulatzen dugu
            int pasatakoDenbora = SDL_GetTicks() - hasierakoDenbora;

            // Azkarregi jun ba gea itxoiten dugu
            if (pasatakoDenbora < 33)
            {
                SDL_Delay(33 - pasatakoDenbora);
            }
            kontsumista.internalTimer++;
        }
        while (kontsumista.fasea == 2 && quitlvl != 0)
        {
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

            // --- UPDATE ---
            kontsumistaUpdate();
            pertsonaiaUpdate(SUELO_KONTSUMISTA);

            // --- DISPAROS kontsumista (KONTSUMISTA) ---
            // 1. Crear balas
            kontsumistaDisparar();

            // 2. ColisiónbossBala -> Lumen

            balenKolisioa(&lumen, bossBala, 16, 16);
            balenKolisioa(&kontsumista, lumenBala, 32, 15);
            bossKolisioa(&kontsumista);

            balakEguneratu(1, bossBala, 0);
            balakEguneratu(1, lumenBala, 0);

            if (kontsumista.bizitza <= 0 && quitlvl != 1 && kontsumista.fasea == 2 && lumen.bizitza > 0)
            {
                quitlvl = 1;
                gameOver = 0;
            }

            if (lumen.bizitza <= 0)
            {
                quitlvl = 1;
                gameOver = 1;
            }

            // --- RENDERIZADO (DIBUJAR) ---
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            // Fondoa marraztu
            SDL_RenderCopy(renderer, texturas.kontsumistaFont, NULL, NULL);
            // 2. DIBUJAR PERSONAJES
            pertsonaiaMarraztu(&lumen, renderer, texturas.lumen);
            pertsonaiaMarraztu(&kontsumista, renderer, texturas.kontsumista2);

            balakMarraztu(renderer, texturas.kontsumistaBala2, 80, 80, bossBala);
            balakMarraztu(renderer, texturas.lumenBala, 32, 15, lumenBala);

            BarraVida_Render(&barraEsk, texturas.aurpegiKontsumista, renderer, kontsumista.bizitza);
            BarraVida_Render(&barraEzk, texturas.aurpegiLumen, renderer, lumen.bizitza);

            SDL_RenderPresent(renderer);

            // Pasatako denbora kalkulatzen dugu
            int pasatakoDenbora = SDL_GetTicks() - hasierakoDenbora;

            // Azkarregi jun ba gea itxoiten dugu
            if (pasatakoDenbora < 33)
            {
                SDL_Delay(33 - pasatakoDenbora);
            }
            if (kontsumista.fasea == 2)
            {
                kontsumista.bizitza--;
            }
        }
    }
    return gameOver;
}