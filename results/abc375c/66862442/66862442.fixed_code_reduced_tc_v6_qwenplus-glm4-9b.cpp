#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<double, double>> points;
    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    double total_cost = 0.0;
    for (int i = 0; i < N; ++i) {
        double dx = points[i].first - 0.0;
        double dy = points[i].second - 0.0;
        total_cost += sqrt(dx * dx + dy * dy);
    }

    cout.precision(30);
    cout << fixed << total_cost << endl;

    return 0;
}