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

        long double dx = abs(nowX - nextX);
        long double dy = abs(nowY - nextY);

        ans += sqrtl(dx * dx + dy * dy);

        nowX = nextX;
        nowY = nextY;
    }

    // Add the cost of returning to the origin
    ans += sqrtl(nowX * nowX + nowY * nowY);

    cout << ans << endl;

    return 0;
}