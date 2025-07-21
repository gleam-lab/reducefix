#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> points(N + 1);
    points[0] = {0, 0}; // Starting at the origin

    double total_cost = 0.0;

    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
        total_cost += sqrt(pow(points[i - 1].first - points[i].first, 2) + pow(points[i - 1].second - points[i].second, 2));
    }

    // Return to the origin
    total_cost += sqrt(pow(points[N].first, 2) + pow(points[N].second, 2));

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}