#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<pair<long long, long long>> points(n);
    for (long long i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;
    long long x = 0, y = 0;

    for (const auto& point : points) {
        long long dx = point.first - x;
        long long dy = point.second - y;
        total_cost += sqrt(dx * dx + dy * dy);
        x = point.first;
        y = point.second;
    }

    // Return to the origin
    long long dx = x;
    long long dy = y;
    total_cost += sqrt(dx * dx + dy * dy);

    cout.precision(15);
    cout << total_cost << '\n';

    return 0;
}