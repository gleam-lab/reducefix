#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    rep(qi, Q){
        ll b; int k;
        cin >> b >> k;
        
        // Binary search on the answer (distance)
        ll left = -1, right = 2e9 + 10;
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