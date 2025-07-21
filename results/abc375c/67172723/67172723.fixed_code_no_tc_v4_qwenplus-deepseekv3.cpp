#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double ans = 0.0;
    int px = 0, py = 0; // Starting at origin
    int x, y;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;
        py = y;
    }
    
    // Add distance from last point back to origin
    ans += hypot(px, py);
    
    printf("%.10f\n", ans);
    return 0;
}