#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ld dist(const ld& x1, const ld& y1, const ld& x2, const ld& y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
    int n;
    cin >> n;
    vector<ld> xs(n + 1), ys(n + 1);
    xs[0] = ys[0] = 0.0;
    for (int i = 1; i <= n; ++i) {
        cin >> xs[i] >> ys[i];
    }
    
    ld total_cost = 0.0;
    for (int i = 1; i <= n; ++i) {
        total_cost += dist(xs[i], ys[i], xs[i - 1], ys[i - 1]);
    }
    total_cost += dist(xs[n], ys[n], xs[0], ys[0]);
    
    cout << setprecision(20) << total_cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}