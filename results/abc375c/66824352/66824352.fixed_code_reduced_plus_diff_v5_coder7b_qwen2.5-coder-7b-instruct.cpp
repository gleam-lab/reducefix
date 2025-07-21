#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double euclideanDistance(long long x1, long long y1, long long x2, long long y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> points(n);
    
    // Read points
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0.0;
    // Calculate the cost of moving from the origin to the first point
    totalCost += euclideanDistance(0, 0, points[0].first, points[0].second);

    // Calculate the cost of moving between each pair of consecutive points
    for (int i = 0; i < n - 1; ++i) {
        totalCost += euclideanDistance(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
    }

    // Calculate the cost of returning to the origin from the last point
    totalCost += euclideanDistance(points[n - 1].first, points[n - 1].second, 0, 0);

    // Output the result with high precision
    cout << fixed << setprecision(10) << totalCost << endl;

    return 0;
}