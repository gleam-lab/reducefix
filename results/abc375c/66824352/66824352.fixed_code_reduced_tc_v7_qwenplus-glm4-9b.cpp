#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 0) return 0;

    vector<pair<double, double>> points;
    points.emplace_back(0.0, 0.0); // Start at the origin

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    points.emplace_back(0.0, 0.0); // End at the origin

    double total_cost = 0.0;

    // Calculate the cost of travel between consecutive points
    for (int i = 0; i < points.size() - 1; ++i) {
        double x1 = points[i].first;
        double y1 = points[i].second;
        double x2 = points[i + 1].first;
        double y2 = points[i + 1].second;
        total_cost += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}