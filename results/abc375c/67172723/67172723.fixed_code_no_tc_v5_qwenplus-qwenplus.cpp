#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long px = 0, py = 0;
    double total = 0.0;

    // Store all points to return to origin at the end
    vector<pair<long long, long long>> points(n + 1);

    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    points[n] = {0, 0};  // Return to origin

    for (int i = 0; i <= n; ++i) {
        long long dx = points[i].first - px;
        long long dy = points[i].second - py;
        total += sqrt(static_cast<double>(dx * dx + dy * dy));
        px = points[i].first;
        py = points[i].second;
    }

    // Ensure precision up to required tolerance
    cout.precision(15);
    cout << fixed << total << '\n';

    return 0;
}