#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will consider all windows of size n - K
    int window_size = n - k;
    int min_diff = numeric_limits<int>::max();

    // Sliding window: check each subsequence of length (n - k)
    for (int i = 0; i + window_size <= n; ++i) {
        int j = i + window_size - 1;
        // To find min and max in the current window efficiently,
        // we use a multiset to simulate a sliding window.
        multiset<int> ms;
        for (int idx = i; idx <= j; ++idx) {
            ms.insert(A[idx]);
        }
        int current_diff = *ms.rbegin() - *ms.begin();
        min_diff = min(min_diff, current_diff);
    }

    cout << min_diff << endl;
    return 0;
}