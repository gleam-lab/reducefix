#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    vector<double> distances(N);

    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;
    double origin_x = 0.0, origin_y = 0.0;

    for (int i = 0; i < N; ++i) {
        double x1 = origin_x, y1 = origin_y;
        double x2 = points[i].first, y2 = points[i].second;

        total_cost += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        origin_x = x2;
        origin_y = y2;
    }

    double x2 = origin_x, y2 = origin_y;
    total_cost += sqrt((x2 - 0) * (x2 - 0) + (y2 - 0) * (y2 - 0));

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}