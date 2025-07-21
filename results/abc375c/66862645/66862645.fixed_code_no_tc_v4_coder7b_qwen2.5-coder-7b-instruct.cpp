#include <bits/stdc++.h>
using namespace std;

int main() {
    long double cost = 0;
    long double ans = 0;
    int n;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nextX >> nextY;

        cost = sqrt(pow(nextX - nowX, 2) + pow(nextY - nowY, 2));

        ans += cost;

        nowX = nextX;
        nowY = nextY;
    }

    cost = sqrt(nowX * nowX + nowY * nowY);
    ans += cost;

    cout << ans << endl;

    return 0;
}