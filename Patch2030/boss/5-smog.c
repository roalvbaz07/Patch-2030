#include "boss.h"

void smogUpdate()
{
    // Smogren timer-a gehitzen dugu
    smog.internalTimer++;

    if (smog.internalTimer % 12 == 0) // Animazioa aldatuko da, internaltimer /12 ren hondarra == 0 denean
    {
        smog.frame = (smog.frame + 1) % 4; // ehunekoaren ondorengoa frame kop totala da
    }
}

// Funtzio honek Smog-ren bizitzaren arabera disparuen abiadura eta frekuentzia aldatzen du.
void SmogBizitzaDisparo()
{
    // CoolDown-a kudeatu lehenik
    if (coolDownDisparo > 0)
    {
        coolDownDisparo--;
        return;
    }

    if (smog.bizitza > 100)
    {
        coolDownDisparo = 60;
        SmogDisparo(12);
    }
    else if (smog.bizitza > 50 && smog.bizitza <= 100)
    {
        coolDownDisparo = 50;
        SmogDisparo(16);
    }
    else if (smog.bizitza <= 50) // 50 edo gutxiago
    {
        coolDownDisparo = 40;
        SmogDisparo(20);
    }
}

// Funtzio hau Smog-ren disparoa antolatzen du
void SmogDisparo(float abiadura)
{
    // Bilatu bala inaktibo bat arrayan
    for (int i = 0; i < MAX_BALAK; i++)
    {
        if (!bossBala[i].aktibo)
        {
            bossBala[i].aktibo = 1;

            // Sorrera: bossaren erdia baina pixkat beherago
            bossBala[i].x = smog.x + (smog.w / 2);       // X ardatza
            bossBala[i].y = smog.y + (smog.h / 2) + 150; // Y ardatza

            bossBala[i].Vx = abiadura; // Balaren abiadura behar denera aldatzen dugu
            bossBala[i].Vy = 0;        // Bala horizontala izateko
            break;                     // Bala bat aurkitu eta aktibatu ondoren, bukatu
        }
    }
}