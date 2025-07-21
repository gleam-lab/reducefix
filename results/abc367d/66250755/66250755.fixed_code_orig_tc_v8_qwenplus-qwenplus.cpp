#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
const int MAXM = 1000005;

int n, m;
long long a[MAXN * 2], prefix_mod[MAXN * 2];
map<long long, long long> freq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i]; // duplicate the array for circular handling
    }

    // Compute prefix sums modulo m
    for (int i = 1; i <= 2 * n; ++i) {
        prefix_mod[i] = (prefix_mod[i - 1] + a[i]) % m;
    }

    long long result = 0;
    freq[0] = 1; // Initialize with mod 0 at position 0

    for (int i = 1; i <= 2 * n; ++i) {
        // Only consider the first n elements as end of subarrays
        if (i > n) {
            // Remove count from i - n positions ago
            freq[prefix_mod[i - n]]--;
        }
        // Add current prefix mod to result
        result += freq[prefix_mod[i]];
        // Increment frequency of current prefix mod
        freq[prefix_mod[i]]++;
    }

    cout << result << endl;
    return 0;
}