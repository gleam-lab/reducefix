#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN], cnt[MAXN+1]; // cnt array with range 0 to m

int main() {
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i]; // Extend array once for pattern repetition
    }
    for(ll i = 1; i <= n; i++) {
        sum[i] = (a[i] % m); // Update sum directly with modulo
        cnt[sum[i]]++; // Use immediate value
    }
    for(ll i = n + 1; i <= 2 * n; i++) {
        cnt[a[i] % m]--; // Update count of the current value
        ans += cnt[sum[i - n]]; // Add the count of the sum of the previous value
        cnt[a[i] % m]++; // Increment count again
        sum[i] = (sum[i - n] + a[i] % m) % m; // Update sum with modulo
    }
    printf("%lld", ans);
    return 0;
}