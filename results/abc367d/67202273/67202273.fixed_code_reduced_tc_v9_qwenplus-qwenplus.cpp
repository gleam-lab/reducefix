#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e5 + 10;

ll a[MAXN], sum[MAXN];
map<ll, ll> cnt;

int main() {
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);

    // Read input circular array (double length for easier modulo handling)
    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }

    // Compute prefix sums modulo m
    sum[0] = 0;
    for (ll i = 1; i <= 2 * n; ++i) {
        sum[i] = (sum[i - 1] + a[i]) % m;
    }

    // Reset count map and initialize with sum[0]
    cnt.clear();
    cnt[sum[0]] = 1;

    // Sliding window over the circular array
    for (ll i = 1; i <= 2 * n; ++i) {
        // If we've passed the first n elements, remove the element that slides out
        if (i > n) {
            cnt[sum[i - n]]--;
            if (cnt[sum[i - n]] == 0) {
                cnt.erase(sum[i - n]);
            }
        }
        // Count subarrays ending at i with sum divisible by m
        ans += cnt[sum[i]];
        // Add current prefix sum to the map
        cnt[sum[i]]++;
    }

    printf("%lld\n", ans);
    return 0;
}