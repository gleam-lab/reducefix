#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 10;

ll a[MAXN], sum[MAXN], cnt[MAXN];

int main() {
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    
    // Initialize array a with twice its size to handle circular nature
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }

    // Compute prefix sums modulo m
    for (ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % m;
    }

    // Count occurrences of each prefix sum
    unordered_map<ll, int> count;
    count[sum[0]]++;

    // Iterate through the second half of the array to find valid pairs
    for (ll i = n + 1; i <= 2 * n; i++) {
        ans += count[(sum[i] - sum[i - n] + m) % m]; // Ensure non-negative index
        count[sum[i]]++;
    }

    printf("%lld\n", ans);
    return 0;
}