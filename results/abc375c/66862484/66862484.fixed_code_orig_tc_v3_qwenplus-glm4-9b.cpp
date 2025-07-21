#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double x = 0.0, y = 0.0, total_cost = 0.0;

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;

        // Calculate squared distance from current position to the new point
        total_cost += (x - X) * (x - X) + (y - Y) * (y - Y);
        
        // Update current position
        x = X;
        y = Y;
    }

    // Add the squared distance from the last point to the origin
    total_cost += (x - 0) * (x - 0) + (y - 0) * (y - 0);

    // Calculate the square root of the total squared distance
    total_cost = sqrt(total_cost);

    // Output the result with sufficient precision
    cout.precision(12);
    cout << fixed << total_cost << endl;

    return 0;
}