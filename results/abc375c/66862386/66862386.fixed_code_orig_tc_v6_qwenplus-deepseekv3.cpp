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
        cost = sqrtl((nowX - nextX) * (nowX - nextX) + (nowY - nextY) * (nowY - nextY));
        nowX = nextX;
        nowY = nextY;
        ans += cost;
    }

    cost = sqrtl((nowX - 0) * (nowX - 0) + (nowY - 0) * (nowY - 0));
    ans += cost;

    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}