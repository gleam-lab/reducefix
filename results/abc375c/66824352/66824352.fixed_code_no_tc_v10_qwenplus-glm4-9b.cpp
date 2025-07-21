#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Initialize starting point at the origin
    long long x = 0, y = 0;
    long long total_cost = 0;

    // Iterate over each point
    for (int i = 0; i < n; ++i) {
        int X, Y;
        cin >> X >> Y;
        // Calculate the cost to move to the current point from the last point
        total_cost += sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
        // Update the current point to the new point
        x = X;
        y = Y;
    }

    // Calculate the cost to return to the origin
    total_cost += sqrt(x * x + y * y);

    // Print the total cost with a precision of 10 decimal places
    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}