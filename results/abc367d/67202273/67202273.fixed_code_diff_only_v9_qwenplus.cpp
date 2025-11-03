#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 10;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    vector<ll> a(2 * n + 1), sum(2 * n + 2);
    vector<ll> cnt(m, 0);
    
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }
    
    // Compute prefix sums modulo m
    for (ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i-1] + a[i]) % m;
        if (sum[i] < 0) sum[i] += m; // Ensure non-negative modulo
    }
    
    ll ans = 0;
    // Initialize frequency of prefixes in first window
    for (ll i = 0; i < n; i++) {
        cnt[sum[i]]++;
    }
    
    // Slide window from position n to 2*n-1
    for (ll i = n; i <= 2 * n; i++) {
        // Remove the prefix that's leaving the window
        cnt[sum[i - n]]--;
        // Count how many previous prefixes have same sum (meaning subarray sum divisible by m)
        ans += cnt[sum[i]];
        // Add current prefix to frequency map
        if (i < 2 * n) {  // Only add if we're not at the final sentinel
            cnt[sum[i]]++;
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}