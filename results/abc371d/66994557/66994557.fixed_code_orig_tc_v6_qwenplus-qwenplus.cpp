#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 1);  // Use 1-based indexing
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    vector<long long> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // Prefix sum of p
    vector<long long> sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;

        // Find the first index where x[i] >= L using lower_bound
        int left = lower_bound(x.begin() + 1, x.end(), L) - x.begin();

        // Find the first index where x[i] > R using upper_bound
        int right = upper_bound(x.begin() + 1, x.end(), R) - x.begin();

        // Sum from p[left] to p[right - 1]
        cout << sum[right - 1] - sum[left - 1] << '\n';
    }

    return 0;
}