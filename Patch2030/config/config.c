#include "config.h"

void balakEguneratu(int direction, BALAK *balak, int gravity)
{
    for (int i = 0; i < MAX_BALAK; i++)
    {
        if (balak[i].aktibo)
        {
            // 1. Mover X (Velocidad constante)
            balak[i].x += direction * balak[i].Vx;

            // 2. Mover Y (Velocidad vertical)
            balak[i].y += balak[i].Vy;

            // 3. Aplicar Gravedad (Aceleración)
            if (gravity)
            {
                balak[i].Vy += GRAVEDAD;
            }

            // 4. Limpieza: Si sale de la pantalla, desactivar
            // Asumimos WIDTH y HEIGHT de config.h
            if (balak[i].y > HEIGHT || balak[i].x < 0 || balak[i].x > WIDTH)
            {
                balak[i].aktibo = 0;
            }
        }
    }
}

void balakHasieratu()
{
    for (int i = 0; i < MAX_BALAK; i++)
    {
        bossBala[i].aktibo = 0;
        lumenBala[i].aktibo = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        miniBala[i].aktibo = 0;
    }
}