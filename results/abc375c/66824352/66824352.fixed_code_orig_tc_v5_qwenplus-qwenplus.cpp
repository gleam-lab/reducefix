#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double total = 0.0;

    cin >> n;

    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long long curr_x = 0, curr_y = 0;

    for (const auto& p : points) {
        long long dx = curr_x - p.first;
        long long dy = curr_y - p.second;
        total += sqrt(static_cast<double>(dx * dx + dy * dy));
        curr_x = p.first;
        curr_y = p.second;
    }

    // Return to origin
    total += sqrt(static_cast<double>(curr_x * curr_x + curr_y * curr_y));

    cout << fixed << setprecision(15) << total << endl;

    return 0;
}