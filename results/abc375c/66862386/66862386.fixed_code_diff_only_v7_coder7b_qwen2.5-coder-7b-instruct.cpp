#include <bits/stdc++.h>
using namespace std;

int main() {
    long double cost = 0;
    long double ans = 0;
    int N;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> nextX >> nextY;

        // Calculate Euclidean distance squared to avoid precision issues with sqrt
        cost = powl((nowX - nextX), 2.0) + powl((nowY - nextY), 2.0);
        nowX = nextX;
        nowY = nextY;

        // Add the cost of moving to the next point
        ans += powl(cost, 0.5);
    }

    // Return to the origin
    cost = powl((nowX - 0), 2.0) + powl((nowY - 0), 2.0);
    ans += powl(cost, 0.5);

    cout << ans << endl;

    return 0;
}