#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;

ll a[MAXN];
ll f[MAXN][2];      // f[i][0/1]: max sum up to i-th element, ending with even/odd count
ll cnt[MAXN][2];    // cnt[i][0/1]: number of elements used in the optimal selection for f[i][0/1]

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    // Initialize base case
    f[0][0] = 0;    // Even count (0 elements)
    f[0][1] = -INF; // Odd count (impossible at step 0)
    cnt[0][0] = 0;  // 0 elements selected
    cnt[0][1] = 1;  // Impossible state but tracked

    for(ll i=1;i<=n;i++){
        // Option: not take current element
        f[i][0] = f[i-1][0];
        cnt[i][0] = cnt[i-1][0];
        f[i][1] = f[i-1][1];
        cnt[i][1] = cnt[i-1][1];

        // Try to take current element from previous even state
        ll val_even = a[i];
        ll new_cnt_even = cnt[i-1][0] + 1;
        if (new_cnt_even % 2 == 0) val_even = a[i] * 2;
        if (f[i-1][0] + val_even > f[i][1]){
            f[i][1] = f[i-1][0] + val_even;
            cnt[i][1] = new_cnt_even;
        }

        // Try to take current element from previous odd state
        ll val_odd = a[i];
        ll new_cnt_odd = cnt[i-1][1] + 1;
        if (new_cnt_odd % 2 == 0) val_odd = a[i] * 2;
        if (f[i-1][1] + val_odd > f[i][1]){
            f[i][1] = f[i-1][1] + val_odd;
            cnt[i][1] = new_cnt_odd;
        }

        // Also consider taking current element and starting fresh as odd
        if (a[i] > f[i][1]){
            f[i][1] = a[i];
            cnt[i][1] = 1;
        }
    }

    printf("%lld\n",max(f[n][0],f[n][1]));
    return 0;
}