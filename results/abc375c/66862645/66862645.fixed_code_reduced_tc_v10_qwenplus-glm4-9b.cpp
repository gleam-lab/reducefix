#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N + 1);

    // Initialize the first point as the origin
    points[0] = {0, 0};

    // Read the coordinates of the remaining N points
    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Initialize the answer and the previous position
    double ans = 0.0;
    int prevX = 0, prevY = 0;

    // Calculate the total cost
    for (int i = 1; i <= N; ++i) {
        int currX = points[i].first;
        int currY = points[i].second;

        // Calculate the distance from the previous point to the current point
        double distance = sqrt(pow(currX - prevX, 2) + pow(currY - prevY, 2));

        // Add the distance to the total cost
        ans += distance;

        // Update the previous point
        prevX = currX;
        prevY = currY;
    }

    // Output the total cost
    cout.precision(10);
    cout << fixed << ans << endl;

    return 0;
}