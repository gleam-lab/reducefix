#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    // Read the points into a vector of pairs
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_distance = 0.0;

    // Calculate the distance from the origin to the first point
    total_distance += sqrt(points[0].first * points[0].first + points[0].second * points[0].second);

    // Calculate the distances between consecutive points
    for (size_t i = 1; i < n; ++i) {
        total_distance += sqrt(pow(points[i].first - points[i - 1].first, 2) +
                              pow(points[i].second - points[i - 1].second, 2));
    }

    // Calculate the distance from the last point back to the origin
    total_distance += sqrt(points[n - 1].first * points[n - 1].first + points[n - 1].second * points[n - 1].second);

    // Print the result with high precision
    cout << fixed << setprecision(20) << total_distance << '\n';

    return 0;
}