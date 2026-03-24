// https://open.kattis.com/problems/aliennumbers

#include <iostream>
#include <map>
#include <algorithm>
#define ll long long int

using namespace std;


ll ToBase10(string k, string ogAlphabet) {
    map<char, int> index;

    for (int i = 0; ogAlphabet[i]; i++)
        index[ogAlphabet[i]] = i;
    
    ll mult = 1;
    ll r = 0;

    for (int i = k.size() - 1; i >= 0; i--) {
        r += index[k[i]] * mult;
        mult *= ogAlphabet.size();
    }

    return r;
}

string ToAlienBase(ll w, string A2) {
    string r = "";

    int div = A2.size();
    while (w >= div) {
        r += A2[w % div];
        w /= div;
    }

    r += A2[w];

    reverse(r.begin(), r.end());

    return r;
}

int main() {
    int T;
    string k, A1, A2;

    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> k >> A1 >> A2;

        ll w = ToBase10(k, A1);

        cout << "Case #" << i << ": " << ToAlienBase(w, A2) << endl; 
    }
}