#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 4e5 + 10;

ll a[MAXN], sum[MAXN];
map<ll, ll> cnt;

int main() {
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }

    // Compute prefix sums modulo m
    sum[0] = 0;
    for (ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % m;
        if (i <= n) {
            cnt[sum[i]]++;
        }
    }

    // Sliding window to count valid subarrays
    cnt[sum[0]]++;  // To include subarrays starting at index 1
    for (ll i = 1; i <= n; i++) {
        // Remove the element that slides out of the window
        cnt[sum[i - 1]]--;

        // The number of valid subarrays ending at position i+n-1
        ans += cnt[sum[i + n - 1]];

        // Add current prefix to map
        cnt[sum[i + n - 1]]++;
    }

    printf("%lld\n", ans);
    return 0;
}