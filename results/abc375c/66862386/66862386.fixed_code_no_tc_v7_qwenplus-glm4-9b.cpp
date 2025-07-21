#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    double originX = 0.0, originY = 0.0;
    double currentX = 0.0, currentY = 0.0;
    double totalCost = 0.0;

    for (int i = 0; i < n; i++) {
        double nextX, nextY;
        cin >> nextX >> nextY;

        // Calculate the distance from the current point to the next point
        double distance = sqrt(pow(currentX - nextX, 2) + pow(currentY - nextY, 2));
        totalCost += distance;

        // Move to the new point
        currentX = nextX;
        currentY = nextY;
    }

    // Calculate the distance from the last point back to the origin
    double finalDistance = sqrt(pow(currentX - originX, 2) + pow(currentY - originY, 2));
    totalCost += finalDistance;

    // Output the total cost
    cout.precision(10);
    cout << fixed << totalCost << endl;

    return 0;
}