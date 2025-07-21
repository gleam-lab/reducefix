#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
int n, k;
int a[MAX], b[MAX];
int prefix[MAX];

// Utility function to calculate the sum of elements from index i to j in b
long long sumRange(int i, int j) {
    return prefix[j] - (i > 0 ? prefix[i - 1] : 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        // Initialize prefix sum array
        prefix[0] = 0;
        for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + b[i - 1];

        // Pairing a and b and sort by a in descending order
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) pairs[i] = {a[i], b[i]};
        sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());

        long long min_value = LLONG_MAX;
        long long sum_b = 0; // Sum of B elements in the current subset

        // Calculate the sum of B elements for the first window of size k
        for (int i = 0; i < k; i++) sum_b += pairs[i].second;

        // Calculate the minimum value for the first window
        min_value = min(min_value, pairs[0].first * sum_b);

        // Sliding window to calculate the minimum value for the rest of the windows
        for (int i = k; i < n; i++) {
            sum_b += pairs[i].second - pairs[i - k].second;
            min_value = min(min_value, pairs[i].first * sum_b);
        }

        cout << min_value << '\n';
    }

    return 0;
}