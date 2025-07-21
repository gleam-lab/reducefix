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
    
    double total_distance = 0.0;
    int x = 0, y = 0; // Start from the origin
    
    for (int i = 0; i < n; ++i) {
        // Calculate distance from the current point (x, y) to the next point (points[i].first, points[i].second)
        total_distance += sqrt(pow(x - points[i].first, 2) + pow(y - points[i].second, 2));
        x = points[i].first;
        y = points[i].second;
    }
    
    // Do not add the distance from the last point to the origin to avoid double counting
    // Instead, print the total_distance directly

    cout << fixed << setprecision(10) << total_distance << endl;
    
    return 0;
}