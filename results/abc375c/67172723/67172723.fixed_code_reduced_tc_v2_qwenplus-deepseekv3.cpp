#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long px = 0, py = 0;
    double ans = 0.0;
    long long x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += hypot((double)(x - px), (double)(y - py));
        px = x;
        py = y;
    }
    
    ans += hypot((double)px, (double)py);
    printf("%.15lf\n", ans);
    return 0;
}