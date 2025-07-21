#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int x, y;
    double ans = 0.0;
    double ox = 0.0, oy = 0.0; // Starting point is the origin (0,0)

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        // Calculate distance from the current position to the next point and
        // add it to the total cost
        ans += sqrt(pow(x - ox, 2) + pow(y - oy, 2));
        // Update current position to the next point
        ox = x;
        oy = y;
    }

    // Add the distance from the last point back to the origin
    ans += sqrt(pow(ox, 2) + pow(oy, 2));

    // Print the total cost, formatted to 7 decimal places
    cout.precision(7);
    cout << fixed << ans << endl;

    return 0;
}