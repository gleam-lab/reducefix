#include <iostream>
#include <vector>
#include <cmath>

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

    // Starting from the origin
    pair<long long, long long> current = {0, 0};
    for (const auto& point : points) {
        long long dx = point.first - current.first;
        long long dy = point.second - current.second;
        double distance = sqrt(dx * dx + dy * dy);
        total_cost += distance;
        current = point;
    }

    // Return to the origin
    long long dx = current.first - 0;
    long long dy = current.second - 0;
    double distance = sqrt(dx * dx + dy * dy);
    total_cost += distance;

    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}