#include "fisikak.h"
#include <SDL.h> // Para SDL_HasIntersection y SDL_Rect
#include <stdio.h>

void balenKolisioa(ENTITY *jasotzailea, BALAK *balak, int w, int h)
{
    // DEKLARAZIOAK
    int i;
    SDL_Rect rectjasotzailea = {
        .x = jasotzailea->x,
        .y = jasotzailea->y,
        .w = jasotzailea->w,
        .h = jasotzailea->h,
    };
    SDL_Rect rectBala;

    // 3. LÓGICA DEL BUCLE
    // Fíjate que ahora la 'i' ya existe, solo la ponemos a 0
    for (i = 0; i < MAX_BALAK; i++)
    {
        if (balak[i].aktibo)
        {
            rectBala.x = (int)balak[i].x;
            rectBala.y = (int)balak[i].y;
            rectBala.w = w;
            rectBala.h = h;

            // (int) float denez, pixelera pasatzeko int derrigorrez izan behar da.

            if (SDL_HasIntersection(&rectjasotzailea, &rectBala))
            {
                // Acción al chocar
                balak[i].aktibo = 0;
                jasotzailea->bizitza -= 1;
                printf("KOLISIOA! Lumen bizitza: %d\n", jasotzailea->bizitza);
            }
        }
    }
}

void bossKolisioa(ENTITY *boss)
{
    // Lumenen kolisioaren karratu imaginarioa sortzen dugu
    SDL_Rect rectlumen = {
        .x = lumen.x,
        .y = lumen.y,
        .w = lumen.w,
        .h = lumen.h,
    };

    // Bossaren kolisioaren karratu imaginarioa sortzen dugu
    SDL_Rect rectBoss = {
        .x = boss->x,
        .y = boss->y,
        .w = boss->w,
        .h = boss->h,
    };

    if (SDL_HasIntersection(&rectlumen, &rectBoss))
    {
        // Lumenek bizitza bat galtzen du
        lumen.bizitza -= 1;

        // Tokiz desplazatzen dugu, bossaren posizioaren eta haren posizioaren arabera
        if ((lumen.x) < (boss->x))
        {
            lumen.x -= 100;
        }
        else
        {
            lumen.x += 100;
        }
    }
}