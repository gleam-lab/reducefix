#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 1); // Using long long to prevent overflow in prefix sums
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    // Build prefix sum array
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + x[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;

        // Use lower_bound and upper_bound to find the range indices
        int left = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        int right = upper_bound(x.begin() + 1, x.end(), R) - x.begin() - 1;

        if (left > right) {
            cout << 0 << "\n";
        } else {
            cout << prefix_sum[right] - prefix_sum[left - 1] << "\n";
        }
    }

    return 0;
}