#include "characters.h"
#include "overworld.h"

//Character Constructor
Characters::Characters(std::string name, int HP, int MP, int ATK, int DEF, int SPD){
    this->charName = name;
    this->maxHP = HP;
    this->maxMP = MP;
    this->HP = HP;
    this->MP = MP;
    this->ATK = ATK;
    this->DEF = DEF;
    this->SPD = SPD;
}

//Add Items inside character inventory
void Characters::addItem(Items item){
    bool sameItem = false;

    for (int x = 0; x < inv.size(); x++){
        if (inv[x] == item){
            inv[x].qty++;
            sameItem = true;
            break;
        }
    }

    if (!sameItem){
        inv.push_back(item);
    }
}

//Add Skills for character
void Characters::addSkills(Skills skill){
    skillList.push_back(skill);
}

//Skill Constructor
Skills::Skills(std::string name, int dmg, int mpCost, std::string desc){
    this->name = name;
    this->dmg = dmg;
    this->mpCost = mpCost;
    this->desc = desc;
}

//Item Constructor
Items::Items(std::string name, int dmg, int cost, std::string desc){
    this->name = name;
    this->dmg = dmg;
    this->cost = cost;
    this->desc = desc;
}

//Mob Constructor
Mobs::Mobs(std::string name, int HP, int MP, int ATK, int DEF, int SPD, int EXP){
    this->mobName = name;
    this->maxHP = HP;
    this->HP = HP;
    this->maxMP = MP;
    this->MP = MP;
    this->ATK = ATK;
    this->DEF = DEF;
    this->SPD = SPD;
    this->EXP = EXP;
}

void Mobs::setSprite(std::string sprite[10]){
    for (int x = 0; x < 10; x++){
        this->sprite[x] = sprite[x];
    }
}

void Mobs::showSprite(){
    for (int x = 0; x < 10; x++){
        //Center Sprite
        for (int y = 0; y < 13; y++) {std::cout << " ";}
        //Print sprite
        setColor(14);
        std::cout << this->sprite[x] << std::endl;
    }

    setColor(15);
}