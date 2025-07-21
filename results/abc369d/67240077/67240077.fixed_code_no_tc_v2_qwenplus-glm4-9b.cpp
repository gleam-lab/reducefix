#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
ll a[MAXN], f[MAXN][2], cnt[MAXN][2];

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (ll i = 1; i <= n; i++) {
        // Calculate the maximum value of f[i][0] and f[i][1] based on the previous values
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        // Count the number of even and odd values among the previous ones
        cnt[i][0] = cnt[i - 1][0] + (f[i - 1][0] == f[i - 1][1] ? 1 : 0);
        cnt[i][1] = cnt[i - 1][1] + (f[i - 1][0] <= f[i - 1][1] ? 1 : 0);

        ll cnt1 = cnt[i][0], cnt2 = cnt[i][1];
        ll num1 = cnt1 % 2 == 0 ? a[i] * 2 : a[i];
        ll num2 = cnt2 % 2 == 0 ? a[i] * 2 : a[i];

        // Update f[i][1] considering the number of even and odd values
        f[i][1] = max(f[i - 1][0] + num1, f[i - 1][1] + num2);

        // Update the count for the odd sequence if the updated f[i][1] is better
        if (f[i - 1][0] + num1 > f[i - 1][1] + num2) {
            cnt[i][1] = cnt1;
        } else {
            cnt[i][1] = cnt2;
        }
    }

    // Output the maximum of the final values of f[n][0] and f[n][1]
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}