#include <bits/stdc++.h>
using namespace std;

int main() {
    long double ans = 0;
    int N;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nextX >> nextY;
        long double cost = sqrt(powl(nowX - nextX, 2.0) + powl(nowY - nextY, 2.0));
        ans += cost;
        nowX = nextX;
        nowY = nextY;
    }

    long double cost = sqrt(powl(nowX - 0, 2.0) + powl(nowY - 0, 2.0));
    ans += cost;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}