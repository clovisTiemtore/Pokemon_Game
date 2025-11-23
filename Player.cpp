#include "headers/Player.h"
#include <iostream>
using namespace std;

Player::Player(const string& name) : playerName(name) {}

string Player::getPlayerName() const {
    return playerName;
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int benchIndex) {
    if (benchIndex >= 0 && benchIndex < (int)benchCards.size()) {
        PokemonCard* p = dynamic_cast<PokemonCard*>(benchCards[benchIndex]);
        if (p) {
            cout << playerName << " is activating a Pokemon Card: " << p->getCardName() << endl;
            actionCards.push_back(p);
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }
}

void Player::attachEnergyCard(int benchIndex, int actionIndex) {
    if (benchIndex >= 0 && benchIndex < (int)benchCards.size() &&
        actionIndex >= 0 && actionIndex < (int)actionCards.size()) {
        EnergyCard* e = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
        if (e) {
            cout << playerName << " is attaching Energy Card of type " 
                 << e->getEnergyType() << " to the Pokemon " 
                 << actionCards[actionIndex]->getCardName() << endl;
            actionCards[actionIndex]->attachEnergyOneUnit();
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }
}

void Player::attack(int myActionIdx, int attackIdx, Player& opponent, int opponentActionIdx) {
    if (myActionIdx >= 0 && myActionIdx < (int)actionCards.size() &&
        opponentActionIdx >= 0 && opponentActionIdx < (int)opponent.actionCards.size()) {
        if (actionCards[myActionIdx]->canUseAttack(attackIdx)) {
            string atkName = actionCards[myActionIdx]->getAttack(attackIdx).name;
            cout << playerName << " attacking " << opponent.getPlayerName()
                 << "'s Pokemon " << opponent.actionCards[opponentActionIdx]->getCardName()
                 << " with the Pokemon " << actionCards[myActionIdx]->getCardName()
                 << " using attack: " << atkName << endl;

            int dmg = actionCards[myActionIdx]->useAttack(attackIdx);
            cout << "Reducing " << dmg << " from " 
                 << opponent.actionCards[opponentActionIdx]->getCardName() << "'s HP" << endl;

            opponent.actionCards[opponentActionIdx]->takeDamage(dmg);

            if (opponent.actionCards[opponentActionIdx]->getHP() <= 0) {
                cout << "Pokemon " << opponent.actionCards[opponentActionIdx]->getCardName() << " is knocked out!" << endl;
            } else {
                cout << "Pokemon " << opponent.actionCards[opponentActionIdx]->getCardName() << " is still alive" << endl;
            }
        }
    }
}

void Player::useTrainer(int benchIndex) {
    if (benchIndex >= 0 && benchIndex < (int)benchCards.size()) {
        TrainerCard* t = dynamic_cast<TrainerCard*>(benchCards[benchIndex]);
        if (t) {
            cout << playerName << " is using the Trainer Card to \"" 
                 << t->getEffect() << "\"" << endl;

            for (auto* p : actionCards) {
                p->heal();
            }

            cout << t->getCardName() << " healed all your active Pokemon to full HP!" << endl;
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }
}

void Player::displayBench() const {
    cout << "Bench cards for Player " << playerName << ":" << endl;
    for (size_t i = 0; i < benchCards.size(); ++i) {
        benchCards[i]->displayInfo();
        cout << endl;
    }
}

void Player::displayAction() const {
    cout << "Action cards for Player " << playerName << ":" << endl;
    for (size_t i = 0; i < actionCards.size(); ++i) {
        actionCards[i]->displayInfo();
        cout << endl;
    }
}
