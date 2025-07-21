#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 2), p(n + 2); // Extra space to avoid boundary issues

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // Prefix sum of p
    vector<long long> sum(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;

        // Find the first index where x[i] >= L
        int left = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();

        // Find the first index where x[i] > R
        int right = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin();

        // Elements from left to right-1 are in the range [L, R]
        cout << sum[right - 1] - sum[left - 1] << '\n';
    }

    return 0;
}