#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double ans = 0.0;
    int px = 0, py = 0;  // Current position starts at origin
    int x, y;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;  // Update current position to the new point
        py = y;
    }
    
    // Add distance from last point back to origin
    ans += hypot(px, py);
    
    printf("%.15f\n", ans);
    return 0;
}