#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the total distance
    double totalDistance = 0.0;
    for (int i = 0; i < n; ++i) {
        totalDistance += calculateDistance(i == 0 ? 0 : points[i-1].first, i == 0 ? 0 : points[i-1].second,
                                          points[i].first, points[i].second);
    }

    // Add the distance back to the origin
    totalDistance += calculateDistance(points[n-1].first, points[n-1].second, 0, 0);

    // Output the result with high precision
    cout << fixed << setprecision(10) << totalDistance << endl;

    return 0;
}