#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n + 2), p(n + 2); // Using long long to prevent overflow

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // Prefix sum of p
    vector<long long> sum(n + 2);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + p[i];
    }

    int q;
    cin >> q;

    while (q--) {
        long long L, R;
        cin >> L >> R;

        // Use lower_bound and upper_bound on the sorted x array
        auto left = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();
        auto right = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin();

        // Sum from [left, right)
        cout << sum[right - 1] - sum[left - 1] << '\n';
    }

    return 0;
}