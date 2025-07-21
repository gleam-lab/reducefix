#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double total_cost = 0.0;
    int x = 0, y = 0;
    for (const auto& point : points) {
        int dx = point.first - x;
        int dy = point.second - y;
        total_cost += sqrt(dx * dx + dy * dy);
        x = point.first;
        y = point.second;
    }
    total_cost += sqrt(x * x + y * y);
    
    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}