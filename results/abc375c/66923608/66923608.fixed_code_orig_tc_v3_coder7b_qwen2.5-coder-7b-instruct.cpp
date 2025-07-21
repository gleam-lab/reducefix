#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n;
    cin >> n;
    
    // Vectors to store coordinates of points
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    double totalCost = 0;

    // Calculate the total cost of visiting all points in order and returning to the origin
    for(int i = 0; i < n; ++i) {
        totalCost += euclideanDistance(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }

    // Output the total cost with high precision
    cout << fixed << setprecision(12) << totalCost << '\n';

    return 0;
}