/*

One day, an ant called Alice came to an M*M chessboard.
She wanted to go around all the grids.
So she began to walk along the chessboard according to this way: 
(you can assume that her speed is one grid per second)

At the first second, Alice was standing at (1,1).
Firstly she went up for a grid, then a grid to the right, a grid downward.
After that, she went a grid to the right, then two grids upward,
and then two grids to the left. In a word, the path was like a snake.

For example, her first 25 seconds went like this:
( the numbers in the grids stands for the time when she went into the grids)

5   25 24 23 22 21
4   10 11 12 13 20
3   9  8  7  14 19
2   2  3  6  15 18
1   1  4  5  16 17

    1  2  3  4  5

At the 8-th second , she was at (2,3), and at 20-th second, she was at (5,4).
Your task is to decide where she was at a given time
(you can assume that M is large enough).

# Input
    Input file will contain several lines, and each line contains a number
    N (1 ≤ N ≤ 2∗10^9),which stands for the time.
    The file will be ended with a line that contains a number ‘0’.

# Output
    For each input situation you should print a line with two numbers (x,y),
    the column and the row number, there must be only a space between them.

*/

#include <iostream>
#define ll long long int
#define pii pair<int, int>

using namespace std;

double Sqrt(int n) {
    double inf = 1, sup = n;
    
    while (sup - inf > 0.001){
        const double m = (inf + sup) / 2;

        if (m * m < n)
            inf = m;
        else
            sup = m;
    }

    return sup;
}

pii Calcular(int n) {
    const ll y = Sqrt(n);
    const ll x = y + 1;
    
    const int m = ((x * x + y * y) / 2) + 1;
    
    if (n == m)
        return pii(x, x);
    
    int r1, r2;
        
    if (n == y * y) {
        r1 = y;
        r2 = 1;
    }
    else {
        r1 = (n < m) ? x : x - (n - m);
        r2 = (n > m) ? x : x - (m - n);
    }
    
    if (y & 1) {
        r1 ^= r2;
        r2 ^= r1;
        r1 ^= r2;
    }

    return pii(r1, r2);
}

int main() {
    int N;

    while (true) {
        cin >> N;

        if (!N) break;

        pii result = Calcular(N);

        cout << result.first << " " << result.second << endl;
    }
}