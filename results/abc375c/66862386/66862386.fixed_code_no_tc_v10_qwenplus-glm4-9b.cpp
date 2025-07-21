#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;
    
    vector<pair<long long, long long>> points(N);
    long long x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        points[i] = {x, y};
    }

    // Calculate the total cost of moving from the origin to each point and back
    long double total_cost = 0.0;
    for (int i = 0; i < N; ++i) {
        long double cost_to_point = sqrt(pow(points[i].first, 2) + pow(points[i].second, 2));
        total_cost += cost_to_point;
        // When moving to the last point, we only add the cost to and from the origin
        if (i == N - 1) {
            total_cost += sqrt(pow(points[i].first, 2) + pow(points[i].second, 2));
        }
    }

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}