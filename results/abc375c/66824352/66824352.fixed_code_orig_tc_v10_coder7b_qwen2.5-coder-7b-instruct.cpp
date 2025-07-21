#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double calculateTotalCost(vector<pair<int, int>>& points) {
    double totalCost = 0.0;
    int n = points.size();
    
    // Calculate cost from origin to first point
    totalCost += sqrt(points[0].first * points[0].first + points[0].second * points[0].second);
    
    // Calculate cost between consecutive points
    for (int i = 1; i < n; ++i) {
        totalCost += sqrt(pow(points[i].first - points[i - 1].first, 2) +
                         pow(points[i].second - points[i - 1].second, 2));
    }
    
    // Calculate cost from last point back to origin
    totalCost += sqrt(points[n - 1].first * points[n - 1].first + points[n - 1].second * points[n - 1].second);
    
    return totalCost;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double result = calculateTotalCost(points);
    printf("%.10f\n", result); // Print with 10 decimal places
    
    return 0;
}