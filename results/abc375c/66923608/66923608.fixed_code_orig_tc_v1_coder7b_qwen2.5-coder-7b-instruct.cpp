#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long double EuclideanDistance(long long x1, long long y1, long long x2, long long y2) {
    long double dx = x2 - x1;
    long double dy = y2 - y1;
    return sqrtl(dx * dx + dy * dy);
}

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }

    vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    long double total_distance = 0;

    // Calculate distance from origin to first point
    total_distance += EuclideanDistance(0, 0, x[0], y[0]);

    // Calculate distance between consecutive points
    for (int i = 0; i < n - 1; ++i) {
        total_distance += EuclideanDistance(x[i], y[i], x[i + 1], y[i + 1]);
    }

    // Calculate distance from last point back to origin
    total_distance += EuclideanDistance(x[n - 1], y[n - 1], 0, 0);

    cout << fixed << setprecision(12) << total_distance << endl;

    return 0;
}