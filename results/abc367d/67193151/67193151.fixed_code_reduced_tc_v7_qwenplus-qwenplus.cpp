#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5; // Slightly larger to avoid overflow

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(N), prefix_sum(N);
    map<long long, int> freq;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i]; // Duplicate array for circular handling
    }

    long long result = 0;
    freq[0] = 1; // For subarrays starting from index 0

    for (int i = 1; i < 2 * n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
        long long mod = prefix_sum[i] % m;

        // Count how many times this mod has occurred before
        result += freq[mod];

        // If we're within the original array length, update frequency
        if (i < n) {
            freq[mod]++;
        } else {
            // Remove contribution of the element that's now out of window
            long long removed_mod = prefix_sum[i - n] % m;
            freq[removed_mod]--;
        }
    }

    cout << result << endl;
    return 0;
}