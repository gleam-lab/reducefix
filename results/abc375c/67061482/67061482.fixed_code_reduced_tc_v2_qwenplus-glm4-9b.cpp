#include <bits/stdc++.h>
using namespace std;
#include <cmath>

int main() {
    int N;
    cin >> N;
    
    if (N == 0) {
        // If there are no points to visit, the cost is zero.
        cout << 0 << endl;
        return 0;
    }

    double sum = 0.0; // To store the total cost.
    double x, y; // To store the current coordinates.

    cin >> x >> y; // Read the first point and set it as the starting point.
    sum = sqrt(x*x + y*y); // Calculate the cost from origin to the first point.

    for (int i = 1; i < N; ++i) {
        cin >> x >> y; // Read the next point.
        sum += sqrt((x - x)*((x - x) + (y - y))); // Calculate the cost between the last point and the current point.
    }

    // Add the cost from the last point to the origin.
    sum += sqrt((x - 0)*(x - 0) + (y - 0)*(y - 0));

    cout << fixed << setprecision(9) << sum << endl; // Print the total cost with high precision.
}