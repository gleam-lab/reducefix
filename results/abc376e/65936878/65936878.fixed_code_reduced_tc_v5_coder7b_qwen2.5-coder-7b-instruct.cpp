#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        
        // Sort based on A values in descending order
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());
        
        // Calculate initial sum of smallest B values
        long long sum_b = accumulate(b.begin(), b.begin()+k, 0LL);
        
        // Initialize answer with the product of largest A and sum of smallest B
        long long ans = (long long)a[0] * sum_b;
        
        // Adjust the sum by removing the smallest B and adding the next one
        for(int i=1; i<k; ++i) {
            sum_b -= b[i-1];
            sum_b += b[k+i-1];
            ans = min(ans, (long long)a[i] * sum_b);
        }
        
        cout << ans << '\n';
    }
}