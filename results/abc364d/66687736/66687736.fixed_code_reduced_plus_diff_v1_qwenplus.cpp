#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    rep(i, q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = -1, right = 2e9;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from B
            ll low_bound = b - mid;
            ll high_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low_bound);
            auto it2 = upper_bound(a.begin(), a.end(), high_bound);
            int count = it2 - it1;
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        cout << right << endl;
    }
}