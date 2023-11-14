#include "funPQProblem.h"

FunPQProblem::FunPQProblem() {}


//=============================================================================
// Exercise 2: Minimum Cost
//=============================================================================
// TODO
int FunPQProblem::minCost(const vector<int> &ropes) {
    int cost = 0;
    int tempRope = 0;

    priority_queue<int, std::vector<int>, std::greater<int>> ropesToConnect;

    for ( const int rope : ropes) {
        ropesToConnect.push(rope);
    }

    while(ropesToConnect.size() > 1) {
        tempRope = 0;
        tempRope += ropesToConnect.top();
        ropesToConnect.pop();
        tempRope += ropesToConnect.top();
        ropesToConnect.pop();
        cost += tempRope;
        ropesToConnect.push(tempRope);
    }


    return cost;
}
