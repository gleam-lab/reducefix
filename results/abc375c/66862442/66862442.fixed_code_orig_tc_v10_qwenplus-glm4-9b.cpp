#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long originateX = 0, originateY = 0;
    double totalDistance = 0.0;

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate distance to the current point
        double distanceToCurrent = sqrt((x - originateX) * (x - originateX) + (y - originateY) * (y - originateY));
        totalDistance += distanceToCurrent;

        // Update the origin to the current point
        originateX = x;
        originateY = y;
    }

    // Calculate the distance from the last point back to the origin
    double distanceBackToOrigin = sqrt((originateX - 0) * (originateX - 0) + (originateY - 0) * (originateY - 0));
    totalDistance += distanceBackToOrigin;

    // Print the total distance
    cout.precision(6);
    cout << fixed << totalDistance << endl;

    return 0;
}