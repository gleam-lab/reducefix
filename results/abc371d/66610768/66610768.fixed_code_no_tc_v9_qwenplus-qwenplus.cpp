#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    // Build prefix sum of b[i] over sorted a[i]
    vector<ll> c(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + b[i];
    }

    int m;
    cin >> m;

    while (m--) {
        int l, r;
        cin >> l >> r;

        // Find first index where a[i] >= l
        int left = lower_bound(a.begin() + 1, a.end(), l) - a.begin();

        // Find last index where a[i] <= r
        int right = upper_bound(a.begin() + 1, a.end(), r) - a.begin() - 1;

        if (left > right) {
            cout << 0 << '\n';
        } else {
            cout << c[right] - c[left - 1] << '\n';
        }
    }

    return 0;
}