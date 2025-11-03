#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 10;

ll a[MAXN], sum[MAXN];
map<ll, ll> cnt;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }
    
    sum[0] = 0;
    cnt[0] = 1;  // Important: prefix sum 0 appears once initially
    
    ll ans = 0;
    for (ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i-1] + a[i]) % m;
        
        // For positions beyond the first n, start removing old counts
        if (i > n) {
            cnt[sum[i - n]]--;
        }
        
        // Only count valid subarrays ending at position i that start at position >= max(1, i-n+1)
        if (i >= 1) {
            ans += cnt[sum[i]];
        }
        
        // Add current prefix sum to counter if it's within the sliding window
        if (i < n) {
            cnt[sum[i]]++;
        }
    }
    
    printf("%lld", ans);
    return 0;
}