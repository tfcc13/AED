#ifndef JACKPOT_H_
#define JACKPOT_H_

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Bet {
    vector<int> numbers;
    string player;
public:
    Bet(vector<int> ns, string p);
    vector<int> getNumbers() const;
    string getPlayer() const;
};

//=============================================================================
// Exercise 2: Jackpot
//=============================================================================
struct betHash
{
    // Hash function
    // TODO
	int operator() (const Bet& b) const {
        return 0;
	}

    // Equality function
    // TODO
	bool operator() (const Bet& b1, const Bet& b2) const {
        /*vector<int> aux1 = b1.getNumbers();
        vector<int> aux2 = b2.getNumbers();

        sort(aux1.begin(),aux1.end());
        sort(aux2.begin(),aux2.end());

        for (int i = 0; i < b1.getNumbers().size(); i++){
            if (aux1[i] != aux2[i]) return false;
        }
        return true;*/

        unordered_set<int> auxSet;

        for (int i = 0; i < b1.getNumbers().size(); i++) {
            auxSet.insert(b1.getNumbers()[i]);
        }

        for (int i = 0; i < b1.getNumbers().size(); i++) {
            if(auxSet.find(b2.getNumbers()[i]) == auxSet.end()) {
                return false;
            }
        }
        return true;
	}
};


typedef unordered_set<Bet, betHash, betHash> tabHBet;

class Jackpot
{
	tabHBet bets;
public:
	Jackpot();
	void addBet(const Bet& ap);
	unsigned betsInNumber(unsigned num) const;
	vector<string> drawnBets(vector<int> draw) const;
    unsigned getNumBets() const;
};

#endif 
