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

    // Initialize base case
    f[1][0] = 0;
    f[1][1] = a[1];
    cnt[1][0] = 0;
    cnt[1][1] = 1;

    for (ll i = 2; i <= n; i++) {
        // Calculate the maximum value without taking the current number twice
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);

        // Calculate the maximum value with taking the current number once or twice
        f[i][1] = max(f[i - 1][0] + a[i], f[i - 1][1] + a[i]);

        // Update the count of how many times we have taken the number up to this point
        if (f[i - 1][0] > f[i - 1][1]) {
            cnt[i][0] = cnt[i - 1][0];
            cnt[i][1] = cnt[i - 1][1] + 1;
        } else {
            cnt[i][0] = cnt[i - 1][0] + 1;
            cnt[i][1] = cnt[i - 1][1];
        }
    }

    // Output the maximum value we can get
    printf("%lld\n", max(f[n][0], f[n][1]));

    return 0;
}