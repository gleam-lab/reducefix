#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

double euclid(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    double total = 0.0;

    vector<double> x(n + 2), y(n + 2);  // +2 to include origin at start and end

    x[0] = 0.0;
    y[0] = 0.0;

    rep(i, n) {
        cin >> x[i + 1] >> y[i + 1];
    }
    x[n + 1] = 0.0;
    y[n + 1] = 0.0;

    for (int i = 0; i <= n; ++i) {
        total += euclid(x[i], y[i], x[i + 1], y[i + 1]);
    }

    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}