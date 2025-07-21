#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

double euclid(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n;
    cin >> n;

    vector<double> x(n), y(n);

    rep(i, n) {
        cin >> x[i] >> y[i];
    }

    double totalCost = 0.0;

    // From origin to first point
    totalCost += euclid(0, 0, x[0], y[0]);

    // Between all consecutive points
    for (int i = 0; i < n - 1; ++i) {
        totalCost += euclid(x[i], y[i], x[i+1], y[i+1]);
    }

    // From last point back to origin
    totalCost += euclid(x[n-1], y[n-1], 0, 0);

    cout << fixed << setprecision(12) << totalCost << endl;

    return 0;
}