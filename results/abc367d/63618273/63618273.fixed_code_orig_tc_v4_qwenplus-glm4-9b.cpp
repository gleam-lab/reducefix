#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n+10);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> prefixSum(n+10);
    for(int i=1; i<=n; i++) {
        prefixSum[i] = (prefixSum[i-1] + a[i]) % mod;
    }
    ll ans = 0;
    // Count pairs (j, k) such that j < k and (prefixSum[j] + prefixSum[k]) % M == 0
    for (int i = 0; i < n; i++) {
        // Calculate dividend for each prefixSum[i]
        ll dividend = (ll)prefixSum[i] * (n - i) % mod;
        // Check how many time we can use (prefixSum[i] - t) % M for the pairs
        for (ll t = 0; t < M; t++) {
            if (dividend % mod == t) {
                ans = (ans + (n - i) - 1) % mod; // Subtract 1 as we include both ends
            }
        }
    }
    cout << ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}