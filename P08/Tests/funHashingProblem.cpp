#include "funHashingProblem.h"

FunHashingProblem::FunHashingProblem() {}


//=============================================================================
// Exercise 1: Find Duplicates
//=============================================================================
// TODO
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    vector<int> res;
    unordered_set<int> aux;
    for (int i = 0; i < values.size(); i++) {
        if(aux.find(values[i]) != aux.end()) {
            res.push_back(values[i]);
        }
        aux.insert(values[i]);
        if (i>=k) {
            aux.erase(values[i-k]);

        }
    }

    return res;
}
