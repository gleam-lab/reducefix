#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> prefix_sums(2 * n + 1);
    map<long long, int> count_map;
    int result = 0;

    // Initialize the prefix sum array
    prefix_sums[0] = 0;
    for (int i = 1; i <= n; ++i) {
        long long val;
        cin >> val;
        prefix_sums[i] = (prefix_sums[i - 1] + val) % m;
        if (i > 1) {
            // Insert prefix sums from previous elements into the map
            count_map[prefix_sums[i - 2]]++;
        }
    }

    // Handle circular property by processing second half
    for (int i = n + 1; i <= 2 * n; ++i) {
        prefix_sums[i] = (prefix_sums[i - 1] + a[i - n]) % m;
        // Count valid subarrays ending at this position
        result += count_map[prefix_sums[i]];
        count_map[prefix_sums[i - n]]++;
    }

    cout << result << "\n";
    return 0;
}