#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;

double calculate_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> points(N + 1); // +1 for the origin

    // Read points including the origin
    for (int i = 0; i <= N; ++i) {
        double x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    double total_cost = 0.0;
    for (int i = 1; i <= N; ++i) {
        total_cost += calculate_distance(points[i].first, points[i].second, points[i - 1].first, points[i - 1].second);
    }

    cout << fixed << setprecision(7);
    cout << total_cost << endl;

    return 0;
}