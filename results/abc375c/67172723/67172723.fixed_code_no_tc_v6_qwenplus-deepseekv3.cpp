#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double ans = 0.0;
    int px = 0, py = 0;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;
        py = y;
    }
    
    ans += hypot(px, py); // Return to origin from the last point
    printf("%.10f\n", ans);
    
    return 0;
}