#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;

// Function to calculate the Euclidean distance between two points
double Euclid(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n; cin >> n;
    vector<int> x(n + 1), y(n + 1);

    // Read coordinates into vector, adding an extra element for returning to origin
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];

    // Calculate total cost
    double total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        total_cost += Euclid(x[i], y[i], x[i - 1], y[i - 1]);
    }

    // Add the cost of returning to the origin
    total_cost += Euclid(x[n], y[n], x[0], y[0]);

    // Output the result with required precision
    cout << fixed << setprecision(12) << total_cost << endl;

    return 0;
}