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

    double totalDistance = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        if (i > 0) {
            totalDistance += sqrt(pow(points[i].first - points[i - 1].first, 2) + pow(points[i].second - points[i - 1].second, 2));
        }
    }

    totalDistance += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));

    cout << fixed;
    cout.precision(15);
    cout << totalDistance << '\n';

    return 0;
}