#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e5 + 10;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);

    vector<ll> a(2 * n + 2, 0);
    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }

    // Prefix sum modulo m
    vector<ll> sum(2 * n + 2, 0);
    for (ll i = 1; i <= 2 * n; ++i) {
        sum[i] = (sum[i - 1] + a[i]) % m;
    }

    // Use a map to count occurrences of each prefix sum mod m
    vector<ll> cnt(m, 0);
    ll ans = 0;

    // Initialize the map with the first n prefix sums
    for (ll i = 0; i <= n; ++i) {
        cnt[sum[i]]++;
    }

    // Sliding window: remove sum[i-n] and add sum[i]
    for (ll i = n + 1; i <= 2 * n; ++i) {
        cnt[sum[i - n]]--;
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }

    printf("%lld\n", ans);
    return 0;
}