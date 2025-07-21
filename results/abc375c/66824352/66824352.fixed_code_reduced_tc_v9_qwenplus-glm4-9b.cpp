#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<pair<double, double>> points;
    points.emplace_back(0.0, 0.0); // start at origin
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    points.emplace_back(0.0, 0.0); // return to origin

    double total_cost = 0.0;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        total_cost += sqrt(pow(points[i].first - points[i + 1].first, 2) + pow(points[i].second - points[i + 1].second, 2));
    }

    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}