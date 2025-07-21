#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ld distance(ll x1, ll y1, ll x2, ll y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void solve() {
    int n;
    double x = 0, y = 0, total_cost = 0.0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        total_cost += distance(x, y, a, b);
        x = a;
        y = b;
    }
    total_cost += distance(x, y, 0, 0);
    cout << setprecision(20) << fixed << total_cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}