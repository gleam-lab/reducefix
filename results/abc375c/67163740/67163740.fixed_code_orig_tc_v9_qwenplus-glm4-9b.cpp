#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    double x = 0, y = 0;
    double total_cost = 0;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        total_cost += sqrt((x - a) * (x - a) + (y - b) * (y - b));
        x = a;
        y = b;
    }

    // Add the distance from the last point to the origin
    total_cost += sqrt((x - 0) * (x - 0) + (y - 0) * (y - 0));

    cout << fixed << setprecision(10) << total_cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}