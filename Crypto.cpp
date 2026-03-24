// https://open.kattis.com/problems/crypto

#include <iostream>
#define ll unsigned long long int

using namespace std;

int main() {
    ll N, k = 0, maxCantCeros = 0;

    cin >> N;

    for (int b = 2; b * b <= N; b++) {
        ll x = N, cantCeros = 0;

        while (!(x % b)) {
            cantCeros++;
            x /= b;
        }

        if (cantCeros > maxCantCeros) {
            maxCantCeros = cantCeros;
            k = b;
        }
        else if (cantCeros == maxCantCeros && b < k)
            k = b;
    }

    // if N es primo
    if (!k)
        k = N;
     
    cout << k << endl;
}