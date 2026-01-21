#include "levels.h"

void Menu(SDL_Renderer *renderer, SDL_Window *window)
{
    int running = 1;

    // Asegurarnos de que el cursor sea visible en el menú
    SDL_ShowCursor(SDL_ENABLE);

    // Definir dimensiones de botones
    int buttonW = 400;
    int buttonH = 200;
    // Botón Jugar (Centrado un poco más arriba)
    SDL_Rect botonJugar = {(WIDTH - buttonW) / 2 - 380, (HEIGHT / 2) - buttonH + 600, buttonW, buttonH};

    // Botón Salir (Justo debajo)
    SDL_Rect botonSalir = {(WIDTH - buttonW) / 2 + 380, (HEIGHT / 2) - buttonH + 600, buttonW, buttonH};

    while (running)
    {
        // Obtener posición del ratón para hover
        int mx, my;
        SDL_GetMouseState(&mx, &my);

        // --- INPUT ---
        while (SDL_PollEvent(&event))
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

            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    // Comprobar click en Jugar
                    if (mx >= (botonJugar.x - botonJugar.w) && mx <= (botonJugar.x + botonJugar.w) &&
                        my >= (botonJugar.y - botonJugar.h) && my <= (botonJugar.y + botonJugar.h))
                    {
                        // ¡Click en Boton Jugar!
                        running = 0; // Iniciar juego
                    }
                    // Comprobar click en Salir
                    else if (mx >= botonSalir.x && mx <= (botonSalir.x + botonSalir.w) && my >= botonSalir.y &&
                             my <= (botonSalir.y + botonSalir.h))
                    {
                        // ¡Click en Boton Salir!
                        Limpieza(renderer, window); // Salir del juego
                    }
                }
            }
            // Opción para salir con ESC
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    Limpieza(renderer, window);
                }
            }
        }

        // --- RENDER ---
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Fondo
        if (texturas.fondomenu != NULL)
        {
            SDL_RenderCopy(renderer, texturas.fondomenu, NULL, NULL);
        }

        SDL_RenderPresent(renderer);
    }

    // Ocultar cursor de nuevo para el juego si es necesario,
    // pero idealmente main.c o el nivel debería manejar esto.
    SDL_ShowCursor(SDL_DISABLE);
}