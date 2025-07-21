#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    double ans = 0.0;
    double x, y;
    double prevX = 0, prevY = 0;

    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        // Calculate the distance from the origin to the current point
        ans += sqrt(pow(prevX - x, 2) + pow(prevY - y, 2));
        // Update previous point to current point
        prevX = x;
        prevY = y;
    }

    // Add the distance from the last point back to the origin
    ans += sqrt(pow(prevX, 2) + pow(prevY, 2));

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}