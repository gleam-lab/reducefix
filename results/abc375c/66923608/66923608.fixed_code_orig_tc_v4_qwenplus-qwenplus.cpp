#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// Use long double for higher precision to minimize floating-point errors
long double euclid(long double x1, long double y1, long double x2, long double y2) {
    long double dx = x1 - x2;
    long double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long double> x(n + 2), y(n + 2); // +2 to include origin at start and end

    // Read all points
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    // Set origin at start and end
    x[0] = 0; y[0] = 0;
    x[n + 1] = 0; y[n + 1] = 0;

    long double ans = 0.0;

    // Compute total distance
    for (int i = 0; i <= n; ++i) {
        ans += euclid(x[i], y[i], x[i + 1], y[i + 1]);
    }

    // Output with sufficient precision
    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}