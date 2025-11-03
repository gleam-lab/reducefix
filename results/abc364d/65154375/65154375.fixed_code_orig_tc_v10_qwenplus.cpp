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
        ll left = 0, right = 200000000;
        ll ans = right;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from point B
            ll left_bound = b - mid;
            ll right_bound = b + mid;
            
            // Find the first position >= left_bound
            auto it1 = lower_bound(a.begin(), a.end(), left_bound);
            // Find the first position > right_bound
            auto it2 = upper_bound(a.begin(), a.end(), right_bound);
            
            int count = it2 - it1;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}