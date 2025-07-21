#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    double originX = 0.0, originY = 0.0;
    double totalDistance = 0.0;

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        x -= originX; // Subtract current location from destination to avoid large intermediate values
        y -= originY;

        totalDistance += sqrt(x*x + y*y); // Calculate and add the distance
        originX = x; // Update current location
        originY = y;
    }

    // Return to origin and add this distance
    totalDistance += sqrt(originX * originX + originY * originY);

    // Print with sufficient precision
    cout.precision(9); // Set precision to 9 decimal places
    cout << fixed << totalDistance << endl;

    return 0;
}