#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cout.precision(10); // Set precision for floating point output
    cout << fixed; // Fixed-point notation for floating point numbers

    cin >> N; // Read the number of points

    // Initialize variables
    long double ans = 0; // To store the total cost
    int nowX = 0, nowY = 0; // Starting point at the origin

    // Loop through each point
    for (int i = 0; i < N; i++) {
        int nextX, nextY;
        cin >> nextX >> nextY;

        // Calculate the Euclidean distance squared between the current point and the next point
        long double cost = (long double)(nextX - nowX) * (nextX - nowX) + 
                           (long double)(nextY - nowY) * (nextY - nowY);

        // Update the total cost
        ans += cost;

        // Update the current position to the next point
        nowX = nextX;
        nowY = nextY;
    }

    // Calculate the Euclidean distance squared between the last point and the origin
    long double finalCost = (long double)(nowX - 0) * (nowX - 0) +
                             (long double)(nowY - 0) * (nowY - 0);

    // Update the total cost with the distance to the origin
    ans += finalCost;

    // Print the total cost, square root is not needed as the cost is already squared
    cout << ans << endl;

    return 0;
}