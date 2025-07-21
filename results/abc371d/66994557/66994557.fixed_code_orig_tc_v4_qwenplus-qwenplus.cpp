#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n + 2); // 1-based indexing
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    vector<long long> p(n + 2);
    vector<long long> prefix_sum(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    int q;
    cin >> q;

    while (q--) {
        long long L, R;
        cin >> L >> R;

        // Find the first index where x[i] >= L using lower_bound
        int left = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();
        // Find the first index where x[i] > R using upper_bound
        int right = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin();

        // The number of elements in range is (right - left)
        cout << prefix_sum[right - 1] - prefix_sum[left - 1] << "\n";
    }

    return 0;
}