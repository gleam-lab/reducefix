#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<long long, long long>> points(N + 1);

    // Include the origin at (0, 0) as the starting point
    points[0] = {0, 0};

    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long long total_distance = 0;

    // Calculate the total distance
    for (int i = 1; i <= N; ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        total_distance += dx * dx + dy * dy;
    }

    // Calculate the total cost, which is the square root of the total distance
    // Use long double for the square root to maintain precision
    long double ans = sqrtl(static_cast<long double>(total_distance));

    // Print the result
    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}