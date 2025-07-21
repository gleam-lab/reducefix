#include <bits/stdc++.h>
using namespace std;

int main() {
    long double cost = 0;
    long double ans = 0;
    int N;
    long double nowX = 0, nowY = 0;
    long double prevX = 0, prevY = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        long double nextX, nextY;
        cin >> nextX >> nextY;

        // Calculate the cost from the previous point to the current point
        long double dx = prevX - nextX;
        long double dy = prevY - nextY;
        ans += sqrtl(dx * dx + dy * dy);

        prevX = nextX;
        prevY = nextY;
    }

    // Calculate the cost from the last point back to the origin
    long double dx = prevX - nowX;
    long double dy = prevY - nowY;
    ans += sqrtl(dx * dx + dy * dy);

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}