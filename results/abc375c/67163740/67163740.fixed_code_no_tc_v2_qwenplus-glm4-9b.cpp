#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll total_cost = 0;
    ll cx = 0, cy = 0;

    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        total_cost += ll(sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y)));
        cx = x;
        cy = y;
    }

    total_cost += ll(sqrt(cx * cx + cy * cy));
    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}