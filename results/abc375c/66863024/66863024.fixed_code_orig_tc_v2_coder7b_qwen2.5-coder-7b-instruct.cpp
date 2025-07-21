#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    
    int n;
    cin >> n;
    
    vector<pair<long double, long double>> points(n + 1);
    points[0] = {0, 0}; // Origin
    
    for (int i = 1; i <= n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    long double total_cost = 0;
    
    for (int i = 1; i <= n; ++i) {
        long double dx = points[i].first - points[i - 1].first;
        long double dy = points[i].second - points[i - 1].second;
        total_cost += sqrtl(dx * dx + dy * dy);
    }
    
    long double dx = points[n].first - points[0].first;
    long double dy = points[n].second - points[0].second;
    total_cost += sqrtl(dx * dx + dy * dy);
    
    cout << total_cost << endl;
    
    return 0;
}