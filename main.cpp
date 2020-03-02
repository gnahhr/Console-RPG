#include "headers/characters.h"
#include "headers/battle-system.h"
#include "headers/overworld.h"

//Create Skills
Skills sampleUno("Sample1", 50, 5, "Yeeeted");
Skills sampleDos("Sample2", 50, 5, "Yeeeted");
Skills sampleTres("Sample3", 50, 5, "Yeeeted");
Skills sampleQuatro("Sample4", 50, 5, "Yeeeted");

//Create Items
Items bakuUno("Bomb1", 200, 50, "Kabooom!");
Items bakuDos("Bomb2", 200, 50, "Kabooom!");
Items bakuTres("Bomb3", 200, 50, "Kabooom!");
Items baQuatro("Bomb4", 200, 50, "Kabooom!");

int main(){
    int startSwitch = 0;
    //Rand function
    srand(time(NULL));

    //Objects
    Characters Hero("Mattinik", 500, 500, 500, 500, 500);
    Mobs Slime("Slime", 500, 0, 50, 50, 50, 3);
    Mobs Bug("Bug", 50, 0, 50, 50, 50, 1);
    Mobs Bob("Bob", 500, 0, 200, 200, 5, 50);

    //Sprites
    std::string slimed[10] = {
    {"          0 0 0   0"},
    {"        0   0      "},
    {"      0       0    "},
    {"    0           0  "},
    {"  0               0"},
    {"0     0     0     0"},
    {"0                 0"},
    {"0                 0"},
    {"  0             0  "},
    {"    0 0 0 0 0 0    "}};

    std::string bug[10] = {
        {"                   "},
        {"    0              "},
        {"  0 0 0 0          "},
        {"    0 0 0 0        "},
        {"    0 0 0   0      "},
        {"      0   0   0    "},
        {"        0   0 0    "},
        {"          0 0      "},
        {"                   "},
        {"                   "}};

    std::string rob[10] = {
        {"        0 0        "},
        {"      0     0      "},
        {"    0         0    "},
        {"    0 0000000 0    "},
        {"    0    0    0    "},
        {"    0    0    0    "},
        {"  0 0 0000000 0 0  "},
        {"    0         0    "},
        {"      0 0 0 0      "},
        {"  0 0 0     0 0 0  "}};

    //Set Sprites
    Slime.setSprite(slimed);
    Bob.setSprite(rob);
    Bug.setSprite(bug);

    //Map
    char map1[15][15]{
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#',' ','#',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#','#','#','#','#','#',' ',' ','#','#','#'},
        {'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#','S','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','E','#','#','#'}
    };

    //Test Hero item and skills
    Hero.addItem(bakuUno);
    Hero.addItem(bakuDos);
    Hero.addItem(bakuTres);
    Hero.addItem(baQuatro);

    Hero.addSkills(sampleUno);
    Hero.addSkills(sampleDos);
    Hero.addSkills(sampleTres);
    Hero.addSkills(sampleQuatro);

    //Test Map
    Map maple("Map 1", 1, 1, 15, 11);
    maple.setMap(map1);
    maple.addMobs(Slime, 25);
    maple.addMobs(Bug, 10);
    maple.addMobs(Bob, 10);

    //Test Shop
    Shop shop("Testing");
    shop.addItems(bakuUno, 999);
    shop.addItems(bakuDos, 999);
    shop.addItems(bakuTres, 999);
    shop.addItems(baQuatro, 999);

    startSwitch = startMenu();

    switch(startSwitch){
        case 0:
            system("CLS");
            std::cout << "\n\n\tWELCOME!! THIS IS JUST A CODING PLAYGROUND WHERE I TRY TO APPLY WHAT";
            std::cout << "\n\tI'VE LEARNED WITH THE TUTORIALS I'VE WATCHED, IT MAY NOT BE POLISHED";
            std::cout << "\n\tAS I'M TRYING TO GRASP EACH FOUNDATION AT FIRST. THIS CONSOLE GAME JUST";
            std::cout << "\n\tCOVERS THE BASIC AND ROUGH IMPLEMENTATIONS OF WHAT I'VE WANTED TO DO.";
            std::cout << "\n\tIT USES RANDS, FUNCTION OVERLOADING, OBJECTS, AND OTHER SIMPLE STUFF";
            std::cout << "\n\n\t USE THE ARROW KEYS TO MOVE AND SPACE TO SHOW THE MENU";
            std::cout << "\n\n\n\t AGAIN, THESE ARE JUST BASIC CONCEPTS OF C++ AND PROGRAMMING IN GENERAL...";
            system("Pause");
            break;
        case 1:
            return 0;
        default:
            return 0;
    }

    maple.exploreMap(Hero, shop);

    system("CLS");
    std::cout << "THANK YOU FOR PLAYING!";

    return 0;
}