#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN], cnt[MAXN];

int main() {
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i]; // Create circular array
    }
    
    sum[0] = 0;
    for(ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i-1] + a[i]) % m;
    }
    
    // Initialize cnt for the first n elements
    cnt[0] = 1; // sum[0] = 0
    for(ll i = 1; i <= n; i++) {
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    
    // Now handle the circular part by sliding the window
    for(ll i = n + 1; i <= 2 * n; i++) {
        cnt[sum[i - n]]--; // Remove the leftmost element of previous window
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    
    printf("%lld", ans);
    return 0;
}