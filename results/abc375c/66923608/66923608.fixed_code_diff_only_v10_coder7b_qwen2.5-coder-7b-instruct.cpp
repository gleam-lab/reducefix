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
    vector<int> x(n + 1), y(n + 1);
    
    // Reading coordinates of points
    for(int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    
    // Calculate the total distance
    double totalDistance = 0.0;
    for(int i = 1; i <= n; ++i) {
        totalDistance += euclideanDistance(x[i - 1], y[i - 1], x[i], y[i]);
    }
    
    // Adding the distance from the last point back to the origin
    totalDistance += euclideanDistance(x[n], y[n], x[0], y[0]);
    
    // Output the result with high precision
    cout << fixed << setprecision(12) << totalDistance << endl;
    
    return 0;
}