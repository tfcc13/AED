#include "funListStackQueueProblem.h"
#include "cell.h"

FunListStackQueueProblem::FunListStackQueueProblem() {}


//=============================================================================
// Exercise 1: Remove Higher
//=============================================================================
// TODO
list<int> FunListStackQueueProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    list<int>::iterator it;
    for (it = values.begin(); it  !=  values.end(); it++){
        if (*it > x) {
            l1.push_back(*it);
            it = values.erase(it);
            it--;
        }
    }

    return l1;
}


//=============================================================================
// Exercise 2: Overlapping Intervals
//=============================================================================
//TODO
list<pair<int,int>> FunListStackQueueProblem::overlappingIntervals(list<pair<int,int>> values) {
    list<pair<int,int>> res;
    values.sort();
    list<pair<int,int>>::iterator itPair = values.begin();
    res.push_back(*itPair);
    itPair++;

    for (itPair = itPair; itPair != values.end(); itPair++) {
        if (itPair->first <= res.back().second) {
            if(itPair->second > res.back().second) {
                res.back().second = itPair->second;
            }
        }
        else {
            res.push_back(*itPair);
        }
    }

    return res;
}


//=============================================================================
// Exercise 4: Binary Numbers
//=============================================================================
// TODO
vector<string> FunListStackQueueProblem::binaryNumbers(int n) {
    vector<string> res;
    return res;
}


//=============================================================================
// Exercise 5: Calculate Span
//=============================================================================
//TODO
vector<int> FunListStackQueueProblem::calculateSpan(vector<int> prices) {
    vector<int> res;
    return res;
}


//=============================================================================
// Exercise 7: Knight Jumps
//=============================================================================
//TODO
int FunListStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {
    return -1;
}
