#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the total cost of visiting all points and returning to the origin
    double total_cost = 0;
    for(size_t i = 1; i < points.size(); ++i) {
        total_cost += sqrt(pow(points[i-1].first - points[i].first, 2) + pow(points[i-1].second - points[i].second, 2));
    }
    // Add the distance from the last point back to the origin
    total_cost += sqrt(pow(points.back().first, 2) + pow(points.back().second, 2));

    // Print the result with high precision
    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}