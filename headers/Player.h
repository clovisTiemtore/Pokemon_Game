#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include <string>
#include <vector>
using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;

public:
    Player(const string& name);

    string getPlayerName() const;

    void addCardToBench(Card* card);
    void activatePokemonCard(int benchIndex);
    void attachEnergyCard(int benchIndex, int actionIndex);
    void attack(int myActionIdx, int attackIdx, Player& opponent, int opponentActionIdx);
    void useTrainer(int benchIndex);

    void displayBench() const;
    void displayAction() const;
};

#endif
