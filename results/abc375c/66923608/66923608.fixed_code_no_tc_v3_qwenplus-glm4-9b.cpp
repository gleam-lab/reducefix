#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    // Append the origin to the end of the list of points
    points.push_back({0, 0});
    
    double total_distance = 0.0;
    // Calculate the total distance by summing up all the distances between consecutive points
    for (int i = 0; i < n; ++i) {
        // Use the distance formula between two points (x1, y1) and (x2, y2)
        // which is sqrt((x2 - x1)^2 + (y2 - y1)^2)
        total_distance += sqrt(pow(points[i + 1].first - points[i].first, 2) +
                               pow(points[i + 1].second - points[i].second, 2));
    }
    
    // Print the total distance with a precision of 12 decimal places
    cout << fixed << setprecision(12) << total_distance << endl;
    
    return 0;
}