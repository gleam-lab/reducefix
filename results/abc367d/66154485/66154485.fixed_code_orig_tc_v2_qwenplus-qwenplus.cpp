#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Extend array to simulate circular behavior
    vector<long long> prefixSum(2 * n + 1, 0);
    vector<int> freq(m, 0); // Frequency of prefix sum mod m

    long long ans = 0;
    long long currSum = 0;

    // Compute prefix sums
    for (int i = 0; i < 2 * n; ++i) {
        currSum += arr[i % n];
        int mod = ((currSum % m) + m) % m; // Ensure non-negative

        if (i < n) {
            // First pass: build frequency
            ans += freq[mod];
            freq[mod]++;
        } else {
            // Sliding window: subtract counts that are out of range
            ans += freq[mod];
            freq[mod]++;
            // Remove contribution of the element going out of window
            int out_mod = ((prefixSum[i - n] % m) + m) % m;
            freq[out_mod]--;
        }
        prefixSum[i + 1] = currSum;
    }

    cout << ans << '\n';
    return 0;
}