#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<pair<long long, long long>> points(N);

    for (long long i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long double total_cost = 0;
    long double current_position_x = 0;
    long double current_position_y = 0;

    // Calculate the cost of moving from the origin to the first point
    total_cost += sqrt(pow(current_position_x - points[0].first, 2) + pow(current_position_y - points[0].second, 2));
    current_position_x = points[0].first;
    current_position_y = points[0].second;

    // Calculate the cost of moving between consecutive points
    for (long long i = 1; i < N; ++i) {
        total_cost += sqrt(pow(current_position_x - points[i].first, 2) + pow(current_position_y - points[i].second, 2));
        current_position_x = points[i].first;
        current_position_y = points[i].second;
    }

    // Calculate the cost of moving back to the origin
    total_cost += sqrt(pow(current_position_x - 0LL, 2) + pow(current_position_y - 0LL, 2));

    cout.precision(30);
    cout << fixed << total_cost << endl;

    return 0;
}