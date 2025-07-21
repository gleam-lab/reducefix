#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long double cost = 0;
    long double ans = 0;
    int n;
    long double nowX = 0, nowY = 0;
    long double nextX, nextY;

    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> nextX >> nextY;

        long double dx = nowX - nextX;
        long double dy = nowY - nextY;

        ans += sqrtl(dx * dx + dy * dy);

        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    ans += sqrtl(nowX * nowX + nowY * nowY);

    cout << setprecision(15) << ans << endl;

    return 0;
}