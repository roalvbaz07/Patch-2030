#include "assets/assets.h"
#include "boss/boss.h"
#include "config/config.h"
#include "global.h"
#include "hasiera/hasiera.h"
#include "levels/levels.h"
#include "pertsonaiak/pertsonaia.h"
#include "render/render.h"
#include <SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL_image.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

BALAK bossBala[MAX_BALAK];

BALAK lumenBala[MAX_BALAK];

BALAK miniBala[3];

BIZITZABARRA barraEsk = {
    .x = 1400,
    .y = 100,
    .w = 500,
    .h = 25,
};
BIZITZABARRA barraEzk = {
    .x = 200,
    .y = 100,
    .w = 500,
    .h = 25,
};

int coolDownDisparo = 0;

// Pertsonaiak hasieratzen ditugu
ENTITY lumen = {.x = 50,
                .y = SUELO_ZAKARRA,
                .w = 155,
                .h = 194,
                .spriteW = 155,
                .spriteH = 194,
                .Vx = 6,
                .Vy = 0,
                .direction = 1,
                .bizitza = LUMEN_BIZITZA,
                .saltoIndarra = 25,
                .frame = 0,
                .internalTimer = 0,
                .aireanDago = 0,
                .fasea = 1,
                .unekoEgoera = GELDIK};

ENTITY kontsumista = {.x = 1400,
                      .y = 550,
                      .w = 229,
                      .h = 429,
                      .spriteW = 222,
                      .spriteH = 202,
                      .Vx = 0, // Hasierako abiadura
                      .Vy = 0,
                      .direction = -1,
                      .frame = 0,
                      .bizitza = 20,
                      .saltoIndarra = 0,
                      .internalTimer = 0,
                      .aireanDago = 0,
                      .fasea = 1,
                      .unekoEgoera = GELDIK};

ENTITY zakarra = {.x = 1250,
                  .y = 600,
                  .w = 229,
                  .h = 300,
                  .spriteW = 220,
                  .spriteH = 300,
                  .Vx = 0,
                  .Vy = 4,
                  .direction = -1,
                  .frame = 0,
                  .bizitza = 25,
                  .saltoIndarra = 0,
                  .internalTimer = 0,
                  .aireanDago = 0,
                  .fasea = 0,
                  .unekoEgoera = MUGITZEN};

ENTITY sierra = {.x = 1250,
                 .y = 375,
                 .w = 275,
                 .h = 400,
                 .spriteW = 270,
                 .spriteH = 325,
                 .Vx = 0,
                 .Vy = 4,
                 .direction = -1,
                 .frame = 0,
                 .bizitza = SIERRA_BIZITZA,
                 .saltoIndarra = 0,
                 .internalTimer = 0,
                 .aireanDago = 0,
                 .fasea = 0,
                 .unekoEgoera = MUGITZEN};

ENTITY banko = {.x = 1400,
                .y = 360,
                .w = 300,
                .h = 600,
                .spriteW = 250,
                .spriteH = 258,
                .Vx = 0,
                .Vy = 0,
                .direction = -1,
                .frame = 0,
                .bizitza = BANKO_BIZITZA,
                .saltoIndarra = 0,
                .internalTimer = 0,
                .aireanDago = 0,
                .fasea = 0,
                .unekoEgoera = MUGITZEN};

ENTITY smog = {.x = 0,
               .y = 400,
               .w = 800,
               .h = 600,
               .spriteW = 306,
               .spriteH = 203,
               .Vx = 0,
               .Vy = 0,
               .direction = 1,
               .frame = 0,
               .bizitza = SMOG_BIZITZA,
               .saltoIndarra = 0,
               .internalTimer = 0,
               .aireanDago = 0,
               .fasea = 0,
               .unekoEgoera = GELDIK};

GAMESTATE estadoActual;

BOSS bossAhora;

SDL_Event event;

