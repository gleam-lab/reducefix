#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> points(n);
    
    // Read all points
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the total distance
    long double total_distance = 0;
    for(int i = 1; i < n; ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        total_distance += sqrtl(dx * dx + dy * dy);
    }

    // Add the distance from the last point back to the origin
    long long dx = points[0].first - points[n - 1].first;
    long long dy = points[0].second - points[n - 1].second;
    total_distance += sqrtl(dx * dx + dy * dy);

    // Output the result
    printf("%.15Lf\n", total_distance);
    return 0;
}