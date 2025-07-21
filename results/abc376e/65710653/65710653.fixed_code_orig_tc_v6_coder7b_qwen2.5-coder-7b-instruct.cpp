#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll ans = LLONG_MAX;
        for (int i = 0; i <= n - k; ++i) {
            ll max_a = a[i + k - 1];
            ll sum_b = accumulate(b.begin() + i, b.begin() + i + k, 0LL);
            ans = min(ans, max_a * sum_b);
        }

        cout << ans << '\n';
    }

    return 0;
}