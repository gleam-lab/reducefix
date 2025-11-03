#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    // Sort the A points to enable binary search
    sort(a.begin(), a.end());
    
    rep(j, q) {
        ll b, k;
        cin >> b >> k;
        k--; // Convert to 0-indexed
        
        // Binary search on the distance
        ll left = -1;
        ll right = 2e9 + 10;
        
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from B
            ll left_bound = b - mid;
            ll right_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), left_bound);
            auto it2 = upper_bound(a.begin(), a.end(), right_bound);
            
            int count = it2 - it1;
            
            if (count <= k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << '\n';
    }
}