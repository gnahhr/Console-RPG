#include "overworld.h"
#include "characters.h"
#include "battle-system.h"

//Overload Extraction Operator to display Item in shop
std::ostream& operator << (std::ostream& output, const Items item){
            output << item.name << " " << item.qty << "x";
            return output;
}

//Overload Extraction Operator to display Item in shop
bool operator == (const Items item1, const Items item2){
    return item1.name == item2.name;
}

//Overload Extraction Operator to display skills
std::ostream& operator << (std::ostream& output, const Skills skill){
            output << skill.name << " " << skill.mpCost << "MP";
            return output;
}

//Set text color
void setColor (int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//Show defeated and not defeated mobs within the world
//Green for defeated and gray for not yet encountered/defeated
void showBestiary(const std::vector<Mobs> mobs){
    system("CLS");
    for (int x = 0; x < mobs.size(); x++){
        if (mobs[x].isDefeated == true){
            setColor(2);
            std::cout << mobs[x].mobName << std::endl;
        }
        else {
            setColor(8);
            std::cout << mobs[x].mobName << std::endl;
        }
    }
    std::cout << "\nPRESS SPACE TO GO BACK...";
    while(true){
        if (GetAsyncKeyState(VK_SPACE) != 0){ break; }
    }
}

//Show list of items in the inventory of hero
void showInventory(Characters hero){
    system("CLS");
    std::cout << "INVENTORY: \n\n";
    for (int x = 0; x < hero.inv.size(); x++){
        std::cout << hero.inv[x] << std::endl;
    }
    std::cout << "Capacity: " << hero.maxStorage << "\\" << hero.inv.size();
    
    std::cout << "\nPRESS SPACE TO GO BACK...";
    while(true){
        if (GetAsyncKeyState(VK_SPACE) != 0){ break; }
    }
}

//Show stats of the hero along with needed EXP for next level
void showStats(Characters hero){
    system("CLS");
    std::cout << hero.charName << " STATS: \n\n";
    std::cout << "Level: " << hero.LVL << "\n"
    << "HP: " << hero.HP << "\\" << hero.maxHP
    << "\nMP: " << hero.MP << "\\" << hero.maxMP
    << "\nATK: " << hero.ATK
    << "\nDEF: " << hero.DEF
    << "\nSPD: " << hero.SPD
    << "\nEXP: " << hero.EXP << "\\"<< hero.nextEXP << "\n";
    
    std::cout << "\nPRESS SPACE TO GO BACK...";
    while(true){
        if (GetAsyncKeyState(VK_SPACE) != 0){ break; }
    }
}

//Show list of skills of hero
void showSkills(Characters hero){
    system("CLS");
    std::cout << "SKILL LIST: \n\n";
    for (int x = 0; x < hero.skillList.size(); x++){
        std::cout << hero.skillList[x] << std::endl;
    }
    
    std::cout << "\nPRESS SPACE TO GO BACK...";
    while(true){
        if (GetAsyncKeyState(VK_SPACE) != 0){ break; }
    }
}

//Show Menu to Display Infos in Overworld
void showMenu(Characters hero, std::vector<Mobs> mobList){
    std::string menu[5] = {"Character Info", "Inventory", "Skills",
    "Bestiary", "Exit"};
    bool isRunning = true;
    int menuPointer = 0;
    setColor(15);
    while (isRunning){
        system("CLS");
        std::cin.clear();
        setColor(15);
        std::cout << "CHOOSE WHAT YOU WANT TO DO:\n";
        for (int x = 0; x < 5; x++){
            if (menuPointer == x){
                setColor(11);
                std::cout << menu[x] << std::endl;
            }
            else {
                setColor(15);
                std::cout << menu[x] << std::endl;
            }
        }
        while (true){
            if(GetAsyncKeyState(VK_UP) != 0){
                menuPointer--;
                if (menuPointer < 0){
                    menuPointer = 4;
                }
                break;
            }
            else if(GetAsyncKeyState(VK_DOWN) != 0){
                menuPointer++;
                if (menuPointer > 4){
                    menuPointer = 0;
                }
                break;
            }
            else if(GetAsyncKeyState(VK_RETURN) != 0){
                switch (menuPointer){
                    case 0:
                        showStats(hero);
                        break;
                    case 1:
                        showInventory(hero);
                        break;
                    case 2:
                        showSkills(hero);
                        break;
                    case 3:
                        showBestiary(mobList);
                        break;
                    case 4:
                        isRunning = false;
                        break;
                }
                break;
            }
        }
        Sleep(100);
    }
}

//Add items in shop
void Shop::addItems(Items item, int qty){
    bool sameItem = false;

    for (int x = 0; x < shopItems.size(); x++){
        if (shopItems[x] == item){
            shopItems[x].qty += item.qty;
            sameItem = true;
            break;
        }
    }

    if (!sameItem){
        item.qty = qty;
        shopItems.push_back(item);
    }
}

//Browse Shop
void Shop::browseShop(Characters &hero){
    bool isShopping = true;
    int menuPointer = 0;

    while (isShopping){
        system("CLS");
        std::cin.clear();
        setColor(15);
        std::cout << "= Welcome to \t" << this->shopName << ".\t =================\n";
        std::cout << "WHAT WOULD YOU LIKE TO BUY: \n";
        std::cout << "======================================================================\n";
        for (int x = 0; x <= this->shopItems.size(); x++){
            if (menuPointer == x){
                setColor(11);
                if (x == this->shopItems.size()){ std::cout << "EXIT" << std::endl; }
                else {std::cout << this->shopItems[x] << std::endl;}
            }
            else {
                setColor(15);
                if (x == this->shopItems.size()){ std::cout << "EXIT" << std::endl; }
                else {std::cout << this->shopItems[x] << std::endl;}
            }
        }
        setColor(15);
        std::cout << "======================================================================\n";
        std::cout << "===== Gold: " << hero.gold << " \t====================================\n";
        while (true){
            if(GetAsyncKeyState(VK_UP) != 0){
                if (menuPointer < 0){
                    menuPointer = this->shopItems.size()-1;
                }
                else menuPointer--;
                
                break;
            }
            else if(GetAsyncKeyState(VK_DOWN) != 0){
                if (menuPointer > this->shopItems.size()-1){
                    menuPointer = 0;
                }
                else menuPointer++;
                break;
            }
            else if(GetAsyncKeyState(VK_RETURN) != 0){
                if (menuPointer == this->shopItems.size()){
                    isShopping = false;
                    std::cout << "\nThank you for shopping!\n";
                }
                else {
                    //Check if hero has enough gold.
                    if (hero.gold >= this->shopItems[menuPointer].cost){
                        std::cout << "\nYou have purchased " << this->shopItems[menuPointer].name << ".\n";
                        hero.addItem(this->shopItems[menuPointer]);
                        hero.gold -= shopItems[menuPointer].cost;
                        shopItems[menuPointer].qty--;
                    }
                    else {
                        std::cout << "\nSorry, you don't have enough gold!\n";
                    }
                }
                break;
            }
        }
        Sleep(200);
    }
}

//Shop constructor
Shop::Shop(std::string name){
    this->shopName = name;
}

Map::Map(std::string name, int startCX, int startCY, int exitCX, int exitCY){
    this->mapName = name;
    this->startCX = startCX;
    this->startCY = startCY;
    this->exitCX = exitCX;
    this->exitCY = exitCY;
}

//Add mobs with encounter rate, same index of mobs and enounter rate
void Map::addMobs(Mobs mob, int enRate){
    this->mapMobs.push_back(mob);
    this->mobRate.push_back(enRate);
}

void Map::setMap(char map[15][15]){
    for (int x = 0; x < 15; x++){
        for (int y = 0; y < 15; y++){
            this->mapLayout[x][y] = map[x][y];
        }
    }
}
/*bool Map::detectAdj(int posX, int posY){
    //Check front
    //Check side
    //Check back
}*/

//MAPS WITH COLLISION AND RANDOM ENEMY ENCOUNTERS
void Map::exploreMap(Characters hero, Shop shop){
    srand(time(NULL));

    int posX = 1,
        posY = 1,
        corX = 0, corY = 0;

    bool explore = true;

    //Map Exploration
    while (explore){
        system("CLS");
        for (corY = 0; corY < 15; corY++){
            for (corX = 0; corX < 15; corX++){
                if ((corX == posX) && (corY == posY)){
                    setColor(10);
                    std::cout << "P";
                }
                else {
                    setColor(15);
                    std::cout << mapLayout[corY][corX];
                }
            }
            std::cout << std::endl;
        }
        //Move Character
        while (true){
            if(GetAsyncKeyState(VK_UP) != 0){
                if (mapLayout[posY-1][posX] == '#'){
                    std::cout << "\n\nYou've ran into a wall";
                }
                else if (mapLayout[posY][posX+1] == 'S'){
                    shop.browseShop(hero);
                }
                else if (mapLayout[posY][posX+1] == 'E'){
                    explore = false;
                }
                else {
                    posY--;
                    mobEn(mapMobs, mobRate, hero);
                        
                }
                break;
            }
            else if(GetAsyncKeyState(VK_DOWN) != 0){
                if (mapLayout[posY+1][posX] == '#'){
                    std::cout << "\n\nYou've ran into a wall";
                }
                else if (mapLayout[posY+1][posX] == 'S'){
                    shop.browseShop(hero);
                }
                else if (mapLayout[posY+1][posX] == 'E'){
                    explore = false;
                }
                else {
                    posY++;
                    mobEn(mapMobs, mobRate, hero);
                }
                break;
            }
            else if(GetAsyncKeyState(VK_LEFT) != 0){
                if (mapLayout[posY][posX-1] == '#'){
                    std::cout << "\n\nYou've ran into a wall";
                }
                else if (mapLayout[posY][posX-1] == 'S'){
                    shop.browseShop(hero);
                }
                else if (mapLayout[posY][posX-1] == 'E'){
                    explore = false;
                }
                else {
                    posX--;
                    mobEn(mapMobs, mobRate, hero);
                }
                break;
            }
            else if(GetAsyncKeyState(VK_RIGHT) != 0){
                if (mapLayout[posY][posX+1] == '#'){
                    std::cout << "\n\nYou've ran into a wall";
                }
                else if (mapLayout[posY][posX+1] == 'S'){
                    shop.browseShop(hero);
                }
                else if (mapLayout[posY][posX+1] == 'E'){
                    explore = false;
                }
                else {
                    posX++;
                    mobEn(mapMobs, mobRate, hero);
                }
                break;
            }
            else if(GetAsyncKeyState(VK_SPACE) != 0){
                showMenu(hero, mapMobs);
                break;
            }
        }
        Sleep(50);
    }
}

void Map::mobEn(std::vector<Mobs> mapMobs, std::vector<int> mobRate, Characters hero){
    int x = 0, first, enRate;

    if (rand()% 100 < 25){
        enRate = rand()%100;
        for (x = 0, first = 0; x < mapMobs.size(); x++){
           if ((first <= enRate) && (enRate <= first + mobRate[x])){
               displayBattle(hero, mapMobs[x]);
               break;
           }
           else first = first + mobRate[x]+1;
        } 
    }
}

int startMenu(){
    bool start = true;
    std::string menu[2] = {"START", "EXIT"};
    int menuPointer = 0;

    while(start){
        system("CLS");
        setColor(15);
        std::cout << "======================================================\n";
        for (int y = 0; y < 20; y++){
            for (int x = 0; x < 30; x++){
                if (y == 10 && x == 13){
                    setColor(11);
                    std::cout << "CODING PLAYGROUND"; 
                    setColor(15);
                }
                else std::cout << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "======================================================\n";
        for (int y = 0; y < 2; y++){
            for (int x = 0; x < 30; x++){
                if (x == 13){
                    if (menuPointer == y){
                        setColor(14);
                        std::cout << menu[y]; 
                    }
                    else {
                        setColor(15);
                        std::cout << menu[y]; 
                    }
                    
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }

        while (true){
            if(GetAsyncKeyState(VK_UP) != 0){
                if (menuPointer == 0) menuPointer = 1;
                else menuPointer--;
                
                break;
            }
            else if(GetAsyncKeyState(VK_DOWN) != 0){
                if (menuPointer == 1) menuPointer = 0;
                else menuPointer++;
                break;
            }
            else if(GetAsyncKeyState(VK_RETURN) != 0){
                return menuPointer;
                break;
            }
        }
        Sleep(200);
    }
    return 1;
}