#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2], cnt[MAXN][2];

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    
    // Initialize base cases
    f[1][0] = 0;
    cnt[1][0] = 0;
    f[1][1] = a[1];
    cnt[1][1] = 1;
    
    for (ll i = 2; i <= n; i++) {
        // Option 1: Not take current element
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        cnt[i][0] = (f[i-1][0] > f[i-1][1]) ? cnt[i-1][0] : cnt[i-1][1];
        
        // Option 2: Take current element
        ll val1 = (cnt[i-1][0] % 2 == 0) ? a[i] : a[i] * 2;
        ll val2 = (cnt[i-1][1] % 2 == 0) ? a[i] : a[i] * 2;
        
        ll take_option1 = f[i-1][0] + val1;
        ll take_option2 = f[i-1][1] + val2;
        
        if (take_option1 > take_option2) {
            f[i][1] = take_option1;
            cnt[i][1] = cnt[i-1][0] + 1;
        } else {
            f[i][1] = take_option2;
            cnt[i][1] = cnt[i-1][1] + 1;
        }
    }
    
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}