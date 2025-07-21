#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double euclideanDistance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalDistance = 0.0;

    // From origin to first point
    totalDistance += euclideanDistance(0, 0, points[0].first, points[0].second);

    // Between all consecutive points
    for (int i = 0; i < n - 1; ++i) {
        totalDistance += euclideanDistance(points[i].first, points[i].second,
                                           points[i+1].first, points[i+1].second);
    }

    // From last point back to origin
    totalDistance += euclideanDistance(points[n-1].first, points[n-1].second, 0, 0);

    // Output with sufficient precision
    cout << fixed << setprecision(12) << totalDistance << endl;

    return 0;
}