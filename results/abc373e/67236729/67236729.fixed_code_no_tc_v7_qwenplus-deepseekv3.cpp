#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2e5 + 10;
i64 a[N], b[N], sm[N];

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<i64> A(n);
    for (auto &x : A) cin >> x;
    
    vector<i64> B = A;
    sort(B.begin(), B.end());
    
    // Precompute suffix sums
    vector<i64> suffix(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + B[i];
    }
    
    for (int i = 0; i < n; ++i) {
        i64 x = A[i];
        i64 low = 0, high = k, ans = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_val = x + mid;
            
            // Find how many elements are > new_val
            auto it = upper_bound(B.begin(), B.end(), new_val);
            int cnt = B.end() - it;
            
            if (cnt < m) {
                // Already satisfies condition
                ans = mid;
                high = mid - 1;
                continue;
            }
            
            // Need to make sure at most m-1 candidates have > new_val
            // The top 'm' candidates must be <= new_val
            int pos = n - m;
            i64 sum_top_m = suffix[pos];
            
            // Calculate required votes
            i64 required;
            if (B[pos] <= new_val) {
                required = (m * new_val) - sum_top_m;
            } else {
                // Need to push more candidates down
                required = (m * new_val) - (sum_top_m - B[pos] + new_val);
            }
            
            if (required <= (k - mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}