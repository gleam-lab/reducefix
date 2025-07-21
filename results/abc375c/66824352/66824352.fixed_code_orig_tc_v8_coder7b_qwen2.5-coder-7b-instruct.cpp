#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the total distance
    double total_distance = 0.0;
    for (size_t i = 0; i < points.size(); ++i) {
        if (i > 0) {
            total_distance += sqrt(pow(points[i].first - points[i - 1].first, 2) + 
                                   pow(points[i].second - points[i - 1].second, 2));
        }
    }
    // Add the distance back to the origin
    total_distance += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));

    // Print the result with high precision
    cout << fixed << setprecision(10) << total_distance << endl;

    return 0;
}