#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        c[i + 1] = c[i] + b[i];
    }

    int m;
    cin >> m;
    while (m--) {
        ll l, r;
        cin >> l >> r;

        // Find first index where a[i] >= l using lower_bound
        auto l_idx = lower_bound(a.begin(), a.end(), l);
        // Find first index where a[i] > r using upper_bound
        auto r_idx = upper_bound(a.begin(), a.end(), r);

        int left = l_idx - a.begin();
        int right = r_idx - a.begin();

        cout << c[right] - c[left] << "\n";
    }

    return 0;
}