#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Function to calculate Euclidean distance between two points
    auto dist = [](const pair<long long, long long>& p1, const pair<long long, long long>& p2) {
        long long dx = p1.first - p2.first;
        long long dy = p1.second - p2.second;
        return sqrt(dx * dx + dy * dy);
    };

    double total_distance = 0;
    
    // Calculate the distance from origin to the first point
    total_distance += dist({0, 0}, points[0]);
    
    // Calculate the distance between consecutive points
    for (int i = 0; i < n - 1; ++i) {
        total_distance += dist(points[i], points[i + 1]);
    }
    
    // Calculate the distance from the last point back to the origin
    total_distance += dist(points[n - 1], {0, 0});

    printf("%.10f\n", total_distance);
    return 0;
}