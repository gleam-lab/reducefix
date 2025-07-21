#include <bits/stdc++.h>
using namespace std;

int main() {
    long double cost = 0;
    long double ans = 0;
    int N;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nextX >> nextY;

        // Calculate the Euclidean distance squared to avoid floating-point precision issues
        cost = (powl((nowX - nextX), 2.0) + powl((nowY - nextY), 2.0));

        // Update current position
        nowX = nextX;
        nowY = nextY;

        // Add the square root of the distance to the total cost
        ans += powl(cost, 0.5);
    }

    // Return to the origin
    cost = (powl((nowX - 0), 2.0) + powl((nowY - 0), 2.0));
    ans += powl(cost, 0.5);

    cout << ans << endl;

    return 0;
}