int main(int argc, char *argv[])
{
    // SetProcessDPIAware();

    SDL_SetHint(SDL_HINT_WINDOWS_DPI_AWARENESS, "permonitorv2");

    estadoActual = INTRO;

    balakHasieratu();

    int quit = 0;
    int retry = 0;
    int decision = 0;

    // --- CARGA DE RECURSOS ---

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    hasiera(&window, &renderer); // Tu función de inicio

    SDL_Texture *inicio = IMG_LoadTexture(renderer, "img/intro.png");

    // Creamos la estructura
    texturas_Cargar_Con_Pantalla(renderer, inicio); // Cargamos todo de golpe

    SDL_ShowCursor(SDL_DISABLE);

    // --- BUCLE DEL JUEGO ---
    while (!quit)
    {
        switch (estadoActual)
        {
        case INTRO:
            Intro(renderer, window);
            estadoActual = MENUA;
            break;

        case MENUA:
            Menu(renderer, window);
            estadoActual = MAPA;
            bossAhora = BOSS_KONTSUMO;
            break;
        case MAPA:
            mapa(renderer, window);
            if (bossAhora != BOSS_FINAL)
            {
                estadoActual = MINIMENU;
            }
            if (bossAhora == BOSS_FINAL)
            {
                bossAhora = KONTSUMO;
                estadoActual = MENUA;
            }
            break;
        case MINIMENU:
            int itzuli;
            itzuli = introBoss(renderer, window);
            if (itzuli == 1)
            {
                estadoActual = MAPA;
                break;
            }
            else
            {
                switch (bossAhora)
                {
                case BOSS_KONTSUMO:
                    estadoActual = KONTSUMO;
                    break;
                case BOSS_ZAKARRA:
                    estadoActual = ZAKARRA;
                    break;
                case BOSS_SIERRA:
                    estadoActual = SIERRA;
                    break;
                case BOSS_BANKO:
                    estadoActual = BANKO;
                    break;
                case BOSS_SMOG:
                    estadoActual = SMOG;
                    break;
                case BOSS_FINAL:
                    estadoActual = MENUA;
                    break;
                }
            }
            break;
        case KONTSUMO:

            retry = kontsumistalvl(renderer, window);
            if (!retry)
            {
                victory(renderer, window);
                bossAhora++;
                estadoActual = MAPA;
            }
            else
            {
                decision = gameOver(renderer, window);
                if (decision == 0) // Jokotik Atera (Exit)
                {
                    quit = 1;
                }
                else
                {
                    lumen.bizitza = LUMEN_BIZITZA;
                    kontsumista.bizitza = KONTSUMISTA_BIZITZA;
                    kontsumista.fasea = 1;
                }
            }
            break;

        case ZAKARRA:
            retry = zakarralvl(renderer, window);
            if (!retry)
            {
                victory(renderer, window);
                bossAhora++;
                estadoActual = MAPA;
            }
            else
            {
                decision = gameOver(renderer, window);
                if (decision == 0) // Jokotik Atera (Exit)
                {
                    quit = 1;
                }
                else
                {
                    lumen.bizitza = LUMEN_BIZITZA;
                    zakarra.bizitza = 25;
                }
            }
            break;
        case SIERRA:

            retry = sierralvl(renderer, window);
            if (!retry)
            {
                victory(renderer, window);
                bossAhora++;
                estadoActual = MAPA;
            }
            else
            {
                decision = gameOver(renderer, window);
                if (decision == 0) // Jokotik Atera (Exit)
                {
                    quit = 1;
                }
                else
                {
                    lumen.bizitza = LUMEN_BIZITZA;
                    sierra.bizitza = SIERRA_BIZITZA;
                }
            }
            break;
        case BANKO:
            retry = bankolvl(renderer, window);
            if (!retry)
            {
                victory(renderer, window);
                bossAhora++;
                estadoActual = MAPA;
            }
            else
            {
                decision = gameOver(renderer, window);
                if (decision == 0) // Jokotik Atera (Exit)
                {
                    quit = 1;
                }
                else
                {
                    lumen.bizitza = LUMEN_BIZITZA;
                    banko.bizitza = BANKO_BIZITZA;
                }
            }
            break;
        case SMOG:

            retry = smoglvl(renderer, window);
            if (!retry)
            {
                victory(renderer, window);
                bossAhora++;
                estadoActual = MAPA;
            }
            else
            {
                decision = gameOver(renderer, window);
                if (decision == 0) // Jokotik Atera (Exit)
                {
                    quit = 1;
                }
                else
                {
                    lumen.bizitza = 3;
                    smog.bizitza = 300;
                }
            }
            break;
        }
    }

    // --- LIMPIEZA (NUEVO) --  -
    Limpieza(renderer, window);
    return 0;
}

void Limpieza(SDL_Renderer *renderer, SDL_Window *window)
{
    texturas_Limpiar();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(0);
}