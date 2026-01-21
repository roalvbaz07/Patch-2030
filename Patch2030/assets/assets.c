#include "assets.h"
#include <SDL_image.h>

GameTextures texturas;
// Función auxiliar privada para no repetir código
static SDL_Texture *CargarImagen(SDL_Renderer *renderer, const char *path)
{
    SDL_Texture *tex = IMG_LoadTexture(renderer, path);
    if (!tex)
    {
        // ERROR cargando texturas
    }
    return tex;
}
// Función auxiliar para dibujar la barra (Privada para este archivo)
void DibujarBarraProgreso(SDL_Renderer *renderer, SDL_Texture *fondo, int paso, int total)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // 1. Dibujar el fondo (Intro)
    if (fondo)
    {
        SDL_RenderCopy(renderer, fondo, NULL, NULL);
    }

    // 2. Calcular dimensiones de la barra
    int anchoPantalla = 1920; // O usa las constantes de config.h si incluyes config.h
    int barraW = 800;
    int barraH = 40;
    int barraX = (anchoPantalla - barraW) / 2;
    int barraY = 980; // Abajo de la pantalla
    // 3. Dibujar borde de la barra (Blanco)
    SDL_Rect rectBorde = {barraX, barraY, barraW, barraH};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rectBorde);

    // 4. Dibujar relleno (Verde)
    float porcentaje = (float)paso / (float)total;
    SDL_Rect rectRelleno = {barraX + 2, barraY + 2, (int)((barraW - 4) * porcentaje), barraH - 4};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rectRelleno);

    // 5. Presentar
    SDL_RenderPresent(renderer);
}

