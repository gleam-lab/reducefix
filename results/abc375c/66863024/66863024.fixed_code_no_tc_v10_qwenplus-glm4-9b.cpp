#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N + 1);
    long long x, y;

    // Read points, including the origin (0, 0) at the end for easier calculation
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        points[i] = {x, y};
    }
    points[N] = {0, 0}; // The return to the origin

    long long total_cost = 0;

    // Calculate the total cost of moving from one point to the next and back to the origin
    for (int i = 0; i <= N; i++) {
        long long cx = points[i].first;
        long long cy = points[i].second;
        long long nx = points[i == N ? 0 : i + 1].first;
        long long ny = points[i == N ? 0 : i + 1].second;

        total_cost += sqrt((cx - nx) * (cx - nx) + (cy - ny) * (cy - ny));
    }

    // Print the total cost
    cout << total_cost << endl;

    return 0;
}