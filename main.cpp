#include "headers/Card.h"
#include "headers/PokemonCard.h"
#include "headers/EnergyCard.h"
#include "headers/TrainerCard.h"
#include "headers/Player.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Player p1("Clovis");
    Player p2("Hadi");

    PokemonCard* pikachu = new PokemonCard(
        "Pikachu", "Electric", "Pikachu", 0, 100,
        "Thunder Shock", 20, 2,
        "Thunderbolt", 40, 3);

    PokemonCard* Bulbasaur = new PokemonCard(
        "Bulbasaur", "Grass", "Bulbasaur", 0, 90,
        "Vine Whip", 15, 1,
        "Razor Leaf", 30, 2);

    EnergyCard* electricEnergy = new EnergyCard("Electric Energy", "Electric");
    TrainerCard* potion = new TrainerCard("Potion", "Heal active Pokemon");

    p1.addCardToBench(pikachu);
    p1.addCardToBench(electricEnergy);
    p1.addCardToBench(potion);

    p2.addCardToBench(Bulbasaur);

    p1.displayBench();
    p2.displayBench();

    p1.activatePokemonCard(0);
    p2.activatePokemonCard(0);

    p1.displayAction();
    p2.displayAction();

    p1.attachEnergyCard(0, 0);

    p1.attack(0, 0, p2, 0);

    p1.useTrainer(0);

    p1.displayAction();
    p2.displayAction();

    return 0;
}
