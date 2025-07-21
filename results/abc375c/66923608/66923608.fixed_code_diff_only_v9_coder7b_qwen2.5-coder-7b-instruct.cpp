#include <bits/stdc++.h>
using namespace std;

double EuclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n;
    cin >> n;
    
    // Initialize total distance with zero
    double totalDistance = 0;
    
    // Store the coordinates of points
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the distance for each segment including the final return trip to the origin
    for (int i = 0; i <= n; ++i) {
        int currentX = i == n ? 0 : points[i].first;
        int currentY = i == n ? 0 : points[i].second;
        int nextX = (i + 1) % n == n ? 0 : points[(i + 1) % n].first;
        int nextY = (i + 1) % n == n ? 0 : points[(i + 1) % n].second;
        
        totalDistance += EuclideanDistance(currentX, currentY, nextX, nextY);
    }

    // Output the result with precision up to 12 decimal places
    cout << fixed << setprecision(12) << totalDistance << endl;
    return 0;
}