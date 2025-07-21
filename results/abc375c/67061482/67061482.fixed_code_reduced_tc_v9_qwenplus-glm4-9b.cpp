#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<double, double>> points;
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    
    double total_cost = 0.0;
    double x = 0.0, y = 0.0;
    
    for (const auto& p : points) {
        total_cost += sqrt((x - p.first) * (x - p.first) + (y - p.second) * (y - p.second));
        x = p.first;
        y = p.second;
    }
    
    total_cost += sqrt(x * x + y * y);
    cout.precision(15);
    cout << fixed << total_cost << endl;
}