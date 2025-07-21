#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 400010;

ll a[MAXN], prefix_mod[MAXN];
map<ll, ll> count_map;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);

    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }

    // Double the array to handle circular property
    for (ll i = 1; i <= n; ++i) {
        a[i + n] = a[i];
    }

    // Compute prefix sums mod m
    prefix_mod[0] = 0;
    for (ll i = 1; i <= 2 * n; ++i) {
        prefix_mod[i] = (prefix_mod[i - 1] + a[i]) % m;
    }

    ll result = 0;
    count_map[0] = 1; // Initialize with mod 0

    for (ll i = 1; i <= 2 * n; ++i) {
        // Only consider subarrays of length ≤ n
        if (i > n) {
            count_map[prefix_mod[i - n - 1]]--;
        }
        result += count_map[prefix_mod[i]];
        count_map[prefix_mod[i]]++;
    }

    printf("%lld\n", result);
    return 0;
}