#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate the Euclidean distance between two points
double euclideanDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void solve() {
    int n;
    cin >> n;
    vector<pair<double, double>> points(n);

    // Read all points into a vector
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0.0;

    // Calculate the cost of moving from one point to another in sequence
    for (size_t i = 0; i < n - 1; ++i) {
        totalCost += euclideanDistance(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
    }

    // Add the cost of returning to the origin from the last point
    totalCost += euclideanDistance(points[n - 1].first, points[n - 1].second, 0.0, 0.0);

    // Print the total cost with high precision
    cout << setprecision(20) << fixed << totalCost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}