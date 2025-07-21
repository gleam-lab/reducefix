#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points;
    points.emplace_back(0, 0); // Start at the origin

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    points.emplace_back(0, 0); // End at the origin

    long long total_cost = 0;
    for (size_t i = 1; i < points.size(); ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        total_cost += sqrt(dx * dx + dy * dy);
    }

    cout.precision(10);
    cout << fixed << total_cost << '\n';

    return 0;
}