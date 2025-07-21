#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> points;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    double total_cost = 0.0;
    // Calculate the cost from the origin to the first point
    int origin_x = 0, origin_y = 0;
    if (N > 0) {
        total_cost += hypot(origin_x - points[0].first, origin_y - points[0].second);
    }
    
    // Calculate the cost between consecutive points
    for (int i = 0; i < N - 1; ++i) {
        total_cost += hypot(points[i].first - points[i + 1].first, points[i].second - points[i + 1].second);
    }
    
    // Calculate the cost back to the origin
    if (N > 0) {
        total_cost += hypot(points[N - 1].first - origin_x, points[N - 1].second - origin_y);
    }

    // Print the result with high precision
    cout << fixed << setprecision(12) << total_cost << endl;

    return 0;
}