#include "boss.h"

static int cooldownDisparo = 0;

void sierraUpdate()
{
    sierra.internalTimer++;
    int animSpeed = 10;

    switch (sierra.unekoEgoera)
    {
    case GELDIK:
        if (sierra.internalTimer % 10 == 0)
        {
            sierra.frame = (sierra.frame + 1) % 3;
        }
        if (sierra.internalTimer > 50)
        {
            sierra.unekoEgoera = MUGITZEN;
            sierra.internalTimer = 0;
        }
        break;

    case MUGITZEN:
        sierra.Vy += SIERRA_GRABITATEA;
        sierra.y += sierra.Vy;

        if (sierra.y >= LIMITE_ABAJO)
        {
            sierra.y = LIMITE_ABAJO;
            sierra.Vy = SIERRA_SALTO;
        }

        if (sierra.internalTimer % animSpeed == 0)
        {
            sierra.frame = (sierra.frame + 1) % 3;
        }
        break;
    case KORRIKA_EZKERRA:
    case KORRIKA_ESKUMA:

        break;
    }
}

void sierraDisparar()
{
    if (cooldownDisparo > 0)
    {
        cooldownDisparo--;
        return;
    }

    cooldownDisparo = 80;

    for (int i = 0; i < MAX_BALAK; i++)
    {
        if (!bossBala[i].aktibo)
        {
            bossBala[i].aktibo = 1;

            // Hasierako posizioa
            bossBala[i].x = sierra.x;

            // Altuera aldaketa txiki bat ausazkotasuna emateko
            int variacionAltura = (rand() % 41) - 20;
            bossBala[i].y = (sierra.y + (int)(sierra.h * 0.75)) + variacionAltura;

            // Abiadura: ezkerrerantz hasieran
            bossBala[i].Vx = -10.0f;
            bossBala[i].Vy = 0;

            // Ez dugu frame-rik hasieratu behar irudi bakarra delako
            break;
        }
    }
}

void eguneratuAizkorak()
{
    for (int i = 0; i < MAX_BALAK; i++)
    {
        if (bossBala[i].aktibo)
        {
            // Posizioa eguneratu
            bossBala[i].x += bossBala[i].Vx;
            bossBala[i].y += bossBala[i].Vy;

            // Ezkerreko muga
            if (bossBala[i].Vx < 0 && bossBala[i].x <= 50)
            {
                bossBala[i].Vx = 10.0f; // Eskuinera bueltan
            }

            // Itzulera muga (boss-aren x posizioa gainditzean)
            if (bossBala[i].Vx > 0 && bossBala[i].x >= sierra.x)
            {
                bossBala[i].aktibo = 0; // Desagertu
            }
        }
    }
}
