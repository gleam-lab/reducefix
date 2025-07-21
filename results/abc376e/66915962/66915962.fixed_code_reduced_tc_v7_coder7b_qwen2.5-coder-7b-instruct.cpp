#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Find the best combination
        ll ans = LLONG_MAX;
        for (int i = 0; i <= n - k; ++i) {
            ll max_a = a[i + k - 1];
            ll sum_b = 0;
            for (int j = 0; j < k; ++j) {
                sum_b += b[i + j];
            }
            ans = min(ans, max_a * sum_b);
        }

        cout << ans << '\n';
    }

    return 0;
}