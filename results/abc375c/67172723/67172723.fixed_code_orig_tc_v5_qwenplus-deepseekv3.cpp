#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double ans = 0.0;
    int prev_x = 0, prev_y = 0;
    int x, y;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += hypot(x - prev_x, y - prev_y);
        prev_x = x;
        prev_y = y;
    }
    
    // Add the distance from the last point back to the origin
    ans += hypot(prev_x, prev_y);
    
    printf("%.10f\n", ans);
    return 0;
}