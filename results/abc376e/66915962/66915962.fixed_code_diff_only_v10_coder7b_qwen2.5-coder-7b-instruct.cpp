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
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        // Sort indices based on A values
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });
        
        // Calculate prefix sums of B values
        vector<ll> prefix_b(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix_b[i + 1] = prefix_b[i] + b[idx[i]];
        }
        
        ll ans = LLONG_MAX;
        for (int i = 0; i <= n - k; ++i) {
            ll max_a = a[idx[i + k - 1]];
            ll sum_b = prefix_b[i + k] - prefix_b[i];
            ans = min(ans, max_a * sum_b);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}