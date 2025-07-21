#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n; 
    cin >> n;
    
    // Vector to store coordinates of points
    vector<pair<int, int>> points(n);
    
    // Read input points
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double totalCost = 0.0;
    
    // Calculate the cost of moving from one point to the next
    for(int i = 0; i < n; ++i) {
        totalCost += euclideanDistance(points[i].first, points[i].second, points[(i + 1) % n].first, points[(i + 1) % n].second);
    }
    
    // Output the total cost with high precision
    cout << fixed << setprecision(12) << totalCost << endl;
    
    return 0;
}