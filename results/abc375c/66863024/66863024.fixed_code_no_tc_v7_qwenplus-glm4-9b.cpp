#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<long long, long long>> points(N + 1);

    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long double total_cost = 0.0;

    // Calculate the cost for the initial movement to the first point
    total_cost += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));

    // Calculate the cost for moving through all points in the sequence
    for (int i = 0; i < N - 1; ++i) {
        long long dx = points[i + 1].first - points[i].first;
        long long dy = points[i + 1].second - points[i].second;
        total_cost += sqrt(dx * dx + dy * dy);
    }

    // Calculate the cost to return to the origin
    total_cost += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));

    // Print the total cost, considering the precision requirement
    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}