#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double total_cost = 0.0;
    double x = 0.0, y = 0.0;  // Start at the origin

    for (int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        total_cost += sqrt((xi - x) * (xi - x) + (yi - y) * (yi - y));  // Cost from current point to the next
        x = xi;
        y = yi;
    }

    // Add the cost from the last point back to the origin
    total_cost += sqrt(x * x + y * y);

    cout << fixed << setprecision(10) << total_cost << endl;  // Print the total cost with 10 decimal places
    return 0;
}