#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vll vector<ll>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vll a(n);
    rep(i,n) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    while(q--){
        ll b; int k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = -1, right = 200000000;
        while(right - left > 1){
            ll mid = (left + right) / 2;
            
            // Count points in [b-mid, b+mid]
            ll cnt = upper_bound(a.begin(), a.end(), b + mid) - 
                     lower_bound(a.begin(), a.end(), b - mid);
            
            if(cnt < k){
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << '\n';
    }
}