#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long px = 0, py = 0;
    long double ans = 0;
    long long x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += hypotl(x - px, y - py);
        px = x;
        py = y;
    }
    
    ans += hypotl(px, py);
    printf("%.10Lf\n", ans);
    return 0;
}