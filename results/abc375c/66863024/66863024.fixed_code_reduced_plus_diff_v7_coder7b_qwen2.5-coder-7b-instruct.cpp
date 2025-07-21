#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double cost = 0;
    int n;
    cin >> n;

    vector<pair<long double, long double>> points(n);
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Add the origin as the first point
    points.push_back({0, 0});

    for(int i = 1; i <= n; ++i) {
        long double dx = points[i].first - points[i - 1].first;
        long double dy = points[i].second - points[i - 1].second;
        cost += sqrtl(dx * dx + dy * dy);
    }

    cout << setprecision(10) << fixed << cost << '\n';

    return 0;
}