#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    double x = 0, y = 0, total_cost = 0;
    cin >> n;
    while (n--) {
        double a, b;
        cin >> a >> b;
        total_cost += sqrt((x - a) * (x - a) + (y - b) * (y - b));
        x = a;
        y = b;
    }
    total_cost += sqrt(x * x + y * y);
    cout << fixed << setprecision(20) << total_cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}