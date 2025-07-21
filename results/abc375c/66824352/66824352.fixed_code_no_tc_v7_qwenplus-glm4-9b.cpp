#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    double total_cost = 0.0;
    for (int i = 0; i < n; i++) {
        total_cost += sqrt(pow(points[i].first, 2) + pow(points[i].second, 2));
    }

    // Return to the origin
    total_cost += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));

    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}