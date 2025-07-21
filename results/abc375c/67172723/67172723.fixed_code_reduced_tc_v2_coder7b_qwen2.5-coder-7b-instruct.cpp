#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    double px = 0, py = 0;
    double ans = 0;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        ans += sqrt((x - px) * (x - px) + (y - py) * (y - py));
        px = x;
        py = y;
    }

    ans += sqrt(px * px + py * py);
    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}