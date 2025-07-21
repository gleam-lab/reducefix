#include <iostream>
#include <vector>
#include <cmath>  // Include cmath for sqrt()
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n + 1);  // +1 for the origin point
    
    // Read the points
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    // Add the origin as the starting point at the end of the list
    points.push_back({0, 0});

    double total_cost = 0.0;
    
    // Calculate the distance from each point to the next one
    for (int i = 0; i < n; i++) {
        total_cost += sqrt(pow(points[i].first - points[i + 1].first, 2) +
                           pow(points[i].second - points[i + 1].second, 2));
    }
    
    // Calculate the return distance back to the origin
    total_cost += sqrt(pow(points[n].first - 0, 2) +
                       pow(points[n].second - 0, 2));

    cout << fixed << setprecision(12) << total_cost << endl;
    
    return 0;
}