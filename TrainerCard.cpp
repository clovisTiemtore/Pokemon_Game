#include "headers/TrainerCard.h"
#include <iostream>
using namespace std;

TrainerCard::TrainerCard(const string& name, const string& effect)
    : Card(name), effect(effect) {}

void TrainerCard::displayInfo() const {
    cout << "Trainer Card: " << getCardName()
         << " | Effect: " << effect << endl;
}

string TrainerCard::getEffect() const {
    return effect;
}
