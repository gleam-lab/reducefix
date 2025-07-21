#include <bits/stdc++.h>
using namespace std;
using ll = long double;

void solve() {
    int n;
    ll x = 0, y = 0, t = 0;
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        t += sqrtl((x - a) * (x - a) + (y - b) * (y - b));
        x = a;
        y = b;
    }
    t += sqrtl(x * x + y * y);
    cout << setprecision(20) << t << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}