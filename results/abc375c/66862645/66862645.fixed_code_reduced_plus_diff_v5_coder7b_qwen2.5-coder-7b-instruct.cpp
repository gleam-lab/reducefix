#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0;

    // Calculate the distance from the origin to the first point
    total_cost += sqrt(points[0].first * points[0].first + points[0].second * points[0].second);

    // Calculate the distance between consecutive points
    for (int i = 0; i < n - 1; ++i) {
        total_cost += sqrt(
            (points[i + 1].first - points[i].first) * (points[i + 1].first - points[i].first) +
            (points[i + 1].second - points[i].second) * (points[i + 1].second - points[i].second)
        );
    }

    // Calculate the distance from the last point back to the origin
    total_cost += sqrt(points[n - 1].first * points[n - 1].first + points[n - 1].second * points[n - 1].second);

    cout << total_cost << endl;

    return 0;
}