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
    
    // Calculate prefix sums modulo m
    sum[0] = 0;
    for (ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % m;
        if (sum[i] < 0) sum[i] += m; // Ensure non-negative modulo
    }
    
    ll ans = 0;
    cnt.clear();
    
    // Initialize frequency of prefix sums for first n elements
    for (ll i = 0; i < n; i++) {
        cnt[sum[i]]++;
    }
    
    // Sliding window: for each starting position in the second half
    for (ll i = n; i <= 2 * n; i++) {
        // Remove the prefix that's going out of range
        cnt[sum[i - n]]--;
        
        // Count how many previous prefixes give a subarray divisible by m
        // We want (sum[i] - sum[j]) % m == 0 => sum[j] % m == sum[i] % m
        ans += cnt[sum[i]];
        
        // Add current prefix to the map if we're still within valid range
        if (i < 2 * n) {
            cnt[sum[i]]++;
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}