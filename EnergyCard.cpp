#include "headers/EnergyCard.h"
#include <string>
#include <iostream>
using namespace std;

EnergyCard::EnergyCard(const string& name, const string& type)
    : Card(name), energyType(type) {}

void EnergyCard::displayInfo() const {
    cout << "Energy Card: " << getCardName()
         << " | Type: " << energyType << endl;
}

string EnergyCard::getEnergyType() const {
    return energyType;
}