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
        long double dx = nextX - nowX;
        long double dy = nextY - nowY;
        ans += sqrtl(dx * dx + dy * dy);
        nowX = nextX;
        nowY = nextY;
    }

    long double dx = 0 - nowX;
    long double dy = 0 - nowY;
    ans += sqrtl(dx * dx + dy * dy);

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}