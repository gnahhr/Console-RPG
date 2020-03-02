#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>
#include <vector>
#include <iostream>

class Skills{
    public:
        int dmg, mpCost;
        std::string name, desc;
        Skills(std::string name, int dmg, int mpCost, std::string desc);
};

class Items{
    public:
        int dmg, cost, qty;
        std::string name, desc;
        Items(std::string name, int dmg, int cost, std::string desc);
};

class Characters{
    public:
        int maxHP, maxMP, nextEXP = 10, maxStorage = 5, gold = 500;
        int LVL = 1, HP, MP, ATK, DEF, SPD, EXP = 0;
        std::vector<Items> inv;
        std::vector<Skills> skillList;
        std::string charName;

        void addItem(Items item);
        void addSkills(Skills skill);
        Characters(std::string name, int HP, int MP, int ATK, int DEF, int SPD);
};

class Mobs{
    public:
        int maxHP, HP, maxMP, MP, ATK, DEF, SPD, EXP;
        std::string mobName;
        std::string sprite[10];
        bool isDefeated = false;
        
        void setSprite(std::string sprite[10]);
        void showSprite();
        Mobs(std::string name, int HP, int MP, int ATK, int DEF, int SPD, int EXP);
};

#endif