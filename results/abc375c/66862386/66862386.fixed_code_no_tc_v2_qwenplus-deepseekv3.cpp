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
        long long dx = nowX - nextX;
        long long dy = nowY - nextY;
        ans += sqrtl(dx * dx + dy * dy);
        nowX = nextX;
        nowY = nextY;
    }

    long long dx = nowX - 0;
    long long dy = nowY - 0;
    ans += sqrtl(dx * dx + dy * dy);

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}