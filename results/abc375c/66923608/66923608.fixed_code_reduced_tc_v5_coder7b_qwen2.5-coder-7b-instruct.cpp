#include <bits/stdc++.h>
using namespace std;

double EuclideanDistance(int x1, int y1, int x2, int y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> x(n), y(n);
    
    // Read the coordinates of the points
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    double totalCost = 0.0;

    // Calculate the distance between consecutive points and the origin
    for(int i = 0; i < n; ++i) {
        totalCost += EuclideanDistance(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }

    // Print the result with high precision
    cout << fixed << setprecision(12) << totalCost << '\n';

    return 0;
}