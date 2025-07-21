#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N + 1);
    points[0] = {0, 0}; // Starting at origin (0, 0)
    
    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    long double total_cost = 0.0;
    
    for (int i = 1; i <= N; ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        total_cost += sqrtl(dx * dx + dy * dy);
    }
    
    // Add the distance back to the origin
    long long dx = points[N].first - points[0].first;
    long long dy = points[N].second - points[0].second;
    total_cost += sqrtl(dx * dx + dy * dy);
    
    // Set precision for floating point output
    cout << fixed << setprecision(10);
    cout << total_cost << endl;
    
    return 0;
}