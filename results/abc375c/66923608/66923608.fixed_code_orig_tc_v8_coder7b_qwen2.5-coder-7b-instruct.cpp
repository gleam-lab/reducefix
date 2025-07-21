#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double Euclid(int x1, int x2, int y1, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n;
    cin >> n;
    
    // Vector to store the coordinates
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0;

    // Calculate the total cost of visiting all points in sequence and returning to the origin
    for (int i = 0; i < n; ++i) {
        total_cost += Euclid(points[i].first, points[(i + 1) % n].first, points[i].second, points[(i + 1) % n].second);
    }

    // Print the result with high precision
    cout << fixed << setprecision(15) << total_cost << endl;

    return 0;
}