#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(static_cast<double>(x2 - x1) * (x2 - x1) + static_cast<double>(y2 - y1) * (y2 - y1));
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;
    for (size_t i = 1; i < n; ++i) {
        total_cost += distance(points[i - 1].first, points[i - 1].second, points[i].first, points[i].second);
    }
    // Add the cost of returning to the origin
    total_cost += distance(points[n - 1].first, points[n - 1].second, 0, 0);

    cout << setprecision(10) << total_cost << endl;
    return 0;
}