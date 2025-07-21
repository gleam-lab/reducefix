#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 400005;
const int MAXM = 1 << 20; // Next power of 2 greater than or equal to m

int n, m;
ll a[MAXN], prefix[MAXN];
map<ll, ll> freq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i]; // Duplicate array for circular handling
    }

    // Compute prefix sums modulo m
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }

    ll result = 0;
    freq[0] = 1; // Initialize with 0 to handle cases where prefix[i] == 0

    // We process the first n elements as part of the sliding window
    for (int i = 1; i <= n; ++i) {
        // Remove contribution of element i-n from frequency map if needed
        if (i > n) {
            --freq[prefix[i - n]];
        }
        // Add current prefix and accumulate count
        result += freq[prefix[i]];
        ++freq[prefix[i]];
    }

    cout << result << "\n";
    return 0;
}