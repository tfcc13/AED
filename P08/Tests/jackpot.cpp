#include "jackpot.h"


Bet::Bet(vector<int> ns, string p): numbers(ns), player(p) {}

vector<int> Bet::getNumbers() const {
    return numbers;
}

string Bet::getPlayer() const {
    return player;
}

Jackpot::Jackpot()  {}

unsigned Jackpot::getNumBets() const {
    return bets.size();
}


//=============================================================================
// Exercise 2: Jackpot
//=============================================================================
// Subexercise 2.1: Add Bet
//=============================================================================
// TODO
void Jackpot::addBet(const Bet& b) {
    bets.insert(b);
}

//=============================================================================
// Subexercise 2.2: Bets in Number
//=============================================================================
// TODO
unsigned Jackpot::betsInNumber(unsigned num) const {
	unsigned count = 0;

    for(auto bet : bets) {
        vector<int> numbersBet = bet.getNumbers();
        auto it = find(numbersBet.begin(),numbersBet.end(),int(num));
        if(it != numbersBet.end()) {
            count++;
        }
    }

	return count;
}

//=============================================================================
// Subexercise 2.3: Drawn Bets
//=============================================================================
// TODO
vector<string> Jackpot::drawnBets(vector<int> draw) const {
	vector<string> res;
    unordered_set<int> drawSet;

    for (int i = 0; i < draw.size(); i++) {
        drawSet.insert(draw[i]);
    }

    for(auto bet :bets) {
        int count = 0;
        for(int j = 0; j < bet.getNumbers().size(); j++) {
            if(drawSet.find(bet.getNumbers()[j]) != drawSet.end()) {
                count++;
            }
        }
        if(count > 3) {
            res.push_back(bet.getPlayer());
        }
    }

	return res;
}
