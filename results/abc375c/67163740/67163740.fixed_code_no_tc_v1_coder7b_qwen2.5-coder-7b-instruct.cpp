#include <bits/stdc++.h>
using namespace std;
using ll = long double; // Changed to long double for higher precision

void solve() {
    int n;
    ll x = 0, y = 0, t = 0; // Changed data type of t to long double
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        t += sqrtl((x - a) * (x - a) + (y - b) * (y - b)); // Changed sqrt to sqrtl for long double
        x = a;
        y = b;
    }
    t += sqrtl(x * x + y * y); // Changed sqrt to sqrtl for long double
    cout << setprecision(20) << fixed << t << endl; // Fixed precision setting
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}