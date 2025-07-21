#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<long double, long double>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long double ans = 0;
    long double x = 0, y = 0;

    for (const auto& [nx, ny] : points) {
        long double dx = nx - x;
        long double dy = ny - y;
        ans += sqrtl(dx * dx + dy * dy);
        x = nx;
        y = ny;
    }

    // Add distance back to the origin
    ans += sqrtl(x * x + y * y);

    cout << fixed << setprecision(15) << ans << '\n';

    return 0;
}