#include <bits/stdc++.h>
using namespace std;
using ld = long double; // Use long double for higher precision

void solve() {
    int n;
    ld x = 0, y = 0, t = 0;
    cin >> n;
    while (n--) {
        ld a, b;
        cin >> a >> b;
        t += sqrtl((x - a) * (x - a) + (y - b) * (y - b)); // Use sqrtl for long double
        x = a;
        y = b;
    }
    t += sqrtl(x * x + y * y); // Use sqrtl for long double
    cout << setprecision(20) << t << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}