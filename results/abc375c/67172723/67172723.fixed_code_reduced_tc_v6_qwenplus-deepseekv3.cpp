#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int px = 0, py = 0;
    double ans = 0;
    int x = 0, y = 0; // Initialize x and y to handle n=0 case (though n>=1 per constraints)
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;
        py = y;
    }
    
    ans += hypot(x, y);
    printf("%.17f\n", ans);
    return 0;
}