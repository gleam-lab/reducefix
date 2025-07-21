#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 10;

ll a[MAXN], prefix_sum[MAXN];
map<ll, ll> cnt;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    
    // Read array and duplicate it to handle circular nature
    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }

    // Compute prefix sums modulo m
    prefix_sum[0] = 0;
    for (ll i = 1; i <= 2 * n; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[i]) % m;
    }

    ll ans = 0;
    cnt[0] = n; // We can always pair with the initial sum of 0, which appears n times due to circularity

    for (ll i = 1; i <= 2 * n; ++i) {
        ans += cnt[prefix_sum[i]];
        if (i >= n) {
            // When window moves past n elements, stop incrementing older counts
            cnt[prefix_sum[i - n]]--;
        }
        if (i < 2 * n) {
            cnt[prefix_sum[i]]++;
        }
    }

    printf("%lld\n", ans);
    return 0;
}