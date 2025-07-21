#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window approach to find the minimal range
    // After removing exactly K elements, we can keep (n - K) consecutive elements
    // The minimal difference between max and min in any such subsequence is our answer

    // Since we are looking for the minimum possible value of (max - min),
    // we try all windows of size (n - K) in the sorted array.

    sort(A.begin(), A.end());

    int result = numeric_limits<int>::max();
    int window_size = n - K;

    for (int i = 0; i + window_size <= n; ++i) {
        int current_min = A[i];
        int current_max = A[i + window_size - 1];
        result = min(result, current_max - current_min);
    }

    cout << result << endl;

    return 0;
}