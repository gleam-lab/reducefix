#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N + 1);

    // Read points including the origin for easier calculation
    points[0] = {0, 0};
    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_distance = 0.0;

    // Calculate the total distance traveled
    for (int i = 1; i <= N; ++i) {
        double dx = points[i].first - points[i - 1].first;
        double dy = points[i].second - points[i - 1].second;
        total_distance += sqrt(dx * dx + dy * dy);
    }

    // Set precision for output
    cout << fixed << setprecision(15);
    cout << total_distance << '\n';

    return 0;
}