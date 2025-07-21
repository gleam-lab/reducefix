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
    vector<pair<double, double>> points;

    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    double total_distance = 0.0;

    // Calculate the distance from the origin to each point and return to the origin
    for (const auto& point : points) {
        total_distance += calculate_distance(0, 0, point.first, point.second);
    }

    // Output the total distance rounded to 12 decimal places
    cout << fixed << setprecision(12) << total_distance << endl;

    return 0;
}