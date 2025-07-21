#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN],f[MAXN][2];
ll cnt_even[MAXN][2], cnt_odd[MAXN][2];

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    
    // Initialize base cases
    f[0][0] = 0; // max value not using i-th element
    f[0][1] = 0; // max value using i-th element
    cnt_even[0][0] = 0; // count of elements in sequence ending with even count
    cnt_odd[0][1] = 1;  // count of elements in sequence ending with odd count

    for(ll i=1;i<=n;i++){
        // Case 0: don't use a[i]
        if(f[i-1][0] > f[i-1][1]){
            f[i][0] = f[i-1][0];
            cnt_even[i][0] = cnt_even[i-1][0];
            cnt_odd[i][0] = cnt_odd[i-1][0];
        } else {
            f[i][0] = f[i-1][1];
            cnt_even[i][0] = cnt_even[i-1][1];
            cnt_odd[i][0] = cnt_odd[i-1][1];
        }

        // Case 1: use a[i]
        ll val1, val2;
        ll new_cnt_even = cnt_even[i-1][0] + 1;
        ll new_cnt_odd = cnt_odd[i-1][1] + 1;

        if(new_cnt_even % 2 == 0)
            val1 = f[i-1][0] + a[i] * 2;
        else
            val1 = f[i-1][0] + a[i];

        if(new_cnt_odd % 2 == 0)
            val2 = f[i-1][1] + a[i] * 2;
        else
            val2 = f[i-1][1] + a[i];

        if(val1 > val2){
            f[i][1] = val1;
            cnt_even[i][1] = (new_cnt_even % 2 == 0) ? new_cnt_even : cnt_even[i-1][0];
            cnt_odd[i][1] = (new_cnt_even % 2 == 1) ? new_cnt_even : cnt_odd[i-1][0];
        } else {
            f[i][1] = val2;
            cnt_even[i][1] = (new_cnt_odd % 2 == 0) ? new_cnt_odd : cnt_even[i-1][1];
            cnt_odd[i][1] = (new_cnt_odd % 2 == 1) ? new_cnt_odd : cnt_odd[i-1][1];
        }
    }
    printf("%lld",max(f[n][0],f[n][1]));
    return 0;
}