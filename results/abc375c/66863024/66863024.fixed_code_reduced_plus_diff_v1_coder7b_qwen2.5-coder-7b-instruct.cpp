#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<pair<long long, long long>> points(n);
    
    // Read the coordinates
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    // Add the starting point (origin)
    points.push_back({0, 0});
    
    long double ans = 0;
    
    // Calculate the total distance
    for (size_t i = 0; i < points.size(); ++i) {
        if (i > 0) {
            long double dx = points[i].first - points[i - 1].first;
            long double dy = points[i].second - points[i - 1].second;
            ans += sqrtl(dx * dx + dy * dy);
        }
    }
    
    // Print the result with high precision
    cout << setprecision(15) << fixed << ans << '\n';
    
    return 0;
}