#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N + 1);
    points[0] = {0, 0};  // Start at the origin

    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_distance = 0.0;
    for (int i = 1; i <= N; ++i) {
        long long x1 = points[i - 1].first;
        long long y1 = points[i - 1].second;
        long long x2 = points[i].first;
        long long y2 = points[i].second;
        total_distance += sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }
    // Add the distance back to the origin
    total_distance += sqrt(pow(points[N].first, 2) + pow(points[N].second, 2));

    // Print the result with a precision of at least 6 decimal places
    cout.precision(6);
    cout << fixed << total_distance << endl;

    return 0;
}