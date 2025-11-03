#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(){
    int n,q; cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    
    while(q--){
        ll b, k; cin >> b >> k;
        k--; // 0-indexed
        
        // Binary search on the distance
        ll left = -1, right = 2e9 + 10;
        while(right - left > 1){
            ll mid = (left + right) / 2;
            
            // Count how many points are within distance 'mid' from b
            ll low_bound = b - mid;
            ll high_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low_bound);
            auto it2 = upper_bound(a.begin(), a.end(), high_bound);
            ll count = it2 - it1;
            
            if(count <= k){
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << endl;
    }
}