#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double px = 0, py = 0; // Use double to avoid integer overflow during calculations
    double ans = 0;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;
        py = y;
    }
    
    ans += hypot(px, py); // Distance from last point back to origin
    printf("%.10f\n", ans);
    return 0;
}