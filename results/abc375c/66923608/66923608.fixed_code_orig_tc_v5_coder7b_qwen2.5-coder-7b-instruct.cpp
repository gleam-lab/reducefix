#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate total distance including the path back to origin
    double totalDistance = 0;
    for (int i = 0; i < n - 1; ++i) {
        totalDistance += euclideanDistance(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
    }
    // Adding distance from last point to the origin
    totalDistance += euclideanDistance(points[n - 1].first, points[n - 1].second, 0, 0);

    // Print the result with high precision
    cout << fixed << setprecision(15) << totalDistance << endl;

    return 0;
}