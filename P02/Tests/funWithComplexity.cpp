#include "funWithComplexity.h"

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
    pair<int, int> ans = {0, 0};
    return ans;
}


//=============================================================================
// Exercise 7: Squared notebook
//=============================================================================
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}