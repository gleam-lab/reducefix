#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long px = 0, py = 0;
    double ans = 0.0;

    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < n; ++i) {
        long long cx = points[i].first;
        long long cy = points[i].second;
        ans += hypot(px - cx, py - cy);
        px = cx;
        py = cy;
    }

    ans += hypot(px, py);

    // Use sufficient precision to meet error tolerance
    cout.precision(15);
    cout << fixed << ans << endl;

    return 0;
}