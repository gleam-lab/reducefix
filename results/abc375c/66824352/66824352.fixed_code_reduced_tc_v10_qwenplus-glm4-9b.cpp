#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n + 1);
    points[0] = {0, 0}; // Starting at the origin
    pair<int, int> prev = points[0];
    
    for (int i = 1; i <= n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    double total_cost = 0.0;
    
    for (int i = 1; i <= n; ++i) {
        total_cost += sqrt(pow(prev.first - points[i].first, 2) + pow(prev.second - points[i].second, 2));
        prev = points[i];
    }
    
    // Return to the origin
    total_cost += sqrt(pow(prev.first - 0, 2) + pow(prev.second - 0, 2));
    
    cout.precision(10);
    cout << fixed << total_cost << endl;
    
    return 0;
}