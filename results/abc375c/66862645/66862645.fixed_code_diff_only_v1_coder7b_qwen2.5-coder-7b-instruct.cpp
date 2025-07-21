#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double cost = 0;
    long double ans = 0;
    int operation;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> operation;

    for(int i = 0; i < operation; i++) {
        cin >> nextX >> nextY;

        cost = sqrtl(powl((nowX - nextX), 2.0) + powl((nowY - nextY), 2.0));

        nowX = nextX;
        nowY = nextY;

        ans += cost;
    }

    cost = sqrtl(powl((nowX - 0), 2.0) + powl((nowY - 0), 2.0));
    ans += cost;

    cout << ans << endl;

    return 0;
}