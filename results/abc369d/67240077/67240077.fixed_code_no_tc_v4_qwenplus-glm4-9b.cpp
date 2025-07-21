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
    f[0][0] = 0; // Initialize the first element
    cnt[0][0] = 0; // Initialize the count of even and odd times
    cnt[0][1] = 0;
    for (ll i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        cnt[i][0] = cnt[i - 1][0]; // Carry forward the even count
        cnt[i][1] = cnt[i - 1][1]; // Carry forward the odd count
        
        ll num1 = a[i];
        ll num2 = a[i] * 2;
        if (cnt[i - 1][0] % 2 == 0) {
            f[i][1] = max(f[i - 1][0] + num1, f[i - 1][1] + num2);
            cnt[i][1] = cnt[i - 1][0] + 1;
        } else {
            f[i][1] = max(f[i - 1][0] + num2, f[i - 1][1] + num1);
            cnt[i][1] = cnt[i - 1][0];
        }
        
        // Update the count for even and odd
        if (cnt[i][1] % 2 == 0) {
            cnt[i][0]++;
        } else {
            cnt[i][1]++;
        }
    }
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}