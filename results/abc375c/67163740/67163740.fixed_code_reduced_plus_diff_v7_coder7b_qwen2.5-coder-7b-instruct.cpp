#include <bits/stdc++.h>
using namespace std;
using ld = long double;

void solve() {
    int n;
    ld x = 0, y = 0, t = 0;
    cin >> n;
    while (n--) {
        ld a, b;
        cin >> a >> b;
        t += sqrtl((x - a) * (x - a) + (y - b) * (y - b));
        x = a;
        y = b;
    }
    t += sqrtl(x * x + y * y);
    cout << setprecision(20) << fixed << t << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}