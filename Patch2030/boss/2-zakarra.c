
#include "boss.h"

void etsaiaUpdate()
{
    // 1. Usamos el temporizador PROPIO de la entidad
    zakarra.internalTimer++;
    int animSpeed = 6;

    switch (zakarra.unekoEgoera)
    {
    case GELDIK:
        // Lógica de idle...
        if (zakarra.internalTimer % 10 == 0)
        {
            zakarra.frame = (zakarra.frame + 1) % 3;
        }
        break;

    case MUGITZEN: // Aunque se llame "Subiendo", lo usaremos para "Patrullando Vertical"

        // --- LOGICA DE MOVIMIENTO VERTICAL ---
        zakarra.y += zakarra.Vy;

        // Choque con límite superior
        if (zakarra.y <= LIMITE_ARRIBA)
        {
            zakarra.y = LIMITE_ARRIBA; // Corregir posición
            zakarra.Vy = -zakarra.Vy;  // Invertir velocidad (bajar)
        }
        // Choque con límite inferior
        else if (zakarra.y >= LIMITE_ABAJO)
        {
            zakarra.y = LIMITE_ABAJO; // Corregir posición
            zakarra.Vy = -zakarra.Vy; // Invertir velocidad (subir)
        }
        // -------------------------------------

        // Animación (más rápida si se mueve)
        if (zakarra.internalTimer % animSpeed == 0)
        {
            // Asumiendo que tienes frames de movimiento definidos
            // Usaremos frames 0-3 por si acaso la imagen no tiene frames 4-7
            zakarra.frame = (zakarra.frame + 1) % 3;
        }
        break;

    default:
        break;
    }
}

void bossDisparar()
{
    int i;

    // 1. CoolDown-a 0 izan arte itxoiten dugu
    if (coolDownDisparo > 0)
    {
        coolDownDisparo--;
        return;
    }

    for (i = 0; i < MAX_BALAK; i++)
    {
        if (!bossBala[i].aktibo) // Hutsik dagoen bala bat aurktzen deu
        {
            bossBala[i].aktibo = 1;

            // Nundik ateratzen den definitzen dugu
            bossBala[i].x = zakarra.x + (zakarra.w / 2);
            bossBala[i].y = zakarra.y + (zakarra.h / 2);

            // --- FÍSICA PARABÓLICA ---
            float vyBala = -15.0f; // Berakako indarra

            // Formula: (2*V)/g
            float tiempoVuelo = (2.0f * fabs(vyBala)) / GRAVEDAD;

            float vLumen = 0;
            if (lumen.unekoEgoera == KORRIKA_ESKUMA)
            {
                vLumen = lumen.Vx; // Vx positiboa dela asumituz
            }
            else if (lumen.unekoEgoera == KORRIKA_EZKERRA)
            {
                vLumen = -lumen.Vx; // Vx negatiboa dela asumituz
            }

            float xDestino, xLumen; // xLumen kalkulatzeko posizioa da, hau da, gero ez da aldatzen

            xLumen = lumen.x + (lumen.w / 2); // Lumenen zentroko posizioa kalkulatzeko

            xDestino = xLumen + (vLumen * tiempoVuelo); // Nun egongo den lumen kalkulatzeko

            // Bala kanpora ez joateko
            if (xDestino < 0)
            {
                xDestino = 0;
            }

            if (xDestino > WIDTH)
            {
                xDestino = WIDTH;
            }

            // Distantzia kalkulatzeko
            float distanciaX;
            distanciaX = xDestino - bossBala[i].x; // Zenbateko distantzia dagoen boss-etik lumenera kalkulatzeko

            // Beharrezko abiadura (Vx=x/t)
            bossBala[i].Vx = distanciaX / tiempoVuelo;
            bossBala[i].Vy = vyBala;

            // Cooldown-a aldatzen deu
            coolDownDisparo = 20;
            break;
        }
    }
}