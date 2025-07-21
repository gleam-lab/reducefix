#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will try to keep a subsequence of N - K elements such that
    // the difference between the max and min in that subsequence is minimized.
    // Since N can be up to 2e5, we need an O(N log N) approach.

    // Create a list of pairs: value and original index
    vector<pair<int, int>> indexed_A;
    for (int i = 0; i < n; ++i) {
        indexed_A.emplace_back(A[i], i);
    }

    // Sort by value
    sort(indexed_A.begin(), indexed_A.end());

    // We'll slide a window over the sorted array to find the minimum range
    // that allows us to pick N-K elements whose indices are in valid order
    int window_size = n - k;
    int ans = numeric_limits<int>::max();

    for (int i = 0; i + window_size <= n; ++i) {
        vector<int> indices;
        for (int j = i; j < i + window_size; ++j) {
            indices.push_back(indexed_A[j].second);
        }
        // Check if these indices can be kept in the original sequence
        // That means there exists a subsequence of length N - K with those indices
        // To verify this, we check if the indices are increasing (can be formed from original order)
        // This is always true because we're choosing contiguous elements in sorted A,
        // and their indices are not necessarily contiguous but must be increasing

        // However, we only need to ensure that we can form a subsequence of length N-K
        // with the remaining elements. Since we remove exactly K elements,
        // any subset of N-K elements may not be achievable due to ordering constraints.

        // The correct way is to ensure that the indices of the selected elements
        // can appear in the same order as in the original array.
        // So we sort the indices and check whether they are increasing in original array
        sort(indices.begin(), indices.end());
        bool valid = true;
        for (int j = 1; j < indices.size(); ++j) {
            if (indices[j] < indices[j-1]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            ans = min(ans, indexed_A[i + window_size - 1].first - indexed_A[i].first);
        }
    }

    cout << ans << endl;
    return 0;
}