// https://open.kattis.com/problems/loorolls

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll l, n, k = 1;

    cin >> l >> n;

    while (l % n)
    {
        n -= l % n;
        k++;
    }

    cout << k << endl;
    return 0;
}