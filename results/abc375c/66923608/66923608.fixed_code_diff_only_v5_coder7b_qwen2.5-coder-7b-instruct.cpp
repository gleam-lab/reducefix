#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double Euclid(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n; 
    cin >> n;
    
    // Vector to store coordinates of points
    vector<pair<int, int>> points(n);
    
    // Read coordinates of each point
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    // Initialize total cost
    double totalCost = 0;
    
    // Calculate the total cost of moving from one point to another and back to the origin
    for (int i = 0; i < n; ++i) {
        totalCost += Euclid(points[i].first, points[i].second, points[(i + 1) % n].first, points[(i + 1) % n].second);
    }
    
    // Print the total cost with high precision
    cout << fixed << setprecision(12) << totalCost << endl;
    
    return 0;
}