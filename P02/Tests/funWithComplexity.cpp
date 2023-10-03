#include "funWithComplexity.h"
#include <cmath>
//=============================================================================
// Exercise 4: Analyzing a river
//=============================================================================
// TODO
int FunWithComplexity::river(const vector<int> & v, int k, int t) {

    int aux = 0;
    int res = 0;

    for (int i = 0; i < k; i++) {
        if (v[i] >= t) aux++;
    }

    if (aux >= k/2.0) res++;

    for (int j = k; j < v.size(); j++) {
        if (v[j-k] >= t) aux--;
        if (v[j] >= t) aux++;
        if (aux >= k/2.0) res++;
    }

    return res;
}

//=============================================================================
// Exercise 5: Spiral of Numbers
//=============================================================================
// TODO
pair<int, int> FunWithComplexity::spiral(int n) {
    if (n == 1) {
        return std::make_pair(0,0);
    }

    int x = 0;
    int y = 0;

    int l, d;
    l = (sqrt(n));

    d = (l*l) - n  ;

    if (d<l) {
        x = d;
        y = d;
    }

    else {
        x = l;
        y = (2*l)-d-1;
    }



    pair<int, int> ans = {x, y};
    return ans;
}


//=============================================================================
// Exercise 7: Squared notebook
//=============================================================================
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}