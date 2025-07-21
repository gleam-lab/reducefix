#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points;
    
    // Read points into a vector
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    
    // Start from the origin (0, 0), add the cost to move to the first point
    double total_cost = sqrt(points[0].first * points[0].first + points[0].second * points[0].second);
    
    // Add the cost between consecutive points
    for(int i = 1; i < N; i++) {
        int a = points[i - 1].first;
        int b = points[i - 1].second;
        int c = points[i].first;
        int d = points[i].second;
        total_cost += sqrt((a - c) * (a - c) + (b - d) * (b - d));
    }
    
    // Add the cost to return to the origin
    int a = points[N - 1].first;
    int b = points[N - 1].second;
    total_cost += sqrt(a * a + b * b);
    
    // Print the result with sufficient precision
    cout.precision(10);
    cout << fixed << total_cost << endl;
    
    return 0;
}