#include <bits/stdc++.h>
using namespace std;

int main() {
    double a = 0, b = 0, c, d, cou = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> c >> d;
        cou += sqrt((a - c) * (a - c) + (b - d) * (b - d));
        a = c;
        b = d;
    }
    cou += sqrt(a * a + b * b);
    cout.precision(15);
    cout << cou << endl;
    return 0;
}