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

        long double dx = nowX - nextX;
        long double dy = nowY - nextY;

        ans += sqrtl(dx * dx + dy * dy);

        nowX = nextX;
        nowY = nextY;
    }

    // After loop, nowX and nowY are the last point's coordinates
    ans += sqrtl(nowX * nowX + nowY * nowY);

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}