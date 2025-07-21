#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

const int MAXN = 2 * 1e5 + 5;
int A[MAXN], B[MAXN];
int dp[MAXN][2];

void solve() {
    int n, k; cin >> n >> k;
    
    // Read input
    for(int i = 0; i < n; ++i) cin >> A[i] >> B[i];
    
    // Sort the arrays
    sort(A, A + n);
    sort(B, B + n);
    
    // Initialize DP table
    memset(dp, 0, sizeof(dp));
    
    // Iterate through all possible sizes of subsets
    for(int sz = 1; sz <= k; ++sz) {
        int maxA = 0, sumB = 0;
        for(int i = 0; i < sz; ++i) {
            maxA = max(maxA, A[n-sz+i]);
            sumB += B[n-sz+i];
        }
        
        dp[sz][0] = maxA * sumB;
        
        for(int i = sz; i < n; ++i) {
            maxA = max(maxA, A[n-i-1]);
            sumB -= B[n-i-1];
            sumB += B[i];
            dp[sz][1] = max(dp[sz][1], maxA * sumB);
        }
    }
    
    cout << dp[k][1] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}