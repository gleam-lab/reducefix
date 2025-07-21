#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    double x = 0, y = 0, ans = 0.0;
    double px, py;  // This will hold the coordinates of the previous point.
    int X, Y;
    for (int i = 0; i < n; i++) {
        cin >> X >> Y;
        ans += hypot(X - px, Y - py);  // Calculate distance from previous point to current point.
        px = X, py = Y;  // Update previous point coordinates.
    }

    // Add the distance from the last point to the origin.
    ans += hypot(px, py);
    
    cout.precision(10);
    cout << fixed << ans << endl;
    return 0;
}