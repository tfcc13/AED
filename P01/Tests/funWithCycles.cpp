#include "funWithCycles.h"
#include <algorithm>
//=============================================================================
// Exercise 1: Palindromes
//=============================================================================
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    int k = s.length();

    for (int i = 0; i < k/2; i++) {
        if (s[i] != s[k-i-1]) return false;
    }

    return true;
}


//=============================================================================
// Exercise 2: Palindrome Sentences
//=============================================================================
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    int k = s.length();
    std::string str = "";
    for (int i = 0; i < k; i++) {
        if (isalpha(s[i])) {
            str += toupper(s[i]);
        }
    }

    return palindrome(str);


}


//=============================================================================
// Exercise 3: Interesting Numbers
//=============================================================================
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    n++;
    while (digitSum(n) != sum) {
        n++;
    }
    return n;
}

// This auxiliary function should return the sum of the digits of n
// TODO
int FunWithCycles::digitSum(int n) {

    int sum = 0;

    while (n > 0) {
        sum += n%10;
        n /= 10;
    }

    return sum;
}


//=============================================================================
// Exercise 4: Winter is coming
//=============================================================================
// TODO
int FunWithCycles::winter(const vector<int> & v) {

    int size = v.size();
    int k = 0;
    int count = 0, max = 0;

    while (k < size -1) {
        if (v[k + 1] < v[k]) {
            count++;
            k++;
            if (count > max) {
                max = count;
            }
        } else {
            count = 0;
            k++;
        }
    }
    return max;
}


//=============================================================================
// Exercise 5: Playing with vectors
//=============================================================================

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    std::vector<int>::const_iterator number;
    int count = 0;
    for (number = v.begin(); number != v.end(); number++) {
        if (*number == n) count++;
    }

    return count;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    std::vector<int>::const_iterator number;

    for (number = v.begin(); number != v.end(); number++) {
        if (std::count(v.begin(),v.end(),*number) > 1) return true;
    }
    return false;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {
    std::vector<int>::iterator number;
    std::vector<int> aux;

    for (number = v.begin(); number != v.end(); number++){
        if (std::find(aux.begin(), aux.end(),*number) == aux.end()) {
            aux.push_back(*number);
        }
    }
    v = aux;
}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    int sizev1 = v1.size();
    int sizev2 = v2.size();
    int k = 0;
    int j = 0;
    while (k < sizev1 && j < sizev2 ) {
            if (v1[k] > v2[j]) {
                ans.push_back(v2[j]);
                j++;
            } else if (v1[k] == v2[j]) {
                ans.push_back(v1[k]);
                ans.push_back(v2[j]);
                j++;
                k++;
            } else {
                ans.push_back(v1[k]);
                k++;
            }
        }

    while (k < sizev1) {
        ans.push_back(v1[k]);
        k++;
    }
    while (j < sizev2) {
        ans.push_back(v2[j]);
        j++;
    }
    return ans;
}


//=============================================================================
// Exercise 6: Playing with prime numbers
//=============================================================================

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {

    for (int i = 2; i < n; i++) {
        if (n%i == 0) return false;
    }

    return true;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;

    for (int i = 2; i <= n; i++) {
        while (n % i == 0 && isPrime(i) ) {
            ans.push_back(i);
            n /= i;
        }
    }
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<bool> fake_primes(n+1,true);
    vector<int> ans;

    for (int i = 2; i*i <n; i++) {
        if (fake_primes[i]) {
            for (int p = i*i; p<= n; p+= i) {
                fake_primes[p] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++){
        if (fake_primes[i]) ans.push_back(i);
    }

    return ans;
}
