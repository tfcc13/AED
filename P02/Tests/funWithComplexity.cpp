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
    if (n == 1) {
        return std::make_pair(0,0);
    }

    int x = 0;
    int y = 0;
    int numb = 1;
    int spiral_level= 0;

    while (numb < n) {
        int move = 2*spiral_level+1;
        
        //moving right
        for (int i = 0; i < move && numb < n; i++ ) {
            x++;
            numb++;
        }




        //moving down

        for (int i = 0; i < move && numb  < n; i++){
            y--;
            numb++;
        }

        //moving left
        for (int i = 0; i < move && numb< n; i++)
        {
            x--;
            numb++;
        }

        //moving up

        for (int i = 0; i <move && numb< n; i++)
        {
            y++;
            numb++;
        }
        spiral_level++;



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