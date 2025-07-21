#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e5 + 10;

ll a[MAXN], prefix_sum[MAXN];
map<ll, ll> cnt;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);

    // Read the array and duplicate it to handle circular nature
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }

    // Compute prefix sums modulo m
    prefix_sum[0] = 0;
    for (ll i = 1; i <= 2 * n; i++) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[i]) % m;
    }

    ll ans = 0;
    cnt[0] = 0; // Initialize count of prefix sum 0

    // We'll use a sliding window of size n
    for (ll i = 1; i <= 2 * n; i++) {
        ll current = prefix_sum[i];

        // If we're past the first window, start counting valid subarrays
        if (i > n) {
            cnt[prefix_sum[i - n]]--; // Remove the element that slides out of the window
        }

        ans += cnt[current]; // Count previous occurrences of current prefix sum
        cnt[current]++; // Add current prefix sum to the map

        // After the first n elements, maintain a proper sliding window
        if (i >= n) {
            cnt[prefix_sum[i - n]]--; // Ensure we don't count the removed element twice
        }
    }

    printf("%lld\n", ans);
    return 0;
}