#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    double x = 0, y = 0;
    double total_cost = 0;

    for(int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;

        // Calculate the distance to the next point
        double dx = xi - x;
        double dy = yi - y;
        double distance = sqrt(dx * dx + dy * dy);

        total_cost += distance;

        // Update current position
        x = xi;
        y = yi;
    }

    // Return to the origin
    double back_to_origin = sqrt(x * x + y * y);
    total_cost += back_to_origin;

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}