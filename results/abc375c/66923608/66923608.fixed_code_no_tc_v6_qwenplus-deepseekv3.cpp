#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

double Euclid(double x1, double x2, double y1, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n; cin >> n;
    double ans = 0;
    int prev_x = 0, prev_y = 0; // Starting from origin (0, 0)

    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    // Distance from origin to first point
    ans += Euclid(prev_x, x[0], prev_y, y[0]);

    // Distances between consecutive points
    rep(i, n - 1) {
        ans += Euclid(x[i], x[i + 1], y[i], y[i + 1]);
    }

    // Distance from last point back to origin
    ans += Euclid(x[n - 1], 0, y[n - 1], 0);

    cout << fixed << setprecision(12) << ans << endl;
}