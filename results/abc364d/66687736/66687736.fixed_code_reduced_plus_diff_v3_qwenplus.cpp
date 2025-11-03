#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vll vector<ll>

int main(){
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i,n) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    while(q--){
        ll b, k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = -1, right = 2e9;
        while(right - left > 1){
            ll mid = (left + right) / 2;
            
            // Count points in [b-mid, b+mid]
            ll cnt = upper_bound(a.begin(), a.end(), b + mid) - lower_bound(a.begin(), a.end(), b - mid);
            
            if(cnt < k){
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << endl;
    }
}