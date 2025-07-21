#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double euclidean_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> points(n + 1);
    points[0] = {0, 0};

    for (int i = 1; i <= n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0;

    for (int i = 1; i <= n; ++i) {
        total_cost += euclidean_distance(points[i - 1].first, points[i - 1].second, points[i].first, points[i].second);
    }

    // Adding distance back to the origin
    total_cost += euclidean_distance(points[n].first, points[n].second, 0, 0);

    cout << fixed << setprecision(15) << total_cost << '\n';

    return 0;
}