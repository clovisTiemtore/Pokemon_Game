#include "headers/PokemonCard.h"
#include <iostream>

using namespace std;

PokemonCard::PokemonCard(
    const string& name,
    const string& type,
    const string& family,
    int evolutionLevel,
    int maxHP,
    const string& atk1Name, int atk1Damage, int atk1Cost,
    const string& atk2Name, int atk2Damage, int atk2Cost)
    : Card(name),
      pokemonType(type),
      familyName(family),
      evolutionLevel(evolutionLevel),
      maxHP(maxHP),
      hp(maxHP)
{
    attacks.push_back({atk1Name, atk1Damage, atk1Cost, 0});
    attacks.push_back({atk2Name, atk2Damage, atk2Cost, 0});
}


void PokemonCard::displayInfo() const {
    cout << "Pokemon: " << getCardName()
         << " | Type: " << pokemonType
         << " | Family: " << familyName
         << " | Evolution: " << evolutionLevel
         << " | HP: " << hp << "/" << maxHP
         << endl;

    for (size_t i = 0; i < attacks.size(); ++i) {
        cout << "Attack " << i + 1 << ": "
             << attacks[i].name
             << " | Damage: " << attacks[i].damage
             << " | Cost: " << attacks[i].cost
             << " | Energy: " << attacks[i].currentEnergy
             << endl;
    }
}

void PokemonCard::heal() {
    hp = maxHP;
}

void PokemonCard::takeDamage(int dmg) {
    hp -= dmg;
    if (hp < 0) hp = 0;
}

void PokemonCard::attachEnergyOneUnit() {
    for (auto& atk : attacks) {
        if (atk.currentEnergy < atk.cost) {
            atk.currentEnergy++;
        }
    }
}

bool PokemonCard::canUseAttack(int idx) const {
    if (idx < 0 || idx >= (int)attacks.size()) return false;
    return attacks[idx].currentEnergy >= attacks[idx].cost;
}

int PokemonCard::useAttack(int idx) {
    if (!canUseAttack(idx)) return 0;
    attacks[idx].currentEnergy = 0;
    return attacks[idx].damage;
}

int PokemonCard::getHP() const {
    return hp;
}

int PokemonCard::getMaxHP() const {
    return maxHP;
}

const Attack& PokemonCard::getAttack(int idx) const {
    return attacks[idx];
}
