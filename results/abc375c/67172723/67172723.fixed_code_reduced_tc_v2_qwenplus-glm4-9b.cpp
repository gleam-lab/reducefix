#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n + 1);
    points[0] = {0, 0};
    
    for (int i = 1; i <= n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;
    
    for (int i = 1; i <= n; ++i) {
        total_cost += hypot(points[i].first - points[i - 1].first, points[i].second - points[i - 1].second);
    }
    
    total_cost += hypot(points[n].first, points[n].second);
    
    cout.precision(9);
    cout << fixed << total_cost << endl;
    
    return 0;
}