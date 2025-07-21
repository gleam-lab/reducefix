#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    double total_cost = 0.0;
    vector<pair<int, int>> points;
    
    // Read input
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    // Calculate the total cost of moving from one point to another in sequence
    for (size_t i = 0; i < n; ++i) {
        total_cost += sqrt(pow(points[i].first, 2) + pow(points[i].second, 2));
        if (i > 0) {
            total_cost += sqrt(pow(points[i].first - points[i-1].first, 2) + pow(points[i].second - points[i-1].second, 2));
        }
    }
    
    // Return to the origin
    total_cost += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));
    
    // Print the result with high precision
    cout << setprecision(10) << fixed << total_cost << endl;
    
    return 0;
}