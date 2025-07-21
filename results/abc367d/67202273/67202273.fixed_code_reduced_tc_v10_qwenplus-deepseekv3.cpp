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
        a[i + n] = a[i];  // Create circular array
    }
    
    // Initialize cnt[0] to 1 because sum[0] = 0 (empty prefix)
    cnt[0] = 1;
    
    // Compute prefix sums modulo m
    for(ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % m;
        if(i <= n) {
            cnt[sum[i]]++;
        }
    }
    
    // Sliding window to count valid subarrays
    for(ll i = n + 1; i <= 2 * n; i++) {
        // Remove the leftmost element's contribution from the window
        cnt[sum[i - n]]--;
        // Add counts of current remainder
        ans += cnt[sum[i]];
        // Add current remainder to the window
        cnt[sum[i]]++;
    }
    
    printf("%lld\n", ans);
    return 0;
}