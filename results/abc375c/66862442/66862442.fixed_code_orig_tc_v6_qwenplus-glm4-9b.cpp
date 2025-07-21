#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points;
    points.emplace_back(0, 0); // The origin point

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    long long total_cost = 0;

    for (int i = 1; i < points.size(); ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        total_cost += sqrt(dx * dx + dy * dy);
    }

    cout << fixed << setprecision(7) << total_cost << endl;

    return 0;
}