#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;

// We only need to track the previous state, so we can optimize space usage
ll a[MAXN];
ll f_prev[2], cnt_prev[2];

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++){
        scanf("%lld",&a[i]);
    }

    f_prev[0] = 0;
    f_prev[1] = a[1];
    cnt_prev[0] = 0;
    cnt_prev[1] = 1;

    for(ll i=2; i<=n; i++){
        // Current values
        ll take_even, take_odd;

        // If we don't take current element (even count)
        if(f_prev[0] > f_prev[1]) {
            f_prev[0] = f_prev[0];
            cnt_prev[0] = cnt_prev[0];
        } else {
            cnt_prev[0] = cnt_prev[1];
            f_prev[0] = f_prev[1];
        }

        // If we take current element after even count
        ll cnt_even = cnt_prev[0] + 1;
        ll val_even = (cnt_even % 2 == 0) ? a[i] * 2 : a[i];

        // If we take current element after odd count
        ll cnt_odd = cnt_prev[1] + 1;
        ll val_odd = (cnt_odd % 2 == 0) ? a[i] * 2 : a[i];

        // Compute max value for taking current element
        if(f_prev[0] + val_even > f_prev[1] + val_odd){
            f_prev[1] = f_prev[0] + val_even;
            cnt_prev[1] = cnt_even;
        } else {
            f_prev[1] = f_prev[1] + val_odd;
            cnt_prev[1] = cnt_odd;
        }
    }

    printf("%lld", max(f_prev[0], f_prev[1]));
    return 0;
}