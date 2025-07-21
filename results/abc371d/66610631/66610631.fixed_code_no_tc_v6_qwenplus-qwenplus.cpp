#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;

    vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = b[i] + c[i - 1];
    }

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        // Find first index in a where value >= l
        auto l_i = lower_bound(a.begin() + 1, a.end(), l);
        int left_idx = (l_i - a.begin());

        // Find first index in a where value > r
        auto r_i = upper_bound(a.begin() + 1, a.end(), r);
        int right_idx = (r_i - a.begin()) - 1;

        if (left_idx > right_idx) {
            cout << 0 << '\n';
        } else {
            cout << c[right_idx] - c[left_idx - 1] << '\n';
        }
    }

    return 0;
}