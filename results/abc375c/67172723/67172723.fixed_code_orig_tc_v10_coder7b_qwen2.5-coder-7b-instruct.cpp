#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long px = 0, py = 0;
    double ans = 0;
    int x, y;
    
    // Process each point and calculate the distance to the next point
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;
        py = y;
    }

    // Add the distance from the last point back to the origin
    ans += hypot(px, py);

    printf("%.10f\n", ans);
    return 0;
}