#include <bits/stdc++.h>
using namespace std;

int main() {

    long double cost = 0;
    long double ans = 0;
    int operation;
    long double nowX = 0, nowY = 0;
    long double nextX, nextY;

    cin >> operation;

    for (int i = 0; i < operation; i++) {
        cin >> nextX >> nextY;

        // Calculate distance to the next point
        long double dx = nextX - nowX;
        long double dy = nextY - nowY;
        ans += sqrtl(dx * dx + dy * dy);

        // Update current position
        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    ans += sqrtl(nowX * nowX + nowY * nowY);

    cout << ans << endl;

    return 0;
}