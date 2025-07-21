#include <bits/stdc++.h>
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

    double total = 0;

    // Calculate the distance from the origin to the first point
    total += sqrt(points[0].first * points[0].first + points[0].second * points[0].second);

    // Calculate the distance between each pair of consecutive points
    for (int i = 1; i < N; ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        total += sqrt(dx * dx + dy * dy);
    }

    // Calculate the distance from the last point back to the origin
    total += sqrt(points[N - 1].first * points[N - 1].first + points[N - 1].second * points[N - 1].second);

    // Output the total distance with precision
    printf("%.10f\n", total);

    return 0;
}