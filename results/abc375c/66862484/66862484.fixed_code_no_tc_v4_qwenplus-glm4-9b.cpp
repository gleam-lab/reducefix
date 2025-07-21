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
    points.push_back({0, 0}); // Start from origin

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    points.push_back({0, 0}); // End at origin

    double total_cost = 0.0;
    for (int i = 1; i < points.size(); ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        total_cost += sqrt(dx * dx + dy * dy);
    }

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}