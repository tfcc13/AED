#include "funSortProblem.h"
#include <iomanip>
FunSortProblem::FunSortProblem() {}


//=============================================================================
// Exercise 4: Min Difference
//=============================================================================
// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {

    if (nc > unsigned(values.size())) return -1;

    vector<unsigned> copyValue = values;

    std::sort(copyValue.begin(),copyValue.end());


    unsigned diff = copyValue[nc-1]-copyValue[0];;
    for (unsigned i = 1; i < copyValue.size();i++) {
        if (nc+i > copyValue.size()) break;
        if((copyValue[nc-1+i] - copyValue[i] ) < diff) {
            diff = copyValue[nc-1+i] - copyValue[i];
        }
    }


    return diff;
}


//=============================================================================
// Exercise 6: Num Inversions (extra)
//=============================================================================
//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    return 0;
}


//=============================================================================
// Exercise 7: Nuts and Bolts (extra)
//=============================================================================
// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}
