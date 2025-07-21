#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long x = 0, y = 0;
    double total_cost = 0.0;

    // Read coordinates of all points
    for(int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        
        // Calculate distance from current position to next point
        total_cost += sqrt((xi - x) * (xi - x) + (yi - y) * (yi - y));
        
        // Update current position
        x = xi;
        y = yi;
    }

    // Return to the origin
    total_cost += sqrt(x * x + y * y);

    // Print the total cost with high precision
    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}