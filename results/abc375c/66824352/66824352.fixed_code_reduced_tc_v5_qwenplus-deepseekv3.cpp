#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    long long x = 0, y = 0;
    double total_cost = 0.0;
    
    for (const auto& point : points) {
        long long dx = x - point.first;
        long long dy = y - point.second;
        total_cost += sqrt(dx * dx + dy * dy);
        x = point.first;
        y = point.second;
    }
    
    total_cost += sqrt(x * x + y * y);
    
    cout << fixed << setprecision(15) << total_cost << endl;
    
    return 0;
}