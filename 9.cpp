// https://open.kattis.com/problems/nine

#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007LL
using namespace std;

ll expBin(ll base, ll exp)
{
    ll r = 1;
    base %= MOD;

    while (exp > 0)
    {
        if (exp & 1)
            r = (r * base) % MOD;

        base = (base * base) % MOD;
        exp >>= 1;
    }

    return r;
}

int main()
{
    int T;
    ll d;
    cin >> T;

    while (T--)
    {
        cin >> d;
        cout << ((ll)8 * expBin(9, d - 1)) % MOD << endl;
    }

    return 0;
}