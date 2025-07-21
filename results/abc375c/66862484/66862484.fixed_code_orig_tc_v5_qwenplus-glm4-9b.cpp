#include <iostream>
#include <vector>
#include <cmath>  // For sqrt and pow functions

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;  // Use double for higher precision during calculations
    long long current_x = 0, current_y = 0;  // Starting from the origin

    for (int i = 0; i < N; ++i) {
        long long x = points[i].first;
        long long y = points[i].second;

        // Calculate the distance from the current point to the next point
        double distance = sqrt(pow(current_x - x, 2) + pow(current_y - y, 2));
        total_cost += distance;

        // Update current position
        current_x = x;
        current_y = y;
    }

    // Calculate the distance back to the origin
    double distance_to_origin = sqrt(pow(current_x, 2) + pow(current_y, 2));
    total_cost += distance_to_origin;

    // Since the input constraints suggest that the answer should have an absolute or relative
    // error of at most \( 10^{-6} \), we use printf with a precision of 6 decimal places
    printf("%.6f\n", total_cost);

    return 0;
}