#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Sort A in ascending order and B in descending order
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());

        long long ans = LLONG_MAX;
        for (int i = 0; i <= k && i <= n; ++i) {
            long long maxA = (i > 0 ? a[n - i] : 0);
            long long sumB = accumulate(b.begin(), b.begin() + i, 0LL);
            ans = min(ans, maxA * sumB);
        }

        cout << ans << "\n";
    }

    return 0;
}