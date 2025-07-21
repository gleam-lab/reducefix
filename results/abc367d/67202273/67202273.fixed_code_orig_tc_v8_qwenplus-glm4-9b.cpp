#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 10;
ll a[MAXN], sum[MAXN], cnt[MAXN] = {0};  // Initialize cnt array with zeros

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);  // Read n and m

    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];  // Duplicate the array for circular behavior
    }

    sum[0] = 0;  // Initialize sum[0] to 0
    for (ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % m;  // Calculate prefix sums modulo m
        if (i <= n) {
            cnt[sum[i]]++;  // Increment count for the first n elements
        }
    }

    ll ans = 0;
    for (ll i = n + 1; i <= 2 * n; i++) {
        cnt[sum[i - n]]--;  // Decrement count for the element n steps back
        ans = ans + cnt[sum[i]];  // Add the count to the answer
        cnt[sum[i]]++;  // Increment count for the current element
    }

    printf("%lld", ans);  // Print the answer
    return 0;
}