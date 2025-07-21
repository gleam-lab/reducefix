#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<pair<long long, long long>> points(n);
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;
    for(int i = 0; i < n - 1; ++i) {
        total_cost += sqrt(pow(points[i].first - points[i+1].first, 2) + pow(points[i].second - points[i+1].second, 2));
    }
    
    // Return to origin
    total_cost += sqrt(pow(points[n-1].first, 2) + pow(points[n-1].second, 2));

    cout << fixed << setprecision(10) << total_cost << '\n';

    return 0;
}