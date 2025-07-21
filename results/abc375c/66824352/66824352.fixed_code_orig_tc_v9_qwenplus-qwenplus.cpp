#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    double total = 0.0;
    int curr_x = 0, curr_y = 0;
    
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    for (const auto& p : points) {
        long long dx = static_cast<long long>(curr_x) - p.first;
        long long dy = static_cast<long long>(curr_y) - p.second;
        total += sqrt(static_cast<double>(dx * dx + dy * dy));
        curr_x = p.first;
        curr_y = p.second;
    }

    // Return to origin
    total += sqrt(static_cast<double>(static_cast<long long>(curr_x) * curr_x + static_cast<long long>(curr_y) * curr_y));

    cout << fixed << setprecision(15) << total << endl;

    return 0;
}