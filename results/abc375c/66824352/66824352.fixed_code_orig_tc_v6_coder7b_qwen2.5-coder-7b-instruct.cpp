#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0;
    // Calculate distance from origin to first point
    total_cost += sqrt(points[0].first * points[0].first + points[0].second * points[0].second);

    // Calculate distances between consecutive points
    for(int i = 0; i < n - 1; ++i) {
        total_cost += sqrt(pow(points[i+1].first - points[i].first, 2) + pow(points[i+1].second - points[i].second, 2));
    }

    // Calculate distance from last point back to origin
    total_cost += sqrt(points.back().first * points.back().first + points.back().second * points.back().second);

    cout << setprecision(10) << total_cost << endl;
    return 0;
}