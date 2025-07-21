#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    long double cost = 0;
    long double ans = 0;
    long double nowX = 0, nowY = 0;
    long double nextX, nextY;

    for(int i = 0; i < N; ++i) {
        cin >> nextX >> nextY;

        // Calculate the distance from the current position to the next point
        long double dx = nextX - nowX;
        long double dy = nextY - nowY;
        cost = sqrtl(dx * dx + dy * dy);

        // Add the distance to the total cost
        ans += cost;

        // Update the current position to the next point
        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    long double dx = 0 - nowX;
    long double dy = 0 - nowY;
    cost = sqrtl(dx * dx + dy * dy);
    ans += cost;

    // Print the result with high precision
    cout << setprecision(10) << fixed << ans << endl;

    return 0;
}