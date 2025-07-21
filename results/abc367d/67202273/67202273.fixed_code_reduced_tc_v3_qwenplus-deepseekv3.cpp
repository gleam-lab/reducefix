#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN], cnt[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, m, ans=0;
    cin >> n >> m;
    
    for(ll i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    
    sum[0] = 0;
    for(ll i=1; i<=2*n; i++) {
        sum[i] = (sum[i-1] + a[i]) % m;
    }
    
    memset(cnt, 0, sizeof(cnt));
    for(ll i=1; i<=n; i++) {
        cnt[sum[i]]++;
    }
    
    for(ll i=n+1; i<=2*n; i++) {
        cnt[sum[i-n]]--;
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    
    cout << ans << '\n';
    return 0;
}