#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> prefix_sums(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> prefix_sums[i];
        prefix_sums[i] %= m;
        prefix_sums[i + n] = prefix_sums[i];
    }

    for (int i = 1; i <= 2 * n; ++i) {
        prefix_sums[i] = (prefix_sums[i] + prefix_sums[i - 1]) % m;
    }

    map<int, int> count;
    count[0] = 1; // For subarrays starting at index 0
    long long result = 0;

    for (int i = 1; i <= 2 * n; ++i) {
        // Only start counting from the second half (when i > n)
        if (i > n) {
            result += count[prefix_sums[i]]++;
            // We need to remove the prefix that's now out of the sliding window
            count[prefix_sums[i - n]]--;
        } else {
            count[prefix_sums[i]]++;
        }
    }

    cout << result;
    return 0;
}