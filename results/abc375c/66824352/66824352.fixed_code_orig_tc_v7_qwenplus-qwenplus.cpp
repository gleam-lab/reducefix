#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    double total_cost = 0.0;

    cin >> n;

    // To store previous point
    long long prev_x = 0, prev_y = 0;

    // Vector to hold all points
    vector<pair<long long, long long>> points(n);

    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    // Calculate cost from origin to each point in sequence
    for (const auto& p : points) {
        long long dx = prev_x - p.first;
        long long dy = prev_y - p.second;
        total_cost += sqrt(static_cast<double>(dx * dx + dy * dy));
        prev_x = p.first;
        prev_y = p.second;
    }

    // Return to origin
    total_cost += sqrt(static_cast<double>(prev_x * prev_x + prev_y * prev_y));

    // Output with sufficient precision
    cout << fixed << setprecision(15) << total_cost << endl;

    return 0;
}