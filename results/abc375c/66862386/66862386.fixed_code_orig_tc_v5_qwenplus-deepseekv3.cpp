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
        cost = sqrtl((nowX - nextX) * (nowX - nextX) + (nowY - nextY) * (nowY - nextY));
        nowX = nextX;
        nowY = nextY;
        ans += cost;
    }

    cost = sqrtl(nowX * nowX + nowY * nowY);
    ans += cost;

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}