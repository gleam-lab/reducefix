#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0;
    for (int i = 0; i < n - 1; ++i) {
        total_cost += hypot(points[i + 1].first - points[i].first, points[i + 1].second - points[i].second);
    }
    
    // Return to origin
    total_cost += hypot(points[0].first, points[0].second);

    cout << fixed << setprecision(10) << total_cost << '\n';
    return 0;
}