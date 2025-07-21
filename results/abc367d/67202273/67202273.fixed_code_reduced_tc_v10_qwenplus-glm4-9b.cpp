#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=400010; // 4e5 + 10
ll a[MAXN], sum[MAXN], cnt[MAXN];
int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i]; // Extend the array for another n elements
    }
    for (ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % m;
        if (i <= n) {
            cnt[sum[i]]++; // Count occurrences in the first half
        }
    }
    ll ans = 0;
    for (ll i = n + 1; i <= 2 * n; i++) {
        ans += cnt[sum[i - n]]; // Add occurrences from the second half
        cnt[sum[i - n]]--; // Update count for the second half
        cnt[sum[i]]++; // Update count for the next element in the second half
    }
    printf("%lld\n", ans);
    return 0;
}