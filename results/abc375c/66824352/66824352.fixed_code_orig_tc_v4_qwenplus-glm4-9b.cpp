#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

    // Read the points
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the distance from the origin to the first point and store the total distance so far
    double total_distance = sqrt(points[0].first * points[0].first + points[0].second * points[0].second);

    // Calculate the distance between consecutive points and update the total distance
    for (int i = 1; i < n; ++i) {
        total_distance += sqrt(pow(points[i].first - points[i - 1].first, 2) + pow(points[i].second - points[i - 1].second, 2));
    }

    // Add the distance back to the origin
    total_distance += sqrt(pow(points[n - 1].first, 2) + pow(points[n - 1].second, 2));

    // Set the precision for the output
    cout << fixed << setprecision(10);
    // Output the total distance
    cout << total_distance << endl;

    return 0;
}