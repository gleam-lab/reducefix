#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    long long px = 0, py = 0;
    double ans = 0.0;
    
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        long long dx = x - px;
        long long dy = y - py;
        ans += sqrt(dx*dx + dy*dy);
        px = x;
        py = y;
    }
    
    // Add distance back to origin
    ans += sqrt(px*px + py*py);
    
    cout << fixed << setprecision(15) << ans << '\n';
    return 0;
}