#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long double total_cost = 0;

    // Calculate the cost of moving from the origin to the first point
    total_cost = sqrtl(points[0].first * points[0].first + points[0].second * points[0].second);

    // Calculate the cost of moving from each point to the next
    for (int i = 1; i < N; ++i) {
        total_cost += sqrtl(
            (points[i].first - points[i - 1].first) * (points[i].first - points[i - 1].first) +
            (points[i].second - points[i - 1].second) * (points[i].second - points[i - 1].second)
        );
    }

    // Calculate the cost of returning to the origin from the last point
    total_cost += sqrtl(points[N - 1].first * points[N - 1].first + points[N - 1].second * points[N - 1].second);

    cout << total_cost << endl;

    return 0;
}