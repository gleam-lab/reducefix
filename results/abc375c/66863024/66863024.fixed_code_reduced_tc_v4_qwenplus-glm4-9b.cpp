#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> points;

    for (int i = 0; i <= n; ++i) {
        double x, y;
        if (i == 0) {
            cin >> x >> y;
            points.emplace_back(0, 0); // Add the origin to the list
        } else {
            cin >> x >> y;
            points.emplace_back(x, y);
        }
    }

    double total_cost = 0;
    for (int i = 0; i < n + 1; ++i) {
        int current = i;
        int next = (i + 1) % (n + 1); // Wrap around to the origin after the last point
        double dist = sqrt(pow(points[current].first - points[next].first, 2) +
                           pow(points[current].second - points[next].second, 2));
        total_cost += dist;
    }

    cout.precision(12);
    cout << fixed << total_cost << endl;

    return 0;
}