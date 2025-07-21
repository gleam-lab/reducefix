#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2]; // f[i][0] = not take i, f[i][1] = take i

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    
    f[0][0] = 0;        // base case: 0 elements taken
    f[0][1] = -INF;     // cannot take 0-th element (doesn't exist)
    
    for(ll i=1;i<=n;i++){
        // Option 1: don't take current element
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        
        // Option 2: take current element
        // The value depends on whether previous count was even or odd
        ll val_if_prev_not_taken = a[i]; // since count was 0 (even)
        ll val_if_prev_taken = (f[i-1][1] % 2 == 0) ? a[i]*2 : a[i];
        
        f[i][1] = max(f[i-1][0] + val_if_prev_not_taken, 
                     f[i-1][1] + val_if_prev_taken);
    }
    
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}