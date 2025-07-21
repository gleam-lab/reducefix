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
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> p[i];

    vector<long long> prefix_sum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + p[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int pos_l = lower_bound(x.begin(), x.end(), l) - x.begin();
        int pos_r = upper_bound(x.begin(), x.end(), r) - x.begin();

        long long result = prefix_sum[pos_r] - prefix_sum[pos_l];
        cout << result << '\n';
    }

    return 0;
}