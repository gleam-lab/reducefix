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
        cost = powl((nowX - nextX), 2.0) + powl((nowY - nextY), 2.0);
        nowX = nextX;
        nowY = nextY;
        ans += sqrtl(cost);
    }

    cost = powl(nowX, 2.0) + powl(nowY, 2.0);
    ans += sqrtl(cost);

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}