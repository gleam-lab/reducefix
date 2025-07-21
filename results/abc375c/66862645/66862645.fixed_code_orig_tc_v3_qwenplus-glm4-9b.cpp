#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    long double total_cost = 0.0;
    int n;
    cin >> n;
    vector<pair<long long, long long>> points(n + 1);
    
    // Read points including the origin
    points[0] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    // Calculate the cost of moving from the origin to each point and back to the origin
    for (int i = 0; i <= n; ++i) {
        total_cost += sqrt(pow(points[i].first - points[i == n ? 0 : i + 1].first, 2) +
                           pow(points[i].second - points[i == n ? 0 : i + 1].second, 2)));
    }
    
    // Output the total cost with a precision of 6 decimal places
    cout.precision(6);
    cout << fixed << total_cost << endl;

    return 0;
}