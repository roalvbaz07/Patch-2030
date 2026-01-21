#include "pertsonaia.h"
#include <SDL_image.h>

int tiempoUltimoDisparo = 0;

void pertsonaiaHandleEvent()
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (event.type == SDL_KEYDOWN)
    {
        // Ignorar eventos de repetición automática de tecla
        if (event.key.repeat)
        {
            return;
        }
        if (event.type == SDL_QUIT)
        {
            exit(0); // Jokoa osorik ixten dugu
        }
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            exit(0); // Jokoa osorik ixten dugu
        }

        if (event.key.keysym.sym == SDLK_a)
        {
            lumen.unekoEgoera = KORRIKA_EZKERRA;
        }
        else if (event.key.keysym.sym == SDLK_d)
        {
            lumen.unekoEgoera = KORRIKA_ESKUMA;
        }
        if (event.key.keysym.sym == SDLK_SPACE)
        {
            if (!lumen.aireanDago)
            {
                lumen.Vy = -(lumen.saltoIndarra);
                lumen.aireanDago = 1;
            }
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        if (event.key.keysym.sym == SDLK_a)
        {
            if (state[SDL_SCANCODE_D])
            {
                lumen.unekoEgoera = KORRIKA_ESKUMA;
            }
            else
            {
                lumen.unekoEgoera = GELDIK;
            }
        }
        else if (event.key.keysym.sym == SDLK_d)
        {
            if (state[SDL_SCANCODE_A])
            {
                lumen.unekoEgoera = KORRIKA_EZKERRA;
            }
            else
            {
                lumen.unekoEgoera = GELDIK;
            }
        }
    }
}

void pertsonaiaUpdate(int suelo)
{

    const Uint8 *state = SDL_GetKeyboardState(NULL);

    static int frameCounter = 0;
    frameCounter++;
    int animSpeed = 4; // Cambia el frame cada 6 actualizaciones

    if (lumen.aireanDago == 1)
    {
        lumenSalto(suelo);
    }

    if (state[SDL_SCANCODE_RIGHT])
    {
        lumenDisparo();
    }

    switch (lumen.unekoEgoera)
    {
    case GELDIK:
        lumen.frame = 2; // Frame de idle
        break;

    case KORRIKA_EZKERRA:
        lumen.direction = -1;
        if (lumen.x > 0)
        {
            lumen.x -= 15;
        }
        if (frameCounter % animSpeed == 0)
        {
            lumen.frame = (lumen.frame + 1) % 3;
        }
        break;

    case KORRIKA_ESKUMA:
        lumen.direction = 1;
        if (lumen.x + lumen.w < 1600)
        {
            lumen.x += 15;
        }
        if (frameCounter % animSpeed == 0)
        {
            lumen.frame = (lumen.frame + 1) % 3;
        }
        break;

    case MUGITZEN:
        break;
    }
}

void lumenSalto(int suelo)
{
    // 1. Aplicar Gravedad (Asegúrate que Vy sea float en el struct!)
    lumen.Vy += GRAVEDAD_SALTO;

    // 2. Limitar velocidad máxima de caída
    if (lumen.Vy > 15.0f)
    {
        lumen.Vy = 15.0f;
    }

    // 3. Mover al personaje en el eje Y
    lumen.y += (int)lumen.Vy;

    // 4. Colisión con el suelo usando el DEFINE
    if (lumen.y >= suelo)
    {
        lumen.y = suelo;      // Corregir posición usando la constante
        lumen.Vy = 0;         // Parar caída
        lumen.aireanDago = 0; // Toca suelo
    }
}

void lumenDisparo()
{

    Uint32 tiempoActual = SDL_GetTicks();
    // 300ms de cooldown para no ametrallar
    if (tiempoActual > tiempoUltimoDisparo + 300)
    {
        for (int i = 0; i < MAX_BALAK; i++)
        {
            if (lumenBala[i].aktibo == 0) // Buscamos hueco libre
            {
                lumenBala[i].aktibo = 1;

                // POSICIÓN INICIAL
                // Ajustamos para que salga del centro aproximado de Lumen
                lumenBala[i].x = lumen.x + (lumen.w / 2);
                lumenBala[i].y = lumen.y + (lumen.h / 3);

                // DIRECCIÓN Y VELOCIDAD
                // Multiplicamos la velocidad base por la dirección (1 o -1)
                lumenBala[i].Vx = 50 * lumen.direction;
                lumenBala[i].Vy = 0; // Disparo recto, sin caída vertical

                tiempoUltimoDisparo = tiempoActual;
                break; // Salimos del bucle tras disparar UNA bala
            }
        }
    }
}