#include <bits/stdc++.h>
using namespace std;

double EuclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Add the starting point back to the end to form a cycle
    points.push_back(points.front());

    double total_distance = 0;
    for (size_t i = 1; i <= n; ++i) {
        total_distance += EuclideanDistance(points[i-1].first, points[i-1].second, points[i].first, points[i].second);
    }

    cout << fixed << setprecision(12) << total_distance << '\n';

    return 0;
}