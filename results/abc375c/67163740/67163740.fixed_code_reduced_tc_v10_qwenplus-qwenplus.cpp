#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    double x = 0.0, y = 0.0;
    double total = 0.0;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        total += hypot(x - a, y - b);
        x = a;
        y = b;
    }
    
    total += hypot(x, y);
    
    // Set sufficient precision for output (15-17 digits to ensure <1e-6 relative error)
    cout << fixed << setprecision(15) << total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}