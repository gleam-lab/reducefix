#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long double cost = 0;
    long double ans = 0;
    int N;
    long double nowX = 0, nowY = 0;
    long double nextX, nextY;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> nextX >> nextY;

        long double dx = nowX - nextX;
        long double dy = nowY - nextY;

        ans += sqrtl(dx * dx + dy * dy);

        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    ans += sqrtl(nowX * nowX + nowY * nowY);

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}