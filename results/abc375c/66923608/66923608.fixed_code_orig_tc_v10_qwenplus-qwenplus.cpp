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

    vector<pair<double, double>> points(n + 2); // Include origin at start and end

    // First point is the origin
    points[0] = {0.0, 0.0};

    // Read all N points
    for (int i = 1; i <= n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Return to origin at the end
    points[n + 1] = {0.0, 0.0};

    // Compute total distance
    for (int i = 0; i <= n; ++i) {
        total += euclid(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
    }

    cout << fixed << setprecision(15) << total << endl;
}