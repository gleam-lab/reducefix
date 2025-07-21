#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e5 + 10;

ll a[MAXN], prefix_sum[MAXN];
map<ll, ll> cnt;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);

    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];  // Duplicate array for circular handling
    }

    // Compute prefix sums modulo m
    for (ll i = 1; i <= 2 * n; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[i]) % m;
    }

    ll ans = 0;
    cnt[prefix_sum[0]] = 1;  // Initialize with sum 0 to handle subarrays starting from index 0

    for (ll i = 1; i <= n; ++i) {
        // Only consider prefix sums within the current window of size n
        cnt[prefix_sum[i]]++;
    }

    for (ll i = n + 1; i <= 2 * n; ++i) {
        // Remove the prefix sum that is sliding out of the window
        cnt[prefix_sum[i - n]]--;

        // Add the number of valid previous prefix sums that form a subarray divisible by m
        ans += cnt[prefix_sum[i]];

        // Add current prefix sum to the map
        cnt[prefix_sum[i]]++;
    }

    printf("%lld\n", ans);
    return 0;
}