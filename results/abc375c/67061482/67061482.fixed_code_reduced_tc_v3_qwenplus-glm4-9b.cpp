#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> points(N + 1); // Include the origin in the list of points

    // Read the points from input
    for (int i = 0; i <= N; ++i) {
        double x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    double total_distance = 0;

    // Calculate the total distance by summing the distances between consecutive points
    for (int i = 1; i <= N; ++i) {
        double x1 = points[i - 1].first;
        double y1 = points[i - 1].second;
        double x2 = points[i].first;
        double y2 = points[i].second;
        total_distance += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

    // Output the total distance, formatted to meet the precision requirements
    cout.precision(20);
    cout << fixed << total_distance << endl;

    return 0;
}