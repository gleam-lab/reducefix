#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long px = 0, py = 0;
    double ans = 0;
    long long x, y;
    
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        ans += sqrt((x - px) * (x - px) + (y - py) * (y - py));
        px = x;
        py = y;
    }

    // Return to the origin
    ans += sqrt(px * px + py * py);

    printf("%.10f\n", ans);
    return 0;
}