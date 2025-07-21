#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double Euclid(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n;
    cin >> n;
    
    // Initialize coordinates array with an extra element for the starting point (origin)
    vector<int> x(n + 1), y(n + 1);
    
    // Read input points
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    
    // Set the last point as the origin (0, 0)
    x[n] = 0;
    y[n] = 0;
    
    // Calculate total cost
    double total_cost = 0;
    for (int i = 0; i <= n; ++i) {
        total_cost += Euclid(x[i], y[i], x[i + 1], y[i + 1]);
    }
    
    // Print result with high precision
    cout << fixed << setprecision(12) << total_cost << endl;
    
    return 0;
}