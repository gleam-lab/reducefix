#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long px = 0, py = 0;
    double ans = 0.0;

    vector<pair<long long, long long>> points(n);
    for (auto &[x, y] : points) {
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;
        py = y;
    }

    ans += hypot(static_cast<double>(px), static_cast<double>(py));
    cout.precision(15);
    cout << fixed << ans << endl;

    return 0;
}