#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double euclidean_distance(const pair<int, int>& p1, const pair<int, int>& p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_distance = 0.0;

    // Calculate the distance from the origin to the first point
    total_distance += euclidean_distance({0, 0}, points[0]);

    // Calculate the distance between consecutive points
    for (size_t i = 0; i < n - 1; ++i) {
        total_distance += euclidean_distance(points[i], points[i + 1]);
    }

    // Calculate the distance from the last point back to the origin
    total_distance += euclidean_distance(points[n - 1], {0, 0});

    cout << fixed << setprecision(10) << total_distance << endl;

    return 0;
}