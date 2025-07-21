#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN],sum[MAXN],cnt[MAXN];
ll ans = 0;

int main(){
    ll n, m, total = 0;
    scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i+n] = a[i];  // Replicate the first n elements for the second half
        total = (total + a[i]) % m;
        sum[i+1] = total;
        cnt[sum[i]]++;  // Increment the count of the current prefix sum
    }

    // Corrected loop for counting the valid subsequences in the second half
    for (ll i = n+1; i <= 2*n; i++) {
        total = (total - a[i-n] + m) % m;  // Subtract the old prefix sum and add modulo m
        sum[i+1] = total;
        ans += cnt[sum[i]];  // Add the count of the current prefix sum to the answer
        cnt[sum[i]]++;  // Increment the count of the current prefix sum
    }

    printf("%lld\n", ans);
    return 0;
}