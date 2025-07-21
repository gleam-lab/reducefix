#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main() {
    int n;
    double x = 0, y = 0, total_cost = 0;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    for (const auto& point : points) {
        total_cost += sqrt(pow(x - point.first, 2) + pow(y - point.second, 2));
        x = point.first;
        y = point.second;
    }
    total_cost += sqrt(pow(x, 2) + pow(y, 2));
    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}