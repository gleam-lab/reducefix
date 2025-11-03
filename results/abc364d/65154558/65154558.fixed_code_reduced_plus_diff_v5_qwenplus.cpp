#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search
    sort(a.begin(), a.end());
    
    for (int i = 0; i < q; i++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = 0, right = 2e8;
        ll ans = right;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Find the range of A points within distance 'mid' from point b
            ll lower_bound = b - mid;
            ll upper_bound = b + mid;
            
            // Count how many points in A are in [lower_bound, upper_bound]
            auto it1 = lower_bound(a.begin(), a.end(), lower_bound);
            auto it2 = upper_bound(a.begin(), a.end(), upper_bound);
            int count = it2 - it1;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}