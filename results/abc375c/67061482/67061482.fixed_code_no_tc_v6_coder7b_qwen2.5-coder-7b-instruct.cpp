#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;

    // Start from the origin
    int x = 0, y = 0;

    // Move to each point and return to the origin
    for (const auto& point : points) {
        total_cost += sqrt(pow(x - point.first, 2) + pow(y - point.second, 2));
        x = point.first;
        y = point.second;
    }

    // Return to the origin from the last point
    total_cost += sqrt(pow(x, 2) + pow(y, 2));

    cout << total_cost << endl;

    return 0;
}