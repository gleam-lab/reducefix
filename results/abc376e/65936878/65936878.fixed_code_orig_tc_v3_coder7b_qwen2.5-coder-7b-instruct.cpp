#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> A(n), B(n);
        
        // Read input arrays
        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < n; ++i) cin >> B[i];
        
        // Sort both arrays
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        // Calculate the result
        int ans = LLONG_MAX;
        for(int i = 0; i <= n - k; ++i) {
            int max_A = A[n - k + i];
            int sum_B = accumulate(B.begin() + i, B.begin() + i + k, 0LL);
            ans = min(ans, max_A * sum_B);
        }
        
        // Output the result
        cout << ans << '\n';
    }

    return 0;
}