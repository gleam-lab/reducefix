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

    // Calculate the total cost from the origin to the first point, then visit all points, and finally return to the origin
    long double total_cost = 0.0;
    for (int i = 0; i <= N; ++i) {
        total_cost += sqrt(pow(points[i].first, 2) + pow(points[i].second, 2));
    }

    cout << fixed << setprecision(12) << total_cost << endl;

    return 0;
}