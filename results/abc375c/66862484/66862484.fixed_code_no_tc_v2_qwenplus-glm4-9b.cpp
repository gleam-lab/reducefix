#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points;
    long long x, y;

    // Collect all points
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    // Initialize the current position and total distance
    long long curX = 0, curY = 0, totalDistance = 0;

    // Calculate the total distance by summing the distances between consecutive points
    for (int i = 0; i < N; ++i) {
        long long dx = points[i].first - curX;
        long long dy = points[i].second - curY;
        totalDistance += sqrt(dx * dx + dy * dy); // Calculate the distance using sqrt
        curX = points[i].first;
        curY = points[i].second;
    }

    // Add the distance from the last point to the origin
    long long dx = points[N - 1].first - curX;
    long long dy = points[N - 1].second - curY;
    totalDistance += sqrt(dx * dx + dy * dy);

    // Output the total distance
    cout << fixed << setprecision(6) << totalDistance << '\n';

    return 0;
}