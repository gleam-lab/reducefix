#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(static_cast<double>((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0;
    int x = 0, y = 0;

    for (const auto& p : points) {
        total_cost += distance(x, y, p.first, p.second);
        x = p.first;
        y = p.second;
    }

    total_cost += distance(x, y, 0, 0);

    cout << setprecision(10) << total_cost << endl;
    return 0;
}