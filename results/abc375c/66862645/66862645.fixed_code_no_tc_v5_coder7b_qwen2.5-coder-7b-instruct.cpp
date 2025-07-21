#include <bits/stdc++.h>
using namespace std;

int main() {

    // Initialize variables to store the number of operations, current position, and total cost
    int n;
    cin >> n;

    // Initialize the starting position at the origin
    long double x = 0, y = 0, cost = 0, total_cost = 0;

    // Loop through each operation
    for(int i = 0; i < n; i++) {
        // Read the next coordinates
        long double nx, ny;
        cin >> nx >> ny;

        // Calculate the Euclidean distance between the current position and the next position
        cost = sqrt(pow(nx - x, 2) + pow(ny - y, 2));

        // Add the distance to the total cost
        total_cost += cost;

        // Update the current position to the next position
        x = nx;
        y = ny;
    }

    // Calculate the distance back to the origin from the last position
    cost = sqrt(x * x + y * y);
    total_cost += cost;

    // Print the total cost
    printf("%.10Lf\n", total_cost);

    return 0;
}