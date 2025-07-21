#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double cost = 0;
    long double ans = 0;
    int n;
    cin >> n;
    
    vector<pair<long double, long double>> points(n);
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate distance from origin to first point
    cost = sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));
    ans += cost;

    // Calculate distances between consecutive points
    for(int i = 0; i < n-1; ++i) {
        cost = sqrt(pow(points[i+1].first - points[i].first, 2) + pow(points[i+1].second - points[i].second, 2));
        ans += cost;
    }

    // Calculate distance from last point back to origin
    cost = sqrt(pow(points[n-1].first, 2) + pow(points[n-1].second, 2));
    ans += cost;

    cout << ans << endl;

    return 0;
}