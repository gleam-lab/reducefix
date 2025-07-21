#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double calculateDistance(long double x1, long double y1, long double x2, long double y2) {
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }

    vector<long double> x(n), y(n);
    long double totalDistance = 0;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    // Start from the origin (0, 0) to the first point
    totalDistance += calculateDistance(0, 0, x[0], y[0]);

    // Calculate the distance between consecutive points
    for (int i = 0; i < n - 1; ++i) {
        totalDistance += calculateDistance(x[i], y[i], x[i + 1], y[i + 1]);
    }

    // Return to the origin from the last point
    totalDistance += calculateDistance(x[n - 1], y[n - 1], 0, 0);

    cout << fixed << setprecision(15) << totalDistance << endl;

    return 0;
}