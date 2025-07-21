#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N + 1);

    // Read points and add the origin as the starting point
    points[0] = {0, 0};
    for (int i = 1; i <= N; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    double total_cost = 0.0;

    // Calculate the cost of moving from the origin to each point and back to the origin
    for (int i = 1; i <= N; ++i) {
        total_cost += sqrt(pow(points[i].first - points[i - 1].first, 2) +
                           pow(points[i].second - points[i - 1].second, 2));
    }
    // Add the distance from the last point back to the origin
    total_cost += sqrt(pow(points[N].first, 2) + pow(points[N].second, 2));

    cout.precision(12); // Set precision for output
    cout << fixed << total_cost << endl;

    return 0;
}