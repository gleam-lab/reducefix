#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<ll> p(n), prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        prefix_sum[i + 1] = prefix_sum[i] + p[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        // Use binary search to find the range [lt, rt)
        // All elements in x[lt..rt-1] are in [l, r]
        int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
        int rt = upper_bound(x.begin(), x.end(), r) - x.begin();

        cout << prefix_sum[rt] - prefix_sum[lt] << '\n';
    }

    return 0;
}