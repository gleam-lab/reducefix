#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> x(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + p[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        auto it_l = upper_bound(begin(x), end(x), l);
        auto it_r = lower_bound(begin(x), end(x), r);

        int idx_l = distance(begin(x), it_l);
        int idx_r = distance(begin(x), it_r);

        long long result = prefix_sum[idx_r] - prefix_sum[idx_l];
        cout << result << '\n';
    }

    return 0;
}