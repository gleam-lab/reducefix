#include <bits/stdc++.h>
using namespace std;

int main() {
    long double ans = 0.0;
    int N;
    cin >> N;
    
    int nowX = 0, nowY = 0;
    for (int i = 0; i < N; ++i) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        long double dx = nowX - nextX;
        long double dy = nowY - nextY;
        ans += sqrtl(dx * dx + dy * dy);
        nowX = nextX;
        nowY = nextY;
    }
    
    long double dx = nowX;
    long double dy = nowY;
    ans += sqrtl(dx * dx + dy * dy);
    
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}