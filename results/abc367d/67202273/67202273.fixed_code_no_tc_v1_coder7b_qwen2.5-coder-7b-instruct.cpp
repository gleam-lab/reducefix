#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 10;

ll a[MAXN], sum[MAXN], cnt[MAXN];
int main() {
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }
    for (ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % m;
        if (i >= n + 1) ans += cnt[(sum[i] - sum[i - n] + m) % m]; // Corrected the index and condition
        cnt[sum[i]]++;
    }
    printf("%lld", ans);
    return 0;
}