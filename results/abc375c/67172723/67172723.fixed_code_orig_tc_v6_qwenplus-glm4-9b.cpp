#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int px = 0, py = 0;
    double ans = 0.0;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;
        py = y;
    }

    // Add the distance from the last point back to the origin
    ans += hypot(px, py);

    // Print the answer with the required precision
    printf("%.10f\n", ans);
    return 0;
}