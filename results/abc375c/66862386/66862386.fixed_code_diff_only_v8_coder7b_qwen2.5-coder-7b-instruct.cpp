#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    
    // Read all points
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    // Calculate the total distance
    long double total_distance = 0;
    
    // Distance from origin to first point
    total_distance += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));
    
    // Distance between consecutive points
    for(int i = 1; i < n; ++i) {
        total_distance += sqrt(pow(points[i].first - points[i-1].first, 2) + pow(points[i].second - points[i-1].second, 2));
    }
    
    // Distance from last point back to origin
    total_distance += sqrt(pow(points[n-1].first, 2) + pow(points[n-1].second, 2));
    
    // Print the total distance
    cout << total_distance << endl;
    
    return 0;
}