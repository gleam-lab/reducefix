#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long double> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        long double dx = x[i] - x[(i + 1) % n];
        long double dy = y[i] - y[(i + 1) % n];
        ans += sqrt(dx * dx + dy * dy);
    }

    cout << ans << '\n';

    return 0;
}