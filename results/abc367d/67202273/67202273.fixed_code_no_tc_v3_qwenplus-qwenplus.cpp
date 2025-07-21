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
        a[i + n] = a[i];  // Duplicate the array to handle circular subarrays
    }

    // Precompute prefix sums modulo m
    for (ll i = 1; i <= 2 * n; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[i]) % m;
    }

    // Initialize count of prefix sums mod m for the first n elements
    for (ll i = 0; i <= n; ++i) {  // Include prefix_sum[0] = 0
        count_map[prefix_sum[i]]++;
    }

    // Sliding window over the circular array
    for (ll i = n + 1; i <= 2 * n; ++i) {
        // Remove the leftmost sum from the previous window
        count_map[prefix_sum[i - n - 1]]--;

        // Add the current prefix_sum to the answer
        ans += count_map[prefix_sum[i]];

        // Add current prefix_sum to the map for future comparisons
        count_map[prefix_sum[i]]++;
    }

    printf("%lld\n", ans);
    return 0;
}