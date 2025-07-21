#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double Euclid(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n; cin >> n;
    double ans = 0; 

    // Read input coordinates into vectors
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    // Calculate total cost of visiting all points in order and returning to the origin
    for(int i = 0; i < n; ++i) {
        ans += Euclid(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }

    // Print result with high precision
    cout << fixed << setprecision(12) << ans << endl;
}