#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    long double ans = 0.0;
    long double curX = 0, curY = 0;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;

        // Calculate the distance to the next point
        long double dist = sqrt(pow(curX - x, 2) + pow(curY - y, 2));

        // Add the distance to the total cost
        ans += dist;

        // Update current position
        curX = x;
        curY = y;
    }

    // Add the distance from the last point back to the origin
    ans += sqrt(pow(curX, 2) + pow(curY, 2));

    // Print the total cost
    cout.precision(9);
    cout << fixed << ans << endl;

    return 0;
}