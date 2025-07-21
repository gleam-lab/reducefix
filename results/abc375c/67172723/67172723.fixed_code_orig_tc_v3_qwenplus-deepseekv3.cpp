#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long px = 0, py = 0; // Use long long to avoid integer overflow
    double ans = 0.0;
    
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;
        py = y;
    }
    
    // Return to the origin from the last point visited
    ans += hypot(px, py);
    
    printf("%.15f\n", ans);
    return 0;
}