#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long double cost = 0;
    long double ans = 0;
    int n;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nextX >> nextY;
        cost = sqrt(pow(nextX - nowX, 2.0) + pow(nextY - nowY, 2.0));
        ans += cost;
        nowX = nextX;
        nowY = nextY;
    }

    cost = sqrt(pow(nowX, 2.0) + pow(nowY, 2.0));
    ans += cost;

    cout << ans << endl;

    return 0;
}