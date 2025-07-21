#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e5 + 10;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    vector<ll> a(2 * n + 2);
    vector<ll> sum(2 * n + 2, 0);
    unordered_map<ll, ll> cnt;

    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }

    ll ans = 0;
    cnt[0] = 1;

    for (ll i = 1; i <= 2 * n; ++i) {
        sum[i] = (sum[i - 1] + a[i]) % m;
        if (i > n) {
            ll prev_sum = sum[i - n];
            cnt[prev_sum]--;
        }
        ans += cnt[sum[i]];
        if (i <= n) {
            cnt[sum[i]]++;
        }
    }

    printf("%lld\n", ans);
    return 0;
}