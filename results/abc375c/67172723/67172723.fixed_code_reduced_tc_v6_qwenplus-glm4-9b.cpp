#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<double, double>> points;
    double x, y;
    
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    
    double total_cost = 0.0;
    for (int i = 0; i < n; ++i) {
        total_cost += hypot(points[i].first, points[i].second);
    }
    // Return to the origin, calculate the distance from the last point to (0, 0)
    total_cost += hypot(points[n - 1].first, points[n - 1].second);
    
    printf("%.10f\n", total_cost);
    return 0;
}