#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    ll total_cost = 0;
    ll x = 0, y = 0;

    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        total_cost += abs(a - x) + abs(b - y);
        total_cost += (a - x) * (a - x) + (b - y) * (b - y);
        x = a;
        y = b;
    }

    total_cost += abs(x) + abs(y);
    total_cost += x * x + y * y;

    cout << fixed << setprecision(6) << sqrt(total_cost) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}