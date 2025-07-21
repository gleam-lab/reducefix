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
    points[0] = {0, 0}; // Starting point is the origin

    for (int i = 1; i <= N; ++i) {
        long long x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    double total_cost = 0.0;

    for (int i = 1; i <= N; ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        total_cost += sqrt(dx * dx + dy * dy); // Calculate the actual distance and add it to total_cost
    }

    // Add the distance from the last point to the origin
    long long dx = points[N].first - points[0].first;
    long long dy = points[N].second - points[0].second;
    total_cost += sqrt(dx * dx + dy * dy);

    // Set precision for the output
    cout << fixed << setprecision(9) << total_cost << endl;

    return 0;
}