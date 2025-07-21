#include <bits/stdc++.h>
using namespace std;

int main() {
    long double a, b, c, d, cou;
    int N;
    cin >> N;
    a = 0;
    b = 0;
    cou = 0;
    for (int i = 0; i < N; i++) {
        cin >> c >> d;
        cou += sqrtl((a - c) * (a - c) + (b - d) * (b - d));
        a = c;
        b = d;
    }
    cou += sqrtl(a * a + b * b);
    cout << fixed << setprecision(15) << cou << endl;
}