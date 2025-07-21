#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2], cnt[MAXN][2];
int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
    }
    // Initialize the first element
    f[1][0] = a[1];
    f[1][1] = a[1] * 2;
    cnt[1][0] = 1;
    cnt[1][1] = 1;

    for(ll i = 2; i <= n; i++){
        f[i][0] = max(f[i-1][0] + a[i], f[i-1][1]);
        f[i][1] = max(f[i-1][0] + a[i] * 2, f[i-1][1] + a[i]);

        // Update counts
        if (f[i-1][0] + a[i] * 2 >= f[i-1][1] + a[i]) {
            cnt[i][0] = cnt[i-1][0] + 1;
            cnt[i][1] = cnt[i-1][1];
        } else {
            cnt[i][0] = cnt[i-1][1];
            cnt[i][1] = cnt[i-1][0] + 1;
        }
    }

    // Output the maximum of the last two values
    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}