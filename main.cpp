#include <iostream>
#include <time.h>
#include <cmath>
#include <string>
#include <windows.h>

int main() {
    srand(time(NULL)); // randomising seed
    // Creature Attributes
    int Human_Health = 9, Human_Dmg = 4, Human_rand = 2;
    int Zombie_Health = 6, Zombie_Dmg = 12, Zombie_rand = 3;
    std::string teams[2] = {"Zombies", "Humans"};
    int alive;
    int winner;

    // User Input
    int Humans, Zombies;
    
    std::cout << "Humans: ";
    std::cin >> Humans;

    std::cout << "Zombies: ";
    std::cin >> Zombies;

    // Total Health
    int Total_Human_Health = Human_Health*Humans;
    int Total_Zombie_Health = Zombie_Health*Zombies;

    // Game loop
    bool Battling = false;
    int Rounds = 0;
    while (Battling == false) {
        // Human Attack
        if (rand()%Human_rand == 1) {
            Total_Zombie_Health -= Human_Dmg;
        }
        else if (rand()%Zombie_rand == 1) {
            Total_Human_Health -= Zombie_Dmg;
        }

        ++Rounds;

        if (Total_Human_Health <= 0) {
            alive = round(Total_Zombie_Health/Zombie_Health);
            winner = 0;
            break;
        }
        else if (Total_Zombie_Health <= 0) {
            alive = round(Total_Human_Health/Human_Health);
            winner = 1;
            break;
        }
    }

    // Battle Statsb
    std::cout << "After " << Rounds << " great rounds and " << (Zombies+Humans)-alive << " Deaths...\n";
    Sleep(1600);
    std::cout << "...\n";
    Sleep(1600);
    std::cout << teams[winner] << " Wins!\n" << alive << " " << teams[winner] << " survived!";


}