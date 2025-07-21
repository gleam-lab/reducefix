#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points;
    int x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    long double total_cost = 0.0;
    int prev_x = 0, prev_y = 0;

    for (const auto& point : points) {
        int next_x = point.first;
        int next_y = point.second;
        long double cost = sqrt((next_x - prev_x) * (next_x - prev_x) + (next_y - prev_y) * (next_y - prev_y));
        total_cost += cost;
        prev_x = next_x;
        prev_y = next_y;
    }

    // Add the cost to return to the origin
    total_cost += sqrt(prev_x * prev_x + prev_y * prev_y);

    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}