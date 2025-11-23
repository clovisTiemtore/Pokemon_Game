#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <string>
#include <vector>

using namespace std;

struct Attack {
    string name;
    int damage;
    int cost;
    int currentEnergy;
};

class PokemonCard : public Card {
private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<Attack> attacks;

public:
    PokemonCard(const string& name,
                const string& type,
                const string& family,
                int evolutionLevel,
                int maxHP,
                const string& atk1Name, int atk1Damage, int atk1Cost,
                const string& atk2Name, int atk2Damage, int atk2Cost);

    void displayInfo() const override;
    void heal();
    void takeDamage(int dmg);
    void attachEnergyOneUnit();
    bool canUseAttack(int idx) const;
    int useAttack(int idx);

    int getHP() const;
    int getMaxHP() const;
    const Attack& getAttack(int idx) const;
};

#endif
