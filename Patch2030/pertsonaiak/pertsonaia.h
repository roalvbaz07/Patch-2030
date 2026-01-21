#ifndef PERTSONAIA_H
#define PERTSONAIA_H

// ==== INCLUDEAK ====
#include "../config/config.h"
#include "../global.h"
#include <SDL.h>
#include <stdio.h>

//==== ETXERN ====

// ==== FUNTZIOAK ====
void pertsonaiaHandleEvent();     // Teklatuaren pultsazioak handleatzeko
void pertsonaiaUpdate(int suelo); // Teklatuaren pultsazioen araberako ekintzak
void lumenDisparo();              // Lumen-ren disparua
void lumenSalto(int suelo);       // Lumen-ren jauzia
#endif