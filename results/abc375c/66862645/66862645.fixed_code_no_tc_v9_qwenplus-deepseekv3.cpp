#include <bits/stdc++.h>
using namespace std;

int main() {
    long double ans = 0;
    int N;
    long long nowX = 0, nowY = 0;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        long long nextX, nextY;
        cin >> nextX >> nextY;
        
        long long dx = nowX - nextX;
        long long dy = nowY - nextY;
        ans += sqrtl(dx * dx + dy * dy);
        
        nowX = nextX;
        nowY = nextY;
    }
    
    // Add distance back to origin
    ans += sqrtl(nowX * nowX + nowY * nowY);
    
    cout << fixed << setprecision(10) << ans << endl;
    
    return 0;
}