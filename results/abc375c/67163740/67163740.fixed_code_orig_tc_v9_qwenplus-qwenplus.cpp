#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long double x = 0, y = 0;
    long double total = 0;

    vector<pair<long double, long double>> points(n);
    for (auto& [xi, yi] : points) {
        cin >> xi >> yi;
    }

    // From origin to first point
    total += sqrtl((x - points[0].first) * (x - points[0].first) + 
                  (y - points[0].second) * (y - points[0].second));

    // Between all consecutive points
    for (int i = 1; i < n; ++i) {
        total += sqrtl((points[i-1].first - points[i].first) * (points[i-1].first - points[i].first) +
                      (points[i-1].second - points[i].second) * (points[i-1].second - points[i].second));
    }

    // From last point back to origin
    total += sqrtl(points.back().first * points.back().first + 
                   points.back().second * points.back().second);

    cout.precision(20);
    cout << fixed << total << endl;

    return 0;
}