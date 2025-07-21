#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N);

    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long long total_cost = 0;
    long long x = 0, y = 0;

    for (const auto& point : points) {
        total_cost += sqrt(pow(point.first - x, 2) + pow(point.second - y, 2));
        x = point.first;
        y = point.second;
    }

    total_cost += sqrt(pow(x, 2) + pow(y, 2));  // Return to the origin

    cout.precision(9);
    cout << fixed << total_cost << endl;

    return 0;
}