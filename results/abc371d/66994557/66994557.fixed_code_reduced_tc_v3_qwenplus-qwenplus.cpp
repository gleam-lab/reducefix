#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 2); // Extra space to avoid boundary issues
    vector<long long> p(n + 2);
    vector<long long> prefix_sum(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;

        // Find first index where x[i] >= L
        int left = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();

        // Find first index where x[i] > R
        int right = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin();

        // All values from [left, right - 1] are in range [L, R]
        cout << prefix_sum[right - 1] - prefix_sum[left - 1] << '\n';
    }

    return 0;
}