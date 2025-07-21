#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    long long x = 0, y = 0;
    double total_cost = 0;
    cin >> n;
    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    // Calculate the cost of moving from the origin to each point and back
    for (const auto& point : points) {
        total_cost += sqrt(x * x + y * y);
        total_cost += sqrt((point.first - x) * (point.first - x) + (point.second - y) * (point.second - y));
        x = point.first;
        y = point.second;
    }
    // Add the cost of returning to the origin from the last point
    total_cost += sqrt(x * x + y * y);
    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}