#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n; cin >> n;
    vector<pair<int, int>> points(n);

    // Read the points
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Add the starting point again to close the loop
    points.push_back(points[0]);

    double totalCost = 0.0;

    // Calculate the total cost of visiting each pair of consecutive points
    for (size_t i = 0; i < n; ++i) {
        totalCost += euclideanDistance(points[i].first, points[i].second,
                                     points[i + 1].first, points[i + 1].second);
    }

    // Output the result with high precision
    cout << fixed << setprecision(12) << totalCost << endl;

    return 0;
}