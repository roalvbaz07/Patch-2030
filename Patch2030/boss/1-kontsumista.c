#include "boss.h"

// KONFIGURAZIOA

static int cooldown = 0;

// 1. ZATIA: MUGIMENDUA (Oraingoz geldirik)
void kontsumistaUpdate()
{
    // A) Erloju propioa eguneratu
    kontsumista.internalTimer++;

    // B) Egoera kudeatu (Switch erabiliz, etorkizunerako prestatuta)

    switch (kontsumista.unekoEgoera)
    {
    case GELDIK:
    case KORRIKA_ESKUMA:
    case MUGITZEN:
    case KORRIKA_EZKERRA:

        // Animazioa: 20 frametik behin irudia aldatu
        if (kontsumista.internalTimer % 20 == 0)
        {
            kontsumista.frame = (kontsumista.frame + 1) % 3; // 0, 1, 2, 3 bueltaka
        }
        break;
    }
}

// 2. ZATIA: TIROA (Zuzen ezkerrera)
void kontsumistaDisparar()
{
    int abiadura = 0;
    // A) Itxaron behar dugu? (Cooldown)
    if (kontsumista.fasea == 1)
    {
        abiadura = -10;
        if (cooldown > 0)
        {
            cooldown--;
            return; // Oraindik ezin du tiro egin
        }
    }

    if (kontsumista.fasea == 2)
    {
        abiadura = -26;
        if (cooldown > 0)
        {
            cooldown--;
            return; // Oraindik ezin du tiro egin
        }
    }

    // B) Bala libre bat bilatu array-an
    int i;
    for (i = 0; i < MAX_BALAK; i++)
    {
        // "aktibo == 0" bada, bala hori erabili dezakegu
        if (!bossBala[i].aktibo)
        {
            // 1. Bala piztu
            bossBala[i].aktibo = 1;
            cooldown = DISPARO_CD; // Tenporizadorea berrezarri

            // 2. Hasierako posizioa (kontsumista-aren bularrean)
            bossBala[i].x = kontsumista.x;
            bossBala[i].y = kontsumista.y + (kontsumista.h / 2);

            // 3. Abiadura (ZUZEN EZKERRERA)
            // Ez dugu Lumen bilatzen. Beti zuzen doa.
            bossBala[i].Vx = abiadura; // -15 (Ezkerrera)
            bossBala[i].Vy = 0;        // 0 (Ez doa gora ez behera)

            break; // Bala bat jaurti dugu, listo.
        }
    }
}