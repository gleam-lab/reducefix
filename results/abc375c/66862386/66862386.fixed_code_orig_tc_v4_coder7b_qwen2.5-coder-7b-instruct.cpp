#include <bits/stdc++.h>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long double cost = 0;
    long double ans = 0;
    int operation;
    int nowX = 0 , nowY = 0;
    int nextX, nextY;

    cin >> operation;

    for(int i = 0;  i < operation; i++) {
        cin >> nextX >> nextY;

        cost = sqrtl(powl((nowX - nextX), 2.0) + powl((nowY - nextY), 2.0));

        nowX = nextX;
        nowY = nextY;

        ans += cost;
    }

    cost = sqrtl(powl(nowX, 2.0) + powl(nowY, 2.0));
    ans += cost;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}