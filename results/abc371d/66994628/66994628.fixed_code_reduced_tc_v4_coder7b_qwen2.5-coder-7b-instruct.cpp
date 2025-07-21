#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
long long x[MAXN], p[MAXN], sum[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        // Find the correct positions using binary search
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        auto it_r = upper_bound(x + 1, x + n + 1, r);

        int idx_l = it_l - x;
        int idx_r = it_r - x;

        // Adjust indices if necessary
        if (idx_l > n || x[idx_l] < l) idx_l++;
        if (idx_r > n || x[idx_r] > r) idx_r--;

        // Calculate the result
        long long result = sum[min(idx_r, n)] - sum[max(idx_l - 1, 0)];
        cout << result << '\n';
    }

    return 0;
}