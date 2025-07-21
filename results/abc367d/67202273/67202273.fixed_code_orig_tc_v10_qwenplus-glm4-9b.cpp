#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN], cnt[MAXN];
int main(){
    ll n, m, ans = 0;
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        a[i + n] = a[i];
    }
    for(ll i = 1; i <= 2 * n; ++i){
        if(i <= n) cnt[sum[i - 1]]++;
        sum[i] = (sum[i - 1] + a[i]) % m;
        if(i <= n) cnt[sum[i]]++;
    }
    for(ll i = n + 1; i <= 2 * n; ++i){
        ans += cnt[sum[i - n]];
        cnt[sum[i - n]]--;
    }
    cout << ans;
    return 0;
}