/*

A k-multiple free set is a set of integers where there is no pair of integers
where one is equal to another integer multiplied by k.

For example for k = 2, {1,3,4} is a valid set, but not {2,4,5}, as 4 is double of 2.

You will be given n and k. you have to determine the largest k-multiple free subset
of the integers from 1 to n.

# Input
    First line of the input contains T (1 ≤ T ≤ 1000) the number of test case.
    Then following lines contains T test cases. Each case contains a line
    containing 2 integers n (1 ≤ n ≤ 1000000000) and k (2 ≤ k ≤ 100).

# Output
    For each test case output contains 1 integer the size of the largest k-multiple
    free subset of the integers from 1 to n.

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, n, k;

    cin >> T;

    while (T--) {
        cin >> n >> k;

        int r = n;
        vector<bool> memo(n + 1);

        for (int i = 1; i * k <= n; i++)
            if (!memo[i])
                r -= memo[i * k] = 1;

        cout << r << endl;
    }

    return 0;
}