void texturas_Cargar_Con_Pantalla(SDL_Renderer *renderer, SDL_Texture *fondoIntro)
{
    int totalPasos = 49; // NÚMERO TOTAL DE CARGAS (Ajústalo si añades más)
    int i;
    SDL_Event ev;
    for (i = 0; i <= totalPasos; i++)
    {

        // --- 1. PROCESAR EVENTOS (Vital para que no se congele) ---
        while (SDL_PollEvent(&ev))
        {
            if (ev.type == SDL_QUIT)
            {
                exit(0);
            }
        }

        // --- 2. DIBUJAR BARRA ---
        DibujarBarraProgreso(renderer, fondoIntro, i, totalPasos);

        // --- 3. CARGAR EL RECURSO CORRESPONDIENTE ---
        switch (i)
        {
        case 0:
            texturas.fondomenu = CargarImagen(renderer, "img/fondomenu.png");
            break;
        case 1:
            texturas.lumen = CargarImagen(renderer, "img/lumen.png");
            break;
        case 2:
            texturas.lumenBala = CargarImagen(renderer, "img/lumenBala.png");
            break;
        case 3:
            texturas.mapaKontsumista = CargarImagen(renderer, "img/mapaKontsumista.png");
            break;
        case 4:
            texturas.menuKontsumista = CargarImagen(renderer, "img/menuKontsumista.png");
            break;
        case 5:
            texturas.kontsumistaFont = CargarImagen(renderer, "img/kontsumistaFont.png");
            break;
        case 6:
            texturas.kontsumista = CargarImagen(renderer, "img/kontsumista.png");
            break;
        case 7:
            texturas.kontsumista2 = CargarImagen(renderer, "img/kontsumista2.png");
            break;
        case 8:
            texturas.kontsumistaBala = CargarImagen(renderer, "img/kontsumistaBala.png");
            break;
        case 9:
            texturas.kontsumistaBala2 = CargarImagen(renderer, "img/kontsumistaBala2.png");
            break;
        case 10:
            texturas.kontsumistaV = CargarImagen(renderer, "img/kontsumistaV.png");
            break;
        case 11:
            texturas.kontsumistaD = CargarImagen(renderer, "img/kontsumistaD.png");
            break;

        case 12:
            texturas.mapaZakarra = CargarImagen(renderer, "img/mapaZakarra.png");
            break;
        case 13:
            texturas.menuZakarra = CargarImagen(renderer, "img/menuZakarra.png");
            break;
        case 14:
            texturas.zakarraFont = CargarImagen(renderer, "img/zakarraFont.png");
            break;
        case 15:
            texturas.zakarra = CargarImagen(renderer, "img/zakarra.png");
            break;
        case 16:
            texturas.zakarraBala = CargarImagen(renderer, "img/zakarraBala.png");
            break;
        case 17:
            texturas.zakarraV = CargarImagen(renderer, "img/zakarraV.png");
            break;
        case 18:
            texturas.zakarraD = CargarImagen(renderer, "img/zakarraD.png");
            break;

        case 19:
            texturas.mapaSierra = CargarImagen(renderer, "img/mapaSierra.png");
            break;
        case 20:
            texturas.menuSierra = CargarImagen(renderer, "img/menuSierra.png");
            break;
        case 21:
            texturas.sierraFont = CargarImagen(renderer, "img/sierraFont.png");
            break;
        case 22:
            texturas.sierra = CargarImagen(renderer, "img/sierra.png");
            break;
        case 23:
            texturas.sierraBala = CargarImagen(renderer, "img/sierraBala.png");
            break;
        case 24:
            texturas.sierraV = CargarImagen(renderer, "img/sierraV.png");
            break;
        case 25:
            texturas.sierraD = CargarImagen(renderer, "img/sierraD.png");
            break;

        case 26:
            texturas.mapaBanko = CargarImagen(renderer, "img/mapaBanko.png");
            break;
        case 27:
            texturas.menuBanko = CargarImagen(renderer, "img/menuBanko.png");
            break;
        case 28:
            texturas.bankoFont = CargarImagen(renderer, "img/bankoFont.png");
            break;
        case 29:
            texturas.banko = CargarImagen(renderer, "img/banko.png");
            break;
        case 30:
            texturas.bankoBala = CargarImagen(renderer, "img/bankoBala.png");
            break;
        case 31:
            texturas.bankoMiniBala = CargarImagen(renderer, "img/bankoMiniBala.png");
            break;
        case 32:
            texturas.bankoV = CargarImagen(renderer, "img/bankoV.png");
            break;
        case 33:
            texturas.bankoD = CargarImagen(renderer, "img/bankoD.png");
            break;

        case 34:
            texturas.mapaSmog = CargarImagen(renderer, "img/mapaSmog.png");
            break;
        case 35:
            texturas.menuSmog = CargarImagen(renderer, "img/menuSmog.png");
            break;
        case 36:
            texturas.smogFont = CargarImagen(renderer, "img/smogFont.png");
            break;
        case 37:
            texturas.smog = CargarImagen(renderer, "img/smog.png");
            break;
        case 38:
            texturas.smogBala = CargarImagen(renderer, "img/smogBala.png");
            break;
        case 39:
            texturas.smogV = CargarImagen(renderer, "img/smogV.png");
            break;
        case 40:
            texturas.smogD = CargarImagen(renderer, "img/smogD.png");
            break;

        case 41:
            texturas.mapaFinal = CargarImagen(renderer, "img/mapaFinal.png");
            break;

        case 42:
            texturas.aurpegiKontsumista = CargarImagen(renderer, "img/aurpegiKontsumista.png");
            break;
        case 43:
            texturas.aurpegiZakarra = CargarImagen(renderer, "img/aurpegiZakarra.png");
            break;
        case 44:
            texturas.aurpegiSierra = CargarImagen(renderer, "img/aurpegiSierra.png");
            break;
        case 45:
            texturas.aurpegiBanko = CargarImagen(renderer, "img/aurpegiBanko.png");
            break;
        case 46:
            texturas.aurpegiSmog = CargarImagen(renderer, "img/aurpegiSmog.png");
            break;
        case 47:
            texturas.aurpegiLumen = CargarImagen(renderer, "img/aurpegiLumen.png");
            break;
        case 48:
            texturas.story = CargarImagen(renderer, "img/story.png");
            break;
        case 49:
            texturas.kontrolak = CargarImagen(renderer, "img/controls.png");
            break;
        }
    }
}
void texturas_Limpiar()
{
    // 0
    if (texturas.fondomenu)
    {
        SDL_DestroyTexture(texturas.fondomenu);
    }

    // 1-2
    if (texturas.lumen)
    {
        SDL_DestroyTexture(texturas.lumen);
    }
    if (texturas.lumenBala)
    {
        SDL_DestroyTexture(texturas.lumenBala);
    }

    // 3-9 (kontsumista)
    if (texturas.mapaKontsumista)
    {
        SDL_DestroyTexture(texturas.mapaKontsumista);
    }
    if (texturas.mapaKontsumista)
    {
        SDL_DestroyTexture(texturas.mapaKontsumista);
    }
    if (texturas.kontsumistaFont)
    {
        SDL_DestroyTexture(texturas.kontsumistaFont);
    }
    if (texturas.kontsumista)
    {
        SDL_DestroyTexture(texturas.kontsumista);
    }
    if (texturas.kontsumista2)
    {
        SDL_DestroyTexture(texturas.kontsumista2);
    }
    if (texturas.kontsumistaBala)
    {
        SDL_DestroyTexture(texturas.kontsumistaBala);
    }
    if (texturas.kontsumistaBala2)
    {
        SDL_DestroyTexture(texturas.kontsumistaBala2);
    }
    // 11-12
    if (texturas.kontsumistaV)
    {
        SDL_DestroyTexture(texturas.kontsumistaV);
    }
    if (texturas.kontsumistaD)
    {
        SDL_DestroyTexture(texturas.kontsumistaD);
    }

    // 13-19 (Zakarra)
    if (texturas.mapaZakarra)
    {
        SDL_DestroyTexture(texturas.mapaZakarra);
    }
    if (texturas.menuZakarra)
    {
        SDL_DestroyTexture(texturas.menuZakarra);
    }
    if (texturas.zakarraFont)
    {
        SDL_DestroyTexture(texturas.zakarraFont);
    }
    if (texturas.zakarra)
    {
        SDL_DestroyTexture(texturas.zakarra);
    }
    if (texturas.zakarraBala)
    {
        SDL_DestroyTexture(texturas.zakarraBala);
    }
    if (texturas.zakarraV)
    {
        SDL_DestroyTexture(texturas.zakarraV);
    }
    if (texturas.zakarraD)
    {
        SDL_DestroyTexture(texturas.zakarraD);
    }

    // 20-26 (Sierra)
    if (texturas.mapaSierra)
    {
        SDL_DestroyTexture(texturas.mapaSierra);
    }
    if (texturas.menuSierra)
    {
        SDL_DestroyTexture(texturas.menuSierra);
    }
    if (texturas.sierraFont)
    {
        SDL_DestroyTexture(texturas.sierraFont);
    }
    if (texturas.sierra)
    {
        SDL_DestroyTexture(texturas.sierra);
    }
    if (texturas.sierraBala)
    {
        SDL_DestroyTexture(texturas.sierraBala);
    }
    if (texturas.sierraV)
    {
        SDL_DestroyTexture(texturas.sierraV);
    }
    if (texturas.sierraD)
    {
        SDL_DestroyTexture(texturas.sierraD);
    }

    // 27-33 (Banko)
    if (texturas.mapaBanko)
    {
        SDL_DestroyTexture(texturas.mapaBanko);
    }
    if (texturas.menuBanko)
    {
        SDL_DestroyTexture(texturas.menuBanko);
    }
    if (texturas.bankoFont)
    {
        SDL_DestroyTexture(texturas.bankoFont);
    }
    if (texturas.banko)
    {
        SDL_DestroyTexture(texturas.banko);
    }
    if (texturas.bankoBala)
    {
        SDL_DestroyTexture(texturas.bankoBala);
    }
    if (texturas.bankoMiniBala)
    {
        SDL_DestroyTexture(texturas.bankoMiniBala);
    }
    if (texturas.bankoV)
    {
        SDL_DestroyTexture(texturas.bankoV);
    }
    if (texturas.bankoD)
    {
        SDL_DestroyTexture(texturas.bankoD);
    }

    // 34-40 (Smog)
    if (texturas.mapaSmog)
    {
        SDL_DestroyTexture(texturas.mapaSmog);
    }
    if (texturas.menuSmog)
    {
        SDL_DestroyTexture(texturas.menuSmog);
    }
    if (texturas.smogFont)
    {
        SDL_DestroyTexture(texturas.smogFont);
    }
    if (texturas.smog)
    {
        SDL_DestroyTexture(texturas.smog);
    }
    if (texturas.smogBala)
    {
        SDL_DestroyTexture(texturas.smogBala);
    }
    if (texturas.smogV)
    {
        SDL_DestroyTexture(texturas.smogV);
    }
    if (texturas.smogD)
    {
        SDL_DestroyTexture(texturas.smogD);
    }
    // 41-46
    if (texturas.mapaFinal)
    {
        SDL_DestroyTexture(texturas.mapaFinal);
    }
    if (texturas.aurpegiKontsumista)
    {
        SDL_DestroyTexture(texturas.aurpegiKontsumista);
    }
    if (texturas.aurpegiZakarra)
    {
        SDL_DestroyTexture(texturas.aurpegiZakarra);
    }
    if (texturas.aurpegiSierra)
    {
        SDL_DestroyTexture(texturas.aurpegiSierra);
    }
    if (texturas.aurpegiBanko)
    {
        SDL_DestroyTexture(texturas.aurpegiBanko);
    }
    if (texturas.aurpegiSmog)
    {
        SDL_DestroyTexture(texturas.aurpegiSmog);
    }
    if (texturas.aurpegiLumen)
    {
        SDL_DestroyTexture(texturas.aurpegiLumen);
    }
    if (texturas.story)
    {
        SDL_DestroyTexture(texturas.story);
    }
    if (texturas.kontrolak)
    {
        SDL_DestroyTexture(texturas.kontrolak);
    }
}