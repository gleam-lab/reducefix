#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long double cost = 0;
    long double ans = 0;
    int nowX = 0, nowY = 0;

    cin >> int(N); // Read the number of points
    for (int i = 0; i < N; ++i) {
        int nextX, nextY;
        cin >> nextX >> nextY;

        // Calculate the cost of moving from the current position to the next point
        cost = sqrt(pow(nextX - nowX, 2) + pow(nextY - nowY, 2));

        // Add this cost to the total cost
        ans += cost;

        // Update the current position to the next point
        nowX = nextX;
        nowY = nextY;
    }

    // Calculate the cost of returning to the origin and add it to the total cost
    cost = sqrt(pow(nowX, 2) + pow(nowY, 2));
    ans += cost;

    // Output the total cost
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}