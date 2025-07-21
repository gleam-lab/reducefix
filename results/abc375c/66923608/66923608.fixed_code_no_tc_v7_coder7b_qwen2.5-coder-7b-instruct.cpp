#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double Euclidean(int x1, int x2, int y1, int y2) {
    double A = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return A;
}

int main() {
    int n; cin >> n;
    
    // Initialize total distance to zero
    double ans = 0; 

    // Vectors to store coordinates of points
    vector<int> x(n), y(n);

    // Read the coordinates of the points
    rep(i, n) cin >> x[i] >> y[i];

    // Calculate the total distance
    rep(i, n) {
        ans += Euclidean(x[i], x[(i + 1) % n], y[i], y[(i + 1) % n]);
    }

    // Print the result with high precision
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}