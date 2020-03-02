#include "battle-system.h"
#include "overworld.h"

//Display battle UI
void displayBattle(Characters &hero, Mobs &mob){
    bool battleOn = true, showMMenu = true, showSMenu = false, showIMenu = false;
    int bMenuPointer = 0;
    std::string menu[4] = {"ATTACK" , "SKILL", "ITEM", "RUN"};

    while (battleOn){
        system("CLS");
        setColor(15);
        //Main Battle UI
        std::cout << "==================================================";
        std::cout << "\n===== " << mob.mobName << "  =  HP: " << mob.HP << "\\" << mob.maxHP << "\t==================";
        std::cout << "\n==================================================\n\n";
        mob.showSprite();
        setColor(15);
        std::cout << "\n\n================================================";
        std::cout << "\n===== Lvl." << hero.LVL << " " << hero.charName << "\t\t================";
        std::cout << "\n===== HP: " << hero.HP << "\\" << hero.maxHP << " = MP: " << hero.MP << "\\" << hero.maxMP << " \t========";
        std::cout << "\n================================================\n";
        
        if (mob.HP <= 0){
            std::cout << "\n\nENEMY DEFEATED!! You have gained " << mob.EXP << " EXP!\n";
            system("PAUSE");
            hero.EXP += mob.EXP;
            battleOn = false;
        }
        else if (hero.HP <= 0){
            std::cout << "YOU HAVE BEEN DEFEATED......\n";
            system("PAUSE");
            battleOn = false;
        }
        else {
            for (int x = 0; x < 4; x++){
            if (bMenuPointer == x){
                setColor(11);
                //Show different menu with the same position
                if (showMMenu){
                    std::cout << menu[x] << std::endl;
                }
                else if (showSMenu){
                    std::cout << hero.skillList[x] << std::endl;
                }
                else if (showIMenu){
                    std::cout << hero.inv[x] << std::endl;
                }
            }
            else {
                setColor(15);
                if (showMMenu){
                    std::cout << menu[x] << std::endl;
                }
                else if (showSMenu){
                    std::cout << hero.skillList[x] << std::endl;
                }
                else if (showIMenu){
                    std::cout << hero.inv[x] << std::endl;
                }
            }
        }

        while (true){

            if(GetAsyncKeyState(VK_UP) != 0){
                bMenuPointer--;
                if (bMenuPointer < 0){
                    bMenuPointer = 3;
                }
                break;
            }

            else if(GetAsyncKeyState(VK_DOWN) != 0){
                bMenuPointer++;
                if (bMenuPointer > 3){
                    bMenuPointer = 0;
                }
                break;
            }

            else if(GetAsyncKeyState(VK_RETURN) != 0){
                switch (bMenuPointer){
                    case 0:
                        if (showMMenu){
                            damageCalc(hero, mob);
                            mobTurn(hero, mob);
                        }
                        else if (showSMenu){
                            useSkill(hero, mob, hero.skillList[bMenuPointer]);
                            showIMenu = false;
                            showMMenu = true;
                            showSMenu = false;
                            bMenuPointer = 0;
                        }
                        else if (showIMenu){
                            useItem(mob, hero.inv[bMenuPointer]);
                            showIMenu = false;
                            showMMenu = true;
                            showSMenu = false;
                            bMenuPointer = 0;
                        }
                        break;
                    case 1:
                        if (showMMenu){
                            showIMenu = false;
                            showMMenu = false;
                            showSMenu = true;
                            bMenuPointer = 0;
                        }
                        else if (showSMenu){
                            useSkill(hero, mob, hero.skillList[bMenuPointer]);
                            showIMenu = false;
                            showMMenu = true;
                            showSMenu = false;
                            bMenuPointer = 0;
                        }
                        else if (showIMenu){
                            useItem(mob, hero.inv[bMenuPointer]);
                            showIMenu = false;
                            showMMenu = true;
                            showSMenu = false;
                            bMenuPointer = 0;
                        }
                        break;
                    case 2:
                        if (showMMenu){
                            showIMenu = true;
                            showMMenu = false;
                            showSMenu = false;
                            bMenuPointer = 0;
                        }
                        else if (showSMenu){
                            useSkill(hero, mob, hero.skillList[bMenuPointer]);
                            showIMenu = false;
                            showMMenu = true;
                            showSMenu = false;
                            bMenuPointer = 0;
                        }
                        else if (showIMenu){
                            useItem(mob, hero.inv[bMenuPointer]);
                            showIMenu = false;
                            showMMenu = true;
                            showSMenu = false;
                            bMenuPointer = 0;
                        }
                        break;
                    case 3:
                        if (showMMenu){
                            battleOn = false;
                            system("CLS");
                            std::cout << "YOU HAVE FLED!!";
                        }
                        else if (showSMenu){
                            useSkill(hero, mob, hero.skillList[bMenuPointer]);
                            showIMenu = false;
                            showMMenu = true;
                            showSMenu = false;
                            bMenuPointer = 0;
                        }
                        else if (showIMenu){
                            useItem(mob, hero.inv[bMenuPointer]);
                            showIMenu = false;
                            showMMenu = true;
                            showSMenu = false;
                            bMenuPointer = 0;
                        }
                        break;
                }
                break;
            }

            else if(GetAsyncKeyState(VK_TAB) != 0){
                if (showSMenu){
                    showIMenu = false;
                    showMMenu = true;
                    showSMenu = false;
                }
                else if (showIMenu){
                    showIMenu = false;
                    showMMenu = true;
                    showSMenu = false;
                }
            }
        }
        }
        Sleep(200);  
    }
}

//Damage Calc for default attack command
void damageCalc(Characters &hero, Mobs &mob){
    mob.HP = mob.HP - (hero.ATK - mob.DEF);
}

//Offensive Items only because yeet
void useItem(Mobs &mob, Items &item){
    mob.HP -= (item.dmg - mob.DEF);
    item.qty--;
}

//Use skills
void useSkill(Characters &hero, Mobs &mob, Skills &skill){
    if (hero.MP < skill.mpCost){
        std::cout << "\nNOT ENOUGH MP!\n";
    }
    else {
        hero.MP -= skill.mpCost;
        mob.HP -= (skill.dmg - mob.DEF);
    }
}

//Mob counter-attack
void mobTurn(Characters &hero, Mobs &mob){
    if ((mob.ATK - hero.DEF) < 0){
        std::cout << "\nAMAZING! YOU GOT 0 DAMAGE!\n";
    }
    else {
        hero.HP = mob.ATK - hero.DEF;
    }
}