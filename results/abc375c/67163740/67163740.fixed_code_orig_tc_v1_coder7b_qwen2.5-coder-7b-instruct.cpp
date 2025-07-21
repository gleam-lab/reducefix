#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double EPS = 1e-9;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0;
    for (int i = 0; i < n - 1; ++i) {
        total_cost += dist(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
    }
    total_cost += dist(points[n - 1].first, points[n - 1].second, 0, 0);

    printf("%.15f\n", total_cost);

    return 0;
}