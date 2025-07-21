#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 10;
ll a[MAXN], sum[MAXN], cnt[MAXN];
int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i]; // Extend the array to handle wrap-around
    }
    for (ll i = 1; i <= 2 * n; i++) {
        sum[i + 1] = (sum[i] + a[i]) % m; // Update the cumulative sum modulo m
        if (i < n) cnt[sum[i]]++; // Increment count for the first half of the circumference
    }
    for (ll i = n + 1; i <= 2 * n; i++) { // Start from n+1 to avoid double counting
        cnt[sum[i - n]]--; // Decrement count for the previous segment
        ans += cnt[sum[i]]; // Add current count to ans
    }
    printf("%lld", ans);
    return 0;
}