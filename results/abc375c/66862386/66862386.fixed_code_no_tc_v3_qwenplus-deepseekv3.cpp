#include <bits/stdc++.h>
using namespace std;

int main() {
    long double ans = 0;
    int N;
    long long nowX = 0, nowY = 0;
    long long nextX, nextY;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nextX >> nextY;
        ans += hypot(nextX - nowX, nextY - nowY);
        nowX = nextX;
        nowY = nextY;
    }

    ans += hypot(nowX, nowY);

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}