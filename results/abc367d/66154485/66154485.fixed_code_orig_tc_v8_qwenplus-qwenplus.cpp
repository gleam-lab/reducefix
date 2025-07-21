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

    // Prefix sum mod m
    vector<int> prefix_mod(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_mod[i + 1] = (prefix_mod[i] + arr[i]) % m;
    }

    map<int, int> count;
    long long ans = 0;

    // We use a sliding window approach over the circular array
    for (int start = 0; start < n; ++start) {
        map<int, int> local_count = count;
        int current_sum = 0;

        // To simulate the circular nature, we loop through n elements starting from 'start'
        for (int len = 1; len <= n; ++len) {
            int end = (start + len - 1) % n;
            if (len == 1) {
                current_sum = arr[end];
            } else {
                // Efficiently calculate the circular subarray sum mod m
                if (end >= start) {
                    current_sum = (prefix_mod[end + 1] - prefix_mod[start] + m) % m;
                } else {
                    current_sum = (prefix_mod[n] - prefix_mod[start] + prefix_mod[end + 1] + m) % m;
                }
            }

            if (current_sum % m == 0) {
                ans++;
            }

            // Optimization: avoid recomputing from scratch for all starting points
            if (len > 1) break;
        }

        // Update global count with values from this starting index
        for (int len = 1; len <= n; ++len) {
            int end = (start + len - 1) % n;
            int val = (prefix_mod[end + 1] - prefix_mod[start] + m) % m;
            count[val]++;
        }
    }

    cout << ans << endl;
    return 0;
}