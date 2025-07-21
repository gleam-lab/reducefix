#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,m,k,sum,cnt,a[N],b[N],c[N];

// Function to calculate the minimum additional votes needed for candidate i
bool canWin(ll x, ll y){
    // Find the position where the candidate would be among the top m candidates after adding x votes
    auto pos = lower_bound(b+1, b+1+n, x+y+1) - b;
    if(pos < n-m) return false; // If candidate is not among the top m, return false
    // Check if even if all remaining votes go to this candidate, he can still win
    return (x+y+1)*(pos-n+m) > k - y;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i){
        cin >> a[i]; 
        k -= a[i]; 
        b[i] = a[i];
    }
    sort(b+1, b+n+1); 
    for(int i=1; i<=n; ++i){
        c[i] = c[i-1] + b[i];
    }
    
    for(int i=1; i<=n; ++i){
        ll l = 0, r = k + 1;
        while(l < r){
            ll mid = (l + r) / 2;
            if(canWin(a[i], mid)){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(l <= k)
            cout << l << " ";
        else
            cout << "-1 ";
    }
    return 0;
}