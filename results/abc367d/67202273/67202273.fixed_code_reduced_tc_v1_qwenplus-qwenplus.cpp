#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 400000 + 10; // Adjusted for safety and clarity

ll a[MAXN], sum[MAXN];
map<ll, ll> cnt;

int main() {
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    
    // Read array and duplicate it to handle circular prefix sums
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }

    // Compute prefix sums modulo m
    sum[0] = 0;
    for (ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % m;
    }

    // Initialize count of prefix sums in first window
    cnt.clear();
    for (ll i = 0; i <= n; i++) {
        cnt[sum[i]]++;
    }

    ans = 0;
    for (ll i = n + 1; i <= 2 * n; i++) {
        // Remove the element exiting the window
        cnt[sum[i - n - 1]]--;

        // Add number of valid subarrays ending at current position
        ans += cnt[sum[i]];

        // Add the current prefix sum to the map
        cnt[sum[i]]++;
    }

    printf("%lld\n", ans);
    return 0;
}