#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N + 1); // +1 for the original point
    points[0] = {0, 0};

    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;

    for (int i = 1; i <= N; ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        total_cost += sqrt(dx * dx + dy * dy);
    }

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}