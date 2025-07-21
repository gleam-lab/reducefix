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

    // Calculate the total distance traveled
    double total_distance = 0;
    for (size_t i = 1; i < n; ++i) {
        total_distance += sqrt(pow(points[i].first - points[i-1].first, 2) + pow(points[i].second - points[i-1].second, 2));
    }
    
    // Add the distance from the last point back to the origin
    total_distance += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));

    cout << fixed << setprecision(10) << total_distance << endl;
    return 0;
}