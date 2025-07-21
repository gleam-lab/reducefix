#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Vector to store points
    vector<pair<int, int>> points;
    int x, y;

    // Reading coordinates
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    // Calculate the total cost
    double total_cost = 0.0;
    for (int i = 0; i < N; i++) {
        int cx = points[i].first, cy = points[i].second;
        total_cost += sqrt(pow(points[(i + 1) % N].first - cx, 2) +
                           pow(points[(i + 1) % N].second - cy, 2));
    }

    // Print the total cost
    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}