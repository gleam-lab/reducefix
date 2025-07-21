#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    long double ans = 0;
    long double x = 0, y = 0;  // Starting point is the origin, so x and y are initially 0.

    for (int i = 0; i < N; ++i) {
        long double nx, ny;
        cin >> nx >> ny;
        // Calculate distance between the current point and the next point
        ans += sqrt((nx - x) * (nx - x) + (ny - y) * (ny - y));
        // Update current position
        x = nx;
        y = ny;
    }

    // Add the distance from the last point back to the origin
    ans += sqrt(x * x + y * y);

    // Print the total cost
    cout.precision(10);
    cout << fixed << ans << endl;

    return 0;
}