#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n;
    vector<LL> a(n + 1), b(n + 1), c(n + 1);

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

        auto l_i = lower_bound(a.begin() + 1, a.end(), l);
        auto r_i = upper_bound(a.begin() + 1, a.end(), r);

        if (r_i == a.end() && l_i == a.begin() + 1) {
            cout << c[n] << '\n';
        } else if (r_i == a.end()) {
            cout << c[n] - c[l_i - a.begin() - 1] << '\n';
        } else if (l_i == a.begin() + 1) {
            cout << c[r_i - a.begin() - 1] << '\n';
        } else {
            cout << c[r_i - a.begin() - 1] - c[l_i - a.begin() - 1] << '\n';
        }
    }

    return 0;
}