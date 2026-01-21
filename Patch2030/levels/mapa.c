#include "levels.h"

// Función auxiliar mejorada para detectar click
// Nota: Es mejor pasar el evento desde el bucle principal, pero para mantener tu estructura:
int mouse_over_boton(int mx, int my, SDL_Rect boton)
{
    int emaitza = 0;
    if (mx >= boton.x && mx <= (boton.x + boton.w) && my >= boton.y && my <= (boton.y + boton.h))
    {
        emaitza = 1;
    }
    return emaitza;
}

void mapa(SDL_Renderer *renderer, SDL_Window *window)
{
    int mx, my, running = 0;

    SDL_ShowCursor(SDL_ENABLE);
    // --- INPUT & RENDER LOOP ---
    while (!running)
    {
        // 1. GESTIONAR EVENTOS (Siempre al principio del bucle)
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

            // Detectar Click
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
            {
                SDL_GetMouseState(&mx, &my);

                // Lógica de cambio de mapa según el estado actual
                switch (bossAhora) // USAR ASTERISCO
                {
                case BOSS_KONTSUMO: {
                    SDL_Rect botoia1 = {1531, 815, 102, 250};
                    // Nota: WIDTH * (1/2) en enteros es 0. Usa WIDTH / 2

                    if (mouse_over_boton(mx, my, botoia1))
                    {
                        // Click . Ir a ZAKARRA
                        running = 1; // Salir del bucle para cargar nuevo mapa
                    }
                }
                break;

                case BOSS_ZAKARRA: {
                    SDL_Rect botoia2 = {1118, 915, 100, 250};
                    if (mouse_over_boton(mx, my, botoia2))
                    {
                        // Click . Ir a SIERRA
                        running = 1;
                    }
                }
                break;

                case BOSS_SIERRA: {
                    SDL_Rect botoia3 = {1135, 636, 89, 250};
                    if (mouse_over_boton(mx, my, botoia3))
                    {
                        // Click . Ir a BANKO
                        running = 1;
                    }
                }
                break;
                case BOSS_BANKO: {
                    SDL_Rect botoia4 = {704, 435, 98, 250};
                    if (mouse_over_boton(mx, my, botoia4))
                    {
                        // Click . Ir a SMOG
                        running = 1;
                    }
                }
                // ... añadir el resto de casos igual ...
                break;
                case BOSS_SMOG: {
                    // Aquí quizás sí quieras salircase BOSS_SIERRA: {
                    SDL_Rect botoia5 = {964, 439, 120, 250};
                    if (mouse_over_boton(mx, my, botoia5))
                    {
                        // Click . Ir a JAKINTSU
                        running = 1;
                    }
                }
                break;
                case BOSS_FINAL:
                    SDL_Rect botoia7 = {698, 709, 520, 200};
                    if (mouse_over_boton(mx, my, botoia7))
                    {
                        // Click . Ir a MENU
                        running = 1;
                    }
                    break;
                }
            }
        }

        // 2. RENDERIZADO (Fuera del loop de eventos)
        SDL_RenderClear(renderer); // Limpiar pantalla anterior

        switch (bossAhora) // USAR ASTERISCO
        {
        case BOSS_KONTSUMO:
            SDL_RenderCopy(renderer, texturas.mapaKontsumista, NULL, NULL);
            // Dibujar botón debug si quieres ver dónde está
            break;
        case BOSS_ZAKARRA:
            SDL_RenderCopy(renderer, texturas.mapaZakarra, NULL, NULL);

            break;
        case BOSS_SIERRA:
            SDL_RenderCopy(renderer, texturas.mapaSierra, NULL, NULL);

            break;
        case BOSS_BANKO:
            SDL_RenderCopy(renderer, texturas.mapaBanko, NULL, NULL);

            break;
        case BOSS_SMOG:
            SDL_RenderCopy(renderer, texturas.mapaSmog, NULL, NULL);

            break;
        case BOSS_FINAL:
            SDL_RenderCopy(renderer, texturas.mapaFinal, NULL, NULL);

            break;
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // Pequeña pausa para no quemar la CPU (aprox 60 FPS)
    }
}

int introBoss(SDL_Renderer *renderer, SDL_Window *window)
{
    int mx, my, running = 0, itzuli = 0;
    running = 0;

    // --- INPUT & RENDER LOOP ---
    while (!running)
    {
        // 1. GESTIONAR EVENTOS (Siempre al principio del bucle)
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                Limpieza(renderer, window);
            }

            // Detectar Click
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
            {
                SDL_GetMouseState(&mx, &my);

                SDL_Rect maparaItzuli = {680, 650, 280, 400};
                SDL_Rect jolastu = {1030, 650, 280, 400};

                if (mouse_over_boton(mx, my, maparaItzuli))
                {
                    // Click . mapara itzuli
                    running = 1; // Salir del bucle para cargar nuevo MENU
                    itzuli = 1;
                }
                else if (mouse_over_boton(mx, my, jolastu))
                {
                    // Click . Jolastu
                    running = 1; // Salir del bucle para cargar nuevo MENU
                }
            }
        }
        // 2. RENDERIZADO (Fuera del loop de eventos)
        SDL_RenderClear(renderer); // Limpiar pantalla anterior

        switch (bossAhora) // USAR ASTERISCO
        {
        case BOSS_KONTSUMO:
            SDL_RenderCopy(renderer, texturas.menuKontsumista, NULL, NULL);
            break;
        case BOSS_ZAKARRA:
            SDL_RenderCopy(renderer, texturas.menuZakarra, NULL, NULL);
            break;
        case BOSS_SIERRA:
            SDL_RenderCopy(renderer, texturas.menuSierra, NULL, NULL);
            break;
        case BOSS_BANKO:
            SDL_RenderCopy(renderer, texturas.menuBanko, NULL, NULL);
            break;
        case BOSS_SMOG:
            SDL_RenderCopy(renderer, texturas.menuSmog, NULL, NULL);
            break;
        case BOSS_FINAL:
            break;
        }
        SDL_RenderPresent(renderer);
    }
    return itzuli;
}