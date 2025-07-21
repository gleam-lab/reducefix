#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> A(n), B(n);
        
        // Read input
        for (int& a : A) cin >> a;
        for (int& b : B) cin >> b;

        // Sort arrays
        sort(A.begin(), A.end());
        sort(B.rbegin(), B.rend());

        // Initialize variables
        int ans = LLONG_MAX;
        for (int i = 0; i <= n - k; ++i) {
            int current_max_A = A[i];
            int current_sum_B = 0;
            for (int j = 0; j < k; ++j) {
                current_sum_B += B[j + i];
            }
            ans = min(ans, current_max_A * current_sum_B);
        }

        cout << ans << '\n';
    }

    return 0;
}