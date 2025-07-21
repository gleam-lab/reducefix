#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// Calculate Euclidean distance between two points (x1, y1) and (x2, y2)
double EuclideanDistance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    double ans = 0.0;

    // Reading the coordinates of the points
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Adding the origin at the beginning and end of the path
    x.push_back(0.0);
    y.push_back(0.0);
    n++; // Adjusting the size of n to account for the origin

    // Calculating the total distance
    for (int i = 0; i < n; i++) {
        // Add distance from current point to the next point
        ans += EuclideanDistance(x[i], y[i], x[i + 1], y[i + 1]);
    }

    // Output the total distance
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}