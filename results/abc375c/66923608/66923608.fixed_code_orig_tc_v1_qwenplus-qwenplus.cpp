#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// Use a constexpr for epsilon to ensure precision
constexpr double EPS = 1e-9;

// Function to compute Euclidean distance with proper double inputs
double euclid(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> x(n + 2), y(n + 2); // +2 to include origin at start and end

    // Start at origin (0, 0)
    x[0] = 0.0;
    y[0] = 0.0;

    // Read the N points
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    // Return to origin at the end
    x[n + 1] = 0.0;
    y[n + 1] = 0.0;

    double total_cost = 0.0;

    // Compute total cost by summing distances between consecutive points
    for (int i = 0; i < n + 1; ++i) {
        total_cost += euclid(x[i], y[i], x[i + 1], y[i + 1]);
    }

    // Output with sufficient precision (15 decimal digits)
    cout << fixed << setprecision(15) << total_cost << endl;

    return 0;
}