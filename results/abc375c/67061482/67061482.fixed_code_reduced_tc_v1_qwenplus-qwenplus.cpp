#include <bits/stdc++.h>
using namespace std;

int main() {
    double a = 0.0, b = 0.0, c, d;
    int N;
    cin >> N;
    long double total = 0.0;

    for (int i = 0; i < N; ++i) {
        cin >> c >> d;
        total += sqrt((a - c) * (a - c) + (b - d) * (b - d));
        a = c;
        b = d;
    }

    total += sqrt(a * a + b * b);
    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}