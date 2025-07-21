#include <bits/stdc++.h>
using namespace std;

int main() {
    long double cost = 0;
    long double ans = 0;
    int N;
    long double nowX = 0, nowY = 0;
    long double nextX, nextY;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nextX >> nextY;
        long double dx = nowX - nextX;
        long double dy = nowY - nextY;
        ans += sqrtl(dx * dx + dy * dy);
        nowX = nextX;
        nowY = nextY;
    }

    // Calculate the distance from the last point back to the origin
    ans += sqrtl(nowX * nowX + nowY * nowY);

    // Print with sufficient precision
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}