#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2], cnt[MAXN][2];

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    // Initialize base cases
    f[1][0] = a[1];
    f[1][1] = a[1];
    cnt[1][0] = 1;
    cnt[1][1] = 1;

    for (ll i = 2; i <= n; i++) {
        // Max of previous results from both strategies
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);

        // Count continuation of the best previous strategy
        cnt[i][0] = (f[i - 1][0] == f[i - 1][1]) ? cnt[i - 1][0] : cnt[i - 1][1];

        // Calculate the new values if continuing with the best previous strategy
        ll num1 = cnt[i][0] % 2 == 0 ? a[i] * 2 : a[i];

        // Calculate new values for the other strategy
        f[i][1] = max(f[i - 1][0] + num1, f[i - 1][1]);
        cnt[i][1] = cnt[i - 1][0] + (f[i - 1][0] + num1 > f[i - 1][1] ? 1 : 0);
    }

    // The result is the maximum of the two strategies at the end
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}