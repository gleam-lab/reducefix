#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
    int n;
    cin >> n;
    vector<pair<double, double>> points(2 * n + 1);
    points[0] = {0, 0}; // Starting from the origin
    for (int i = 1; i <= n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    points[2 * n + 1] = {0, 0}; // Return to the origin

    double total_cost = 0.0;
    for (int i = 1; i <= 2 * n; ++i) {
        total_cost += dist(points[i - 1].first, points[i - 1].second, points[i].first, points[i].second);
    }

    cout << setprecision(20) << total_cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}