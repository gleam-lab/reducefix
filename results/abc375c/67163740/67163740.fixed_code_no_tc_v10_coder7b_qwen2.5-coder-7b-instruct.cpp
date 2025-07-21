#include <bits/stdc++.h>
using namespace std;
using ll = long double; // Changed float to long double for higher precision

void solve() {
    int n;
    ll x = 0, y = 0, t = 0; // Changed float variables to long double for higher precision
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        t += sqrtl((x - a) * (x - a) + (y - b) * (y - b)); // Changed sqrt to sqrtl for long double
        x = a;
        y = b;
    }
    t += sqrtl(x * x + y * y); // Changed sqrt to sqrtl for long double
    cout << setprecision(20) << fixed << t << endl; // Added fixed for consistent decimal places
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}