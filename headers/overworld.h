#ifndef OVERWORLD_H
#define OVERWORLD_H

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "characters.h"


std::ostream& operator << (std::ostream& output, const Items item);
std::ostream& operator << (std::ostream& output, const Skills skill);
bool operator == (const Items item1, const Items item2);

void setColor(int color);
void showBestiary(const std::vector<Mobs> mobs);
void showInventory(Characters hero);
void showStats(Characters hero);
void showSkills(Characters hero);
void showMenu(Characters hero, std::vector<Mobs> mobList);
int startMenu();

class Shop{
    public:
        std::string shopName;
        std::vector<Items> shopItems;
        
        void browseShop(Characters &hero);
        void addItems(Items item, int qty);
        Shop(std::string name);

};

class Map{
    public:
        char mapLayout[15][15];
        std::string mapName;
        std::vector<Mobs> mapMobs;
        int startCX, startCY, exitCX, exitCY;
        std::vector<int> mobRate;

        void addMobs(Mobs mob, int enRate);
        //bool detectAdj(int posX, int posY);
        void exploreMap(Characters hero, Shop shop);
        void setMap(char map[15][15]);
        void mobEn(std::vector<Mobs> mapMobs, std::vector<int> mobRate, Characters hero);
        Map(std::string name, int startCX, int startCY, int exitCX, int exitCY);
};

#endif