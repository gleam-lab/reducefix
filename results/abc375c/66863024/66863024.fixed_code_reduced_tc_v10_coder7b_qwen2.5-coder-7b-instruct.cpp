#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;

    double x = 0, y = 0;
    double total_cost = 0;

    for(long long i = 0; i < n; ++i) {
        double next_x, next_y;
        cin >> next_x >> next_y;

        // Calculate the distance from current position to the next point
        double dx = next_x - x;
        double dy = next_y - y;
        double distance = sqrt(dx * dx + dy * dy);

        // Add the distance to the total cost
        total_cost += distance;

        // Update the current position
        x = next_x;
        y = next_y;
    }

    // Return to the origin
    double return_distance = sqrt(x * x + y * y);
    total_cost += return_distance;

    // Output the total cost with high precision
    printf("%.10f\n", total_cost);

    return 0;
}