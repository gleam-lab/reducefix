#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double ans = 0;
    int px = 0, py = 0;
    int x, y;
    
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;
        py = y;
    }
    
    // Return to origin
    ans += hypot(px, py);
    
    // Print with sufficient precision
    printf("%.15f\n", ans);
    
    return 0;
}