#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // We use a vector instead of an array of pairs for better efficiency in C++
    vector<pair<int, int>> points(n);
    
    // Read the points
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double total_cost = 0.0;
    int x = 0, y = 0; // Starting at the origin

    // Calculate the cost of moving from the origin to the first point and then
    // visiting all the points in sequence
    for (int i = 0; i < n; ++i) {
        total_cost += sqrt((x - points[i].first) * (x - points[i].first) + (y - points[i].second) * (y - points[i].second));
        x = points[i].first;
        y = points[i].second;
    }
    
    // Add the cost of returning to the origin
    total_cost += sqrt(x * x + y * y);
    
    // Print the result with high precision
    cout << fixed << setprecision(20) << total_cost << endl;
    
    return 0;
}