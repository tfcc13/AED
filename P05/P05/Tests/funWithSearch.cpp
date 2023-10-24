#include "funWithSearch.h"


//=============================================================================
// Exercise 1: Elementary Search
//=============================================================================
// Subexercise 1.1: Linear Search
//=============================================================================
// TODO
int FunWithSearch::searchLinear(const vector<int> &v, int key) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i]  == key) return i;
    }

    return -1;

}

//=============================================================================
// Subexercise 1.2: Binary Search
//=============================================================================
// TODO
int FunWithSearch::searchBinary(const vector<int> & v, int key) {
    int end = (int) v.size() -1;
    int start = 0;

    while (start <= end) {

        int middle = start + (end - start) / 2;

        if (key < v[middle]) {
            end = middle -1;
        }

        else if (key > v[middle] ) {
            start = middle+1;
        }
        else return middle;
    }
    return -1;
}

//=============================================================================
// Exercise 2: Facing Sun
//=============================================================================
// TODO
int FunWithSearch::facingSun(const vector<int> & values) {
    return 0;
}


//=============================================================================
// Exercise 3: Square Root
//=============================================================================
// TODO
int FunWithSearch::squareR(int num) {
    return 0;
}


//=============================================================================
// Exercise 5: MinPages (extra)
//=============================================================================
// TODO
int FunWithSearch::minPages(const vector<int> & values, int numSt) {
    return 0;
}
