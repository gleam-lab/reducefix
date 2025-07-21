#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    double x = 0.0, y = 0.0, total = 0.0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        total += hypot(x - a, y - b);
        x = a;
        y = b;
    }
    total += hypot(x, y);
    cout << fixed << setprecision(15) << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}