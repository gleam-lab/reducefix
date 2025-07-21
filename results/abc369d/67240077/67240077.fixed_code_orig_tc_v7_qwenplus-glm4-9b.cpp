#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2], cnt[MAXN][2];
int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    f[0][0] = 0;  // Initial state
    f[0][1] = 0;
    cnt[0][0] = 0;
    cnt[0][1] = 0;
    for(ll i=1;i<=n;i++){
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        cnt[i][0] = cnt[i-1][0];  // Assuming both scenarios lead to the same count
        f[i][1] = max(f[i-1][0] + a[i], f[i-1][1] + a[i]);
        cnt[i][1] = max(cnt[i-1][0], cnt[i-1][1]) + 1;
    }
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}