#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    long long N;
    cin >> N;

    vector<pair<long long, long long>> points(N);
    for (long long i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Sort points to facilitate efficient calculation of distances
    sort(points.begin(), points.end());

    long double total_cost = 0;

    // Calculate the distance from origin to the first point
    total_cost += sqrtl(points[0].first * points[0].first + points[0].second * points[0].second);

    // Calculate the distance between consecutive points
    for (long long i = 1; i < N; ++i) {
        total_cost += sqrtl(
            (points[i].first - points[i - 1].first) * (points[i].first - points[i - 1].first) +
            (points[i].second - points[i - 1].second) * (points[i].second - points[i - 1].second)
        );
    }

    // Calculate the distance from the last point back to the origin
    total_cost += sqrtl(points[N - 1].first * points[N - 1].first + points[N - 1].second * points[N - 1].second);

    cout << total_cost << endl;

    return 0;
}