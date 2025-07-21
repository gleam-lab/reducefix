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

        auto left = lower_bound(x.begin(), x.end(), l);
        auto right = upper_bound(x.begin(), x.end(), r);

        int left_idx = left - x.begin();
        int right_idx = right - x.begin();

        cout << prefix_sum[right_idx] - prefix_sum[left_idx] << "\n";
    }

    return 0;
}