#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0;

    // Calculate distances between consecutive points
    for (int i = 0; i < N - 1; ++i) {
        double dx = points[i + 1].first - points[i].first;
        double dy = points[i + 1].second - points[i].second;
        totalCost += sqrt(dx * dx + dy * dy);
    }

    // Calculate distance from the last point back to the origin
    double dx = points[0].first - points[N - 1].first;
    double dy = points[0].second - points[N - 1].second;
    totalCost += sqrt(dx * dx + dy * dy);

    // Output the total cost
    printf("%.10f\n", totalCost);

    return 0;
}