#include <bits/stdc++.h>
using namespace std;
using ll = long double; // Changed float to long double for higher precision

void solve() {
    int n;
    ll x = 0, y = 0, t = 0; // Initialize all variables as long double
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        t += sqrtl((x - a) * (x - a) + (y - b) * (y - b)); // Use sqrtl for long double
        x = a;
        y = b;
    }
    t += sqrtl(x * x + y * y); // Add distance back to origin using sqrtl
    cout << setprecision(20) << fixed << t << endl; // Set precision and use fixed for decimal points
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}