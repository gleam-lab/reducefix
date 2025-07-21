#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

double euclideanDistance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n + 2), y(n + 2); // +2 to include origin at both ends

    // Read input points
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    // Add the origin at the beginning and end
    x[0] = 0; y[0] = 0;
    x[n + 1] = 0; y[n + 1] = 0;

    double totalCost = 0.0;
    for (int i = 0; i <= n; ++i) {
        totalCost += euclideanDistance(x[i], y[i], x[i + 1], y[i + 1]);
    }

    cout << fixed << setprecision(12) << totalCost << endl;

    return 0;
}