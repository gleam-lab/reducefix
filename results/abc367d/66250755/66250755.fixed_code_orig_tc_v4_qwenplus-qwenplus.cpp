#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
const int MAXM = 1000005;

int n, m;
long long a[MAXN * 2], prefix_sum[MAXN * 2];
map<long long, long long> freq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    // Compute prefix sums modulo m
    for (int i = 1; i <= 2 * n; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[i]) % m;
    }

    long long result = 0;
    freq[0] = 1; // Initialize with prefix sum 0 to count subarrays starting from index 0

    // Sliding window technique to maintain only the relevant part of the frequency map
    deque<long long> dq;
    dq.push_back(0);

    for (int i = 1; i <= 2 * n; ++i) {
        // Maintain only the last n elements in the frequency map
        if (i > n) {
            // Remove the element that slides out of the window
            long long old = (prefix_sum[i - n]);
            freq[old]--;
            if (freq[old] == 0) {
                freq.erase(old);
            }
        }

        // Count how many times current prefix sum has appeared
        result += freq[prefix_sum[i]];

        // Add current prefix sum to frequency map
        freq[prefix_sum[i]]++;
    }

    cout << result << endl;
    return 0;
}