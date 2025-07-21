#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double calculate_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    // Adding the origin as the starting and ending point
    points.push_back({0, 0});
    points.push_back({0, 0});

    double total_distance = 0;

    // Calculate the distance between consecutive points
    for (int i = 0; i < n + 1; i++) {
        total_distance += calculate_distance(points[i].first, points[i].second, points[(i + 1) % (n + 2)].first, points[(i + 1) % (n + 2)].second);
    }

    // Print the result with the required precision
    cout << fixed << setprecision(12) << total_distance << endl;

    return 0;
}