#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> points(N + 1); // +1 for the origin
    points[0] = {0, 0};
    
    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double total_cost = 0.0;
    for (int i = 1; i <= N; ++i) {
        total_cost += sqrt(pow(points[i].first - points[i - 1].first, 2) + pow(points[i].second - points[i - 1].second, 2));
    }
    
    cout << setprecision(9) << fixed << total_cost << endl;
    
    return 0;
}