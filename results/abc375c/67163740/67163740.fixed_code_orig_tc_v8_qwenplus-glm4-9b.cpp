#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll x = 0, y = 0, total_cost = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        total_cost += sqrt((x - a) * (x - a) + (y - b) * (y - b));
        x = a;
        y = b;
    }
    // Do not add the return journey to the origin to the total cost
    cout << fixed << setprecision(20) << total_cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}