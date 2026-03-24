// https://open.kattis.com/problems/hailstone

#include <iostream>
#define ll unsigned long long int

using namespace std;

ll CollatzSum(const ll n) {
    if (n == 1)
        return 1;
    
    if (n & 1)
        return n + CollatzSum(3 * n + 1);
    
    return n + CollatzSum(n / 2);
}

int main() {
    ll n;

    cin >> n;

    cout << CollatzSum(n) << endl;
}