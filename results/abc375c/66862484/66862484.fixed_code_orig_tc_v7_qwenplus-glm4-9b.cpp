#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N + 1); // +1 for the return to origin
    long long total_cost = 0;

    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the distance from origin to the first point
    total_cost += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));

    // Calculate the distances between each pair of points
    for (int i = 1; i < N; ++i) {
        total_cost += sqrt(pow(points[i].first - points[i - 1].first, 2) + pow(points[i].second - points[i - 1].second, 2));
    }

    // Calculate the distance from the last point back to the origin
    total_cost += sqrt(pow(points[N].first, 2) + pow(points[N].second, 2));

    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}