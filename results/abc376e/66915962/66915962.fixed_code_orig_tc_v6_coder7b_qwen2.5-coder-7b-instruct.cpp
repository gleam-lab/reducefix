#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];

        // Sort indices based on A[i]
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j){ return a[i] < a[j]; });

        // Initialize prefix sum of B
        vector<ll> pref_sum(n + 1);
        for(int i = 0; i < n; ++i) pref_sum[i+1] = pref_sum[i] + b[idx[i]];

        // Find the minimum product
        ll ans = LINF;
        for(int i = 0; i <= n - k; ++i) {
            ll max_a = a[idx[i+k-1]];
            ll sum_b = pref_sum[i+k] - pref_sum[i];
            ans = min(ans, max_a * sum_b);
        }

        cout << ans << '\n';
    }

    return 0;
}