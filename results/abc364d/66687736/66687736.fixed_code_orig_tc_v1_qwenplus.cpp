#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>

int main(){
    int n,q;
    cin >> n >> q;
    vi a(n);
    rep(i,n){
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    rep(i,q){
        int b, k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll l = -1, r = 200000000;
        while(r - l > 1){
            ll m = (r + l) / 2;
            
            // Count how many points in A are within distance m from b
            // That is, count points in [b-m, b+m]
            auto left = lower_bound(a.begin(), a.end(), b - m);
            auto right = upper_bound(a.begin(), a.end(), b + m);
            int cnt = right - left;
            
            if(cnt < k){
                l = m;
            } else {
                r = m;
            }
        }
        
        cout << r << endl;
    }
}