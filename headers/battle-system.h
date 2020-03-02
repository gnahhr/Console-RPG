#ifndef BATTLESYS_H
#define BATTLESYS_H

#include "characters.h"
#include "cmath"

void displayBattle(Characters &hero, Mobs &mob);
void damageCalc(Characters &hero, Mobs &mob);
void useItem(Mobs &mob, Items &item);
void useSkill(Characters &hero, Mobs &mob, Skills &skill);
void mobTurn(Characters &hero, Mobs &mob);

#endif