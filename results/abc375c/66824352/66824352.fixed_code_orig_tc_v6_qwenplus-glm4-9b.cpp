#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    double total_distance = 0.0;

    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // First, calculate the distance from the origin to the first point
    total_distance += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));

    // Calculate the distance between each consecutive pair of points
    for (int i = 1; i < n; ++i) {
        double dx = points[i].first - points[i - 1].first;
        double dy = points[i].second - points[i - 1].second;
        total_distance += sqrt(dx * dx + dy * dy);
    }

    // Finally, calculate the distance from the last point back to the origin
    total_distance += sqrt(pow(points[n - 1].first, 2) + pow(points[n - 1].second, 2));

    cout.precision(10);
    cout << fixed << total_distance << endl;

    return 0;
}