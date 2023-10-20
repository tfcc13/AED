#include "funSetProblem.h"

FunSetProblem::FunSetProblem() {}


//=============================================================================
// Exercise 2: FunSetProblem
//=============================================================================
// TODO
pair<int,int> FunSetProblem::pairSum(const vector<int> &values, int sum) {
    set<int> valSet;
    for (int val : values) {
        int comp = sum - val;

        if (valSet.find(comp) != valSet.end()){
            return make_pair(val, comp);
        }
        valSet.insert(val);
    }
    return make_pair(0,0);
}
