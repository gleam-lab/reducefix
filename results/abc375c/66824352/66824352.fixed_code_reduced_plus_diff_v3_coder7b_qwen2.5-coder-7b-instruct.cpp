#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(static_cast<double>((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int main() {
    int n, x = 0, y = 0;
    double total_distance = 0;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    for (const auto& point : points) {
        total_distance += distance(x, y, point.first, point.second);
        x = point.first;
        y = point.second;
    }
    total_distance += distance(x, y, 0, 0);
    cout << fixed << setprecision(10) << total_distance << endl;
    return 0;
}