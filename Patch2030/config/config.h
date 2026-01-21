#ifndef CONFIG_H
#define CONFIG_H

//==== DEFINEAK ====
#define WIDTH 1920               // Pantailaren tamaina horizontalki
#define HEIGHT 1080              // Pantailaren tamaina bertikalki
#define GRAVEDAD 0.5f            // Zenbaf pixel jausten da frame bakoitzean
#define GRAVEDAD_SALTO 1.5f      // Jauziaren grabitatea
#define MAX_BALAK 20             // Pantailan agertu daitzkeen bala kopurua
#define LUMEN_SHOOT_COOLDOWN 300 // Milisegundos entre disparos

// ==== PANTAILAREN LIMITEAK ====
#define LIMITE_ARRIBA 75
#define LIMITE_ABAJO (HEIGHT - 665)

// ==== KONTSUMISTA ====
#define SUELO_KONTSUMISTA 675  // Lurraren posizioa Y ardatzean Kontsumistaren nibelean
#define DISPARO_CD 60          // 60 frames = 2 segundo (tiroen arteko denbora)
#define ABIADURA_BALA -15.0f   // Negatiboa ezkerrera joateko (Lumen dagoen tokira)
#define KONTSUMISTA_BIZITZA 20 // Madam kontsumistaren bizitza

// ==== ZAKARRA ====
#define SUELO_ZAKARRA 605   // Lurraren posizioa Y ardatzean Zakarraren nibelean
#define LUMEN_X_ZAKARRA 605 // Lurraren posizioa Y ardatzean Zakarraren nibelean

// ==== SIERRA =====
#define SUELO_SIERRA 605 // Lurraren posizioa Y ardatzean Sierraren nibelean
#define SIERRA_SALTO -12
#define SIERRA_BIZITZA 25 // Sierraren bizitza kopurua
#define SIERRA_GRABITATEA 0.4f
#define LUMEN_SALTO_SIERRA 30
#define LUMEN_X_SIERRA 605 // Lurraren posizioa Y ardatzean Sierraren nibelean

// ==== BANKO ====
#define SUELO_BANKO 360       // Lurraren posizioa Y ardatzean Bankoren nibelean
#define LUMEN_SUELO_BANKO 750 // Lurraren posizioa Y ardatzean Bankoren nibelean
#define LUMEN_X_BANKO 605     // Lurraren posizioa Y ardatzean Bankoren nibelean
#define BANKO_BIZITZA 67      // Bankeroaren bizitza kopurua
#define LIMITE_ARRIBA_BANKO 150
#define LIMITE_ABAJO_BANKO (HEIGHT - 665)
#define BANKO_GRABITATEA 0.6f

//==== SMOG ====
#define SUELO_SMOG 800    // Lurraren posizioa Y ardatzean Smogren nibelean
#define LUMEN_X_SMOG 1205 // Lurraren posizioa Y ardatzean Smogren nibelean
#define SMOG_BIZITZA 150  // Smogren bizitza kopurua

//==== LUMEN ====
#define LUMEN_BIZITZA 3 // Lumenen bizitza kopurua

typedef enum
{
    GELDIK,
    KORRIKA_ESKUMA,
    KORRIKA_EZKERRA,
    MUGITZEN,
} EGOERA;

typedef struct
{
    float x, y;           // Entitiaren posizioa(x,y)
    int w, h;             // pantailako tamaina(w,h)
    int spriteW, spriteH; // argazkiaren tamaina(spriteW, spriteH)
    float Vx, Vy;         // Entitiaren abiadura(Vx,Vy)
    int direction;        // mugimenduaren zentzua(direction)
    int frame;            // Arkaziaren zatia aukeratzeko
    int bizitza;          // Entity-aren bizitza
    int saltoIndarra;     // Entity-aren saltoaren indarra
    int internalTimer;    // Frameak aldatzeko timer-a
    int aireanDago;       // Entity-a airean dagoen jakiteko
    int fasea;            // Entity-aren faseak (Madam kontsumistarako)
    EGOERA unekoEgoera;   // Entity-aren egoera (mugitzen edo geldik)
} ENTITY;

typedef struct

{
    float x, y;   // Bala-ren posizioa x eta y ardatzetan
    int w, h;     // Bala irudiaren tamaina zabaleran(h) eta luzeeran(h)
    float Vx, Vy; // Bala-ren abiadura x eta y ardatzetan
    int aktibo;   // Balaren egoera (aktibo=1,desaktibauta=0)
} BALAK;

typedef enum
{
    INTRO,
    MENUA,
    MAPA,
    MINIMENU,
    KONTSUMO,
    ZAKARRA,
    SIERRA,
    BANKO,
    SMOG,
} GAMESTATE;

typedef struct
{
    int x, y;
    int w, h;
    int maxVida;
} BIZITZABARRA;

typedef enum
{
    BOSS_KONTSUMO,
    BOSS_ZAKARRA,
    BOSS_SIERRA,
    BOSS_BANKO,
    BOSS_SMOG,
    BOSS_FINAL
} BOSS;

void balakHasieratu();
void balakEguneratu(int direction, BALAK *balak, int gravity);

#include "../global.h"

#endif