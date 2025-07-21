#include <bits/stdc++.h>
using namespace std;

double euclideanDistance(int x1, int y1, int x2, int y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n; 
    cin >> n;
    
    vector<int> x(n + 1), y(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    // Start from the origin (0, 0) to the first point
    double totalCost = euclideanDistance(0, 0, x[0], y[0]);

    // Sum up the distances between consecutive points
    for (int i = 0; i < n - 1; ++i) {
        totalCost += euclideanDistance(x[i], y[i], x[i + 1], y[i + 1]);
    }

    // Return to the origin from the last point
    totalCost += euclideanDistance(x[n - 1], y[n - 1], 0, 0);

    // Output the result with the required precision
    cout << fixed << setprecision(12) << totalCost << endl;
    return 0;
}