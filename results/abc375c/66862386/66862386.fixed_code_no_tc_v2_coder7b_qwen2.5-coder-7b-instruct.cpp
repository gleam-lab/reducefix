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

        cost = sqrtl(powl(nowX - nextX, 2.0) + powl(nowY - nextY, 2.0));
        ans += cost;

        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    cost = sqrtl(powl(nowX - 0, 2.0) + powl(nowY - 0, 2.0));
    ans += cost;

    cout << ans << endl;

    return 0;
}