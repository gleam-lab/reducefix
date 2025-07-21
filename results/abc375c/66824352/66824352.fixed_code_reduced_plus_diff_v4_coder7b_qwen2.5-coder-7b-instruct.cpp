#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0;
    for (size_t i = 1; i < points.size(); ++i) {
        total_cost += distance(points[i - 1].first, points[i - 1].second, points[i].first, points[i].second);
    }
    
    // Adding the cost to return to the origin
    total_cost += distance(points.back().first, points.back().second, 0, 0);

    cout << setprecision(10) << total_cost << endl;

    return 0;
}