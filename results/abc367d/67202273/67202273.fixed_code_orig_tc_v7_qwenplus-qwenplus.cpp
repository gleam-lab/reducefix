#include<bits/stdc++.h>
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
        a[i + n] = a[i];  // Duplicate array to handle circular property
    }

    // Compute prefix sums modulo m
    prefix_sum[0] = 0;
    for (ll i = 1; i <= 2 * n; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[i]) % m;
    }

    ll ans = 0;
    cnt[0] = 1;  // Initialize with sum 0 before starting

    for (ll i = 1; i <= 2 * n; ++i) {
        // Only consider the first n-length window in the second half
        if (i > n) {
            ans += cnt[prefix_sum[i]];
        }
        if (i < n) {
            cnt[prefix_sum[i]]++;
        } else {
            // When we reach the end of the first full window, don't increment further
            if (i != n)
                cnt[prefix_sum[i]]++;
        }
    }

    printf("%lld\n", ans);
    return 0;
}