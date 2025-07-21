#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> points;
    double x = 0, y = 0;
    
    for (int i = 0; i < n; ++i) {
        double X, Y;
        cin >> X >> Y;
        points.push_back({X, Y});
    }
    
    double total_cost = 0;
    for (const auto& point : points) {
        total_cost += sqrt((point.first - x) * (point.first - x) + (point.second - y) * (point.second - y));
        x = point.first;
        y = point.second;
    }
    total_cost += sqrt(x * x + y * y);
    
    cout << setprecision(10) << fixed << total_cost << endl;
    return 0;
}