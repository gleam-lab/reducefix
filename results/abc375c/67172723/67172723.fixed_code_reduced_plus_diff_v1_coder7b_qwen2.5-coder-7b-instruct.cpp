#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    long long px = 0, py = 0;
    double ans = 0;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        long long dx = x - px, dy = y - py;
        ans += sqrt(dx * dx + dy * dy);
        px = x, py = y;
    }
    
    // Return to origin
    long long dx = 0 - px, dy = 0 - py;
    ans += sqrt(dx * dx + dy * dy);
    
    printf("%.10f\n", ans);
    return 0;
}