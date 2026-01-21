#include "render.h"
#include <SDL_image.h>

void pertsonaiaMarraztu(ENTITY *p, SDL_Renderer *renderer, SDL_Texture *textura)
{

    SDL_Rect argazkiarenZatia = {
        .x = p->frame * p->spriteW,
        .y = 0,
        .w = p->spriteW,
        .h = p->spriteH,
    };

    SDL_Rect jokoarenZatia = {
        .x = p->x,
        .y = p->y,
        .w = p->w,
        .h = p->h,
    };

    SDL_RendererFlip flip = (p->direction == -1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer, textura, &argazkiarenZatia, &jokoarenZatia, 0, NULL, flip);
}

// Función auxiliar para actualizar balas (puedes ponerla antes del main o en otro archivo)
void balakMarraztu(SDL_Renderer *renderer, SDL_Texture *textura, int w, int h, BALAK *balak)
{
    // Usamos la variable global 'balak' que definiste como extern en config.h
    for (int i = 0; i < MAX_BALAK; i++)
    {
        if (balak[i].aktibo)
        {
            SDL_Rect Bala = {
                .x = (int)balak[i].x,
                .y = (int)balak[i].y,
                .w = w,
                .h = h,
            };

            SDL_RenderCopy(renderer, textura, NULL, &Bala);
        }
    }
}

void BarraVida_Render(BIZITZABARRA *barra, SDL_Texture *textura, SDL_Renderer *renderer, int vida)
{
    if (barra == NULL || renderer == NULL)
    {
        return;
    }

    SDL_Rect rectAurpegi = {
        .w = 55,
        .h = 55,
        .x = barra->x - 75,
        .y = barra->y - 5,
    };

    // Clampear vida entre 0 y maxVida para dibujo
    if (vida < 0)
    {
        vida = 0;
    }
    if (vida > barra->maxVida)
    {
        vida = barra->maxVida;
    }

    // Calcular porcentaje
    float porcentaje = (float)vida / (float)barra->maxVida;
    int wActual = (int)(barra->w * porcentaje);
    float hiltzekoArriskua = (float)barra->maxVida * 0.25;

    SDL_Rect bgRect = {barra->x, barra->y, barra->w, barra->h};
    SDL_Rect fgRect = {barra->x, barra->y, wActual, barra->h};

    // Fondo gris oscuro
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderFillRect(renderer, &bgRect);

    if ((vida <= hiltzekoArriskua) || vida <= 1)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    }
    SDL_RenderFillRect(renderer, &fgRect);

    // Borde negro
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &bgRect);

    SDL_RenderCopy(renderer, textura, NULL, &rectAurpegi);
}