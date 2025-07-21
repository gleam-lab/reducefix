#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q;
long long x[MAXN], p[MAXN];
long long prefix_sum[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;

        // Find the first index where x[i] >= L using lower_bound
        int left = lower_bound(x + 1, x + n + 1, L) - x;

        // Find the first index where x[i] > R using upper_bound
        int right = upper_bound(x + 1, x + n + 1, R) - x;

        // The valid indices are from [left, right - 1]
        cout << prefix_sum[right - 1] - prefix_sum[left - 1] << '\n';
    }

    return 0;
}