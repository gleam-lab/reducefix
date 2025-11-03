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
    
    // Compute prefix sums modulo m
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
    
    // Sliding window over circular array
    for (ll i = n; i <= 2 * n; i++) {
        // Remove sum[i-n] as it's now out of the sliding window
        cnt[sum[i - n]]--;
        if (cnt[sum[i - n]] == 0) {
            cnt.erase(sum[i - n]);
        }
        
        // Count how many previous prefix sums equal current sum
        // This means subarray sum from that point to here is divisible by m
        ans += cnt[sum[i]];
        
        // Add current prefix sum to frequency map
        if (i < 2 * n) {  // Only add if not at final position
            cnt[sum[i]]++;
        }
    }
    
    printf("%lld", ans);
    return 0;
}