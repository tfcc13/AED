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

    int counter = 1;
    int max = values[0];

    for (int i = 1; i < values.size();i++) {
        if ( values[i] > max) {
    counter++;
    max = values[i];
}
    }
    return counter;
}


//=============================================================================
// Exercise 3: Square Root
//=============================================================================
// TODO
int FunWithSearch::squareR(int num) {
    double end = num;
    double start = 0;

    while ( true) {
        double sqrt = start + (end+start) / 2.0;
        if(int(sqrt * sqrt) > num) {
            end = end - (end+start) / 2.0;
        }
        else if (int(sqrt*sqrt) < num){
            start = start + (end+start)/ 2.0;
        }
        else {
            return int(sqrt);
        }
    }

}


//=============================================================================
// Exercise 5: MinPages (extra)
//=============================================================================
// TODO
int FunWithSearch::minPages(const vector<int> & values, int numSt) {
    return 0;
}
