#include "boss.h"

static int cooldowndisparo = 0;

void etsaiaUpdateBanko()
{
    switch (banko.unekoEgoera)
    {
    case MUGITZEN:
        if (banko.internalTimer % 6 == 0)
        {
            banko.frame = (banko.frame + 1) % 4;
        }
        break;
    case KORRIKA_ESKUMA:
    case KORRIKA_EZKERRA:
    case GELDIK:
        break;
    }
}

void bossDispararBanko()
{
    // 1. cooldowna ezarri
    if (cooldowndisparo > 0)
    {
        cooldowndisparo--;
        return;
    }

    // Reseteatu
    cooldowndisparo = 47;

    for (int i = 0; i < MAX_BALAK; i++)
    {
        if (!bossBala[i].aktibo) // hutsik dagoen bala bat aurkitu
        {
            bossBala[i].aktibo = 1;

            // Non sortuko da
            bossBala[i].x = banko.x + (banko.w / 2);
            bossBala[i].y = banko.y + (banko.h / 2);

            // --- FÍSICA  ---
            float gravedad = BANKO_GRABITATEA;
            float vyInicial = -15.0f; // Gora egiten den indarra

            // Fórmula: Airean mantentzen den denbora
            float tiempoVuelo = (2.0f * fabs(vyInicial)) / gravedad;

            // Distancia horizontala kalkulatu
            float xDestino = lumen.x + (lumen.w / 2);
            float distanciaX = xDestino - bossBala[i].x;

            // X ardatzeko abiadura kalkulatu
            bossBala[i].Vx = distanciaX / tiempoVuelo;
            bossBala[i].Vy = vyInicial;
            break; // Bala handi bat disparatzerakoan irten
        }
    }
}

void balakEguneratuBanko()
{
    // --- BOSS-aren balak eguneratu ---
    for (int i = 0; i < MAX_BALAK; i++)
    {
        if (bossBala[i].aktibo)
        {
            // Movimiento y Física
            bossBala[i].x += bossBala[i].Vx;
            bossBala[i].y += bossBala[i].Vy;
            bossBala[i].Vy += GRAVEDAD;

            // Minibalen sorrerarako lurraren detekzioa
            if (bossBala[i].y >= LUMEN_SUELO_BANKO + 130)
            {
                bossBala[i].y = LUMEN_SUELO_BANKO + 130; // Posizioa zuzendu

                // Minibalen spawná deklaratu
                int sortutakoMinibalak = 0;

                // Minibalen arrayan lekua topatu
                for (int j = 0; j < 3; j++)
                {
                    if (!miniBala[j].aktibo)
                    {
                        miniBala[j].aktibo = 1;

                        // Bala handia bukatu den lekuan sortu
                        miniBala[j].x = bossBala[i].x;
                        miniBala[j].y = bossBala[i].y + 2;

                        // Kontrako direkzioan bidali
                        if (sortutakoMinibalak == 0)
                        {
                            miniBala[j].Vx = 24.0f; // Eskuma
                        }
                        else
                        {
                            miniBala[j].Vx = -24.0f; // Ezkerra
                        }

                        sortutakoMinibalak++;
                        if (sortutakoMinibalak >= 2)
                        {
                            break; // Behin sortuta, irten
                        }
                    }
                }

                // Bala handia desaktibatu
                bossBala[i].aktibo = 0;
            }

            // Bala handia pantailatik kanpo badago, desaktibatu
            if (bossBala[i].aktibo)
            {
                if (bossBala[i].y > HEIGHT || bossBala[i].x < 0 || bossBala[i].x > WIDTH)
                {
                    bossBala[i].aktibo = 0;
                }
            }
        }
    }

    // --- Minibalen eguneraketa ---
    for (int i = 0; i < 3; i++)
    {
        if (miniBala[i].aktibo)
        {
            // X ardatzean mugimendu konstantean mugitu
            miniBala[i].x += miniBala[i].Vx;

            // Pantailatik irtetzerakoan, desaktibatu
            if (miniBala[i].x < 0 || miniBala[i].x > WIDTH)
            {
                miniBala[i].aktibo = 0;
            }
        }
    }
}
