#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    
    vector<ll> x(n+2), p(n+2);  // Using 1-based indexing
    
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    
    // Build prefix sum
    vector<ll> sum(n+2, 0);
    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        
        // Find first position where x[i] >= L
        int l = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.data();
        
        // Find first position where x[i] > R
        int r = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.data();
        
        // All elements from l to r-1 are in the range [L, R]
        cout << sum[r-1] - sum[l-1] << "\n";
    }
    
    return 0;
}