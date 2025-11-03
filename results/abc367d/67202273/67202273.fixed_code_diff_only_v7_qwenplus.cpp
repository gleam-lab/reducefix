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
    
    // Slide window and count valid subarrays ending at each position
    for (ll i = n; i <= 2 * n; i++) {
        // Remove the prefix that's leaving the window
        cnt[sum[i - n]]--;
        // Count how many previous prefixes give sum divisible by m
        ans += cnt[sum[i]];
        // Add current prefix to frequency table
        cnt[sum[i]]++;
    }
    
    printf("%lld\n", ans);
    return 0;
}