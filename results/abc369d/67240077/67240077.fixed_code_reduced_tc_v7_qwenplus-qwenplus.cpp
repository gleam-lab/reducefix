#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN],f[MAXN][2];
ll cnt_even[MAXN], cnt_odd[MAXN];

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    
    // Initialize
    f[0][0] = 0; // even count, value
    f[0][1] = 0; // odd count, value
    cnt_even[0] = 0; // number of elements taken in even count case
    cnt_odd[0] = 0;  // number of elements taken in odd count case
    
    for(ll i=1;i<=n;i++){
        ll val_even_prev = f[i-1][0];
        ll val_odd_prev = f[i-1][1];
        
        // Case 1: do not take current element
        if(val_even_prev > val_odd_prev){
            f[i][0] = val_even_prev;
            cnt_even[i] = cnt_even[i-1];
        } else {
            f[i][0] = val_odd_prev;
            cnt_even[i] = cnt_odd[i-1];
        }
        
        // Case 2: take current element
        ll take_even, take_odd;
        if(cnt_even[i-1] % 2 == 0)
            take_even = val_even_prev + a[i];
        else
            take_even = val_even_prev + 2*a[i];
            
        if(cnt_odd[i-1] % 2 == 0)
            take_odd = val_odd_prev + a[i];
        else
            take_odd = val_odd_prev + 2*a[i];
            
        if(take_even > take_odd){
            f[i][1] = take_even;
            cnt_odd[i] = cnt_even[i-1] + 1;
        } else {
            f[i][1] = take_odd;
            cnt_odd[i] = cnt_odd[i-1] + 1;
        }
    }
    
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}