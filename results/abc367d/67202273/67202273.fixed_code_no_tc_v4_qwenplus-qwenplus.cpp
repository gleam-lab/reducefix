#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e5 + 10;

ll a[MAXN], prefix_sum[MAXN];
map<ll, ll> count_map;

int main() {
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);

    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];  // Duplicate array for circular handling
    }

    // Compute prefix sums modulo m
    for (ll i = 1; i <= 2 * n; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[i]) % m;
    }

    // Initialize counts of prefix sums mod m for the first n elements
    for (ll i = 0; i <= n; ++i) {  // Include prefix_sum[0] (which is 0)
        count_map[prefix_sum[i]]++;
    }

    // Sliding window to maintain valid subarrays starting from each position
    for (ll i = n + 1; i <= 2 * n; ++i) {
        // Remove the element falling out of the window
        count_map[prefix_sum[i - n - 1]]--;

        // Count current valid subarrays ending at i with sum divisible by m
        ans += count_map[prefix_sum[i]];

        // Add current prefix sum to the map for future subarrays
        count_map[prefix_sum[i]]++;
    }

    printf("%lld\n", ans);
    return 0;
}