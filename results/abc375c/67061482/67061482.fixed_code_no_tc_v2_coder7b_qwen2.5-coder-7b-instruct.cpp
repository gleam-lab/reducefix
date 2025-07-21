#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);

    // Read all points
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;

    // Calculate the cost of moving from one point to another
    for (size_t i = 0; i < N - 1; ++i) {
        total_cost += sqrt(pow(points[i].first - points[i + 1].first, 2) +
                           pow(points[i].second - points[i + 1].second, 2));
    }

    // Add the cost of returning to the origin
    total_cost += sqrt(pow(points[N - 1].first, 2) + pow(points[N - 1].second, 2));

    cout << total_cost << endl;

    return 0;
}