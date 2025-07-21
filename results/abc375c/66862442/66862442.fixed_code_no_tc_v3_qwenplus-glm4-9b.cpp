#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> points;
    points.emplace_back(0, 0); // Start from the origin

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    points.emplace_back(0, 0); // End at the origin

    double total_cost = 0;

    for (int i = 0; i < N + 2; ++i) {
        int x1 = points[i].first;
        int y1 = points[i].second;
        int x2 = points[(i + 1) % (N + 2)].first;
        int y2 = points[(i + 1) % (N + 2)].second;

        total_cost += sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}