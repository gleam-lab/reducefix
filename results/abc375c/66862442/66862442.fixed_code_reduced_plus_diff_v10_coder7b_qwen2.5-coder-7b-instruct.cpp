#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

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

    double totalDistance = 0.0;

    for (size_t i = 1; i < N; ++i) {
        auto& prev = points[i - 1];
        auto& curr = points[i];
        totalDistance += sqrt((curr.first - prev.first) * (curr.first - prev.first) +
                              (curr.second - prev.second) * (curr.second - prev.second));
    }

    // Add the distance from the last point back to the origin
    auto& lastPoint = points[N - 1];
    totalDistance += sqrt(lastPoint.first * lastPoint.first + lastPoint.second * lastPoint.second);

    // Output the total distance with high precision
    cout << fixed << setprecision(15) << totalDistance << '\n';

    return 0;
}