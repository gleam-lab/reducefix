#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN], cnt[MAXN];

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];  // Extend array to simulate circular behavior
    }

    // Calculate prefix sums for the array
    for(ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % m;  // Use sum[i-1] to handle circular nature of arr
    }

    // Initialize count array and answer
    for(ll i = 0; i < m; i++) cnt[i] = 0;
    ll ans = 0;

    // Calculate the number of valid patches for each position
    for(ll i = n + 1; i <= 2 * n; i++) {
        cnt[sum[i - n]]++;  // Increment count of the prefix sum that is n positions before
        ans += cnt[sum[i]];  // Add to answer the number of valid patches ending here
        cnt[sum[i]]++;  // Increment the current prefix sum count
    }

    printf("%lld", ans);  // Output the answer
    return 0;
}