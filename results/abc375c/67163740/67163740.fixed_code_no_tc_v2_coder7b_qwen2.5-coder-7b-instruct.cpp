#include <bits/stdc++.h>
using namespace std;
using ll = long double; // Use long double for higher precision

void solve() {
    int n;
    ll x = 0, y = 0, t = 0;
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        t += sqrtl((x - a) * (x - a) + (y - b) * (y - b)); // Use sqrtl for long double
        x = a;
        y = b;
    }
    t += sqrtl(x * x + y * y); // Use sqrtl for long double
    cout << fixed << setprecision(10) << t << endl; // Set precision to 10 decimal places
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}