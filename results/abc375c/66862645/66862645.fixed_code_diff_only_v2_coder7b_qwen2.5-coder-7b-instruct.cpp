#include <bits/stdc++.h>
using namespace std;

int main() {
    long double cost = 0;
    long double ans = 0;
    int n;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> nextX >> nextY;

        cost = sqrtl(powl((nowX - nextX), 2.0) + powl((nowY - nextY), 2.0));

        ans += cost;

        nowX = nextX;
        nowY = nextY;
    }

    cost = sqrtl(powl(nowX, 2.0) + powl(nowY, 2.0));
    ans += cost;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}