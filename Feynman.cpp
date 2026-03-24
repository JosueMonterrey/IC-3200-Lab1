#include <iostream>
#include <iomanip>

using namespace std;

double Cbrt(const double N) {
    double inf = 0, sup = N;

    while (sup - inf > 0.00001) {
        const double m = (inf + sup) / 2;

        if (m * m * m < N)
            inf = m;
        else
            sup = m;
    }

    return sup;
}

int main() {
    double N;

    // cout << fixed << setprecision(4);

    while (true) {
        cin >> N;

        if (!N) break;

        cout << Cbrt(N) << endl;
    }
    return 0;
}