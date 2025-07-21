#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 10;
ll a[MAXN], sum[MAXN], cnt[MAXN][m+1]; // Use a 2D array to avoid index out of bounds

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }

    ll current_sum = 0;
    for (ll i = 1; i <= 2 * n; i++) {
        current_sum = (current_sum + a[i]) % m;
        cnt[a[i]][(current_sum + m) % m]++; // Increment count for the prefix sum modulus m
    }

    ll ans = 0;
    for (ll i = 1; i <= 2 * n; i++) {
        ans = (ans + cnt[a[i]][current_sum]) % m; // Sum the counts for the current prefix sum modulus m
        cnt[a[i]][current_sum] = 0; // Reset count for the current prefix sum
    }

    printf("%lld\n", ans);

    return 0;
}