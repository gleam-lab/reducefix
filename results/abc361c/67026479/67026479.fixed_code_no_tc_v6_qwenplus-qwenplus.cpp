#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int m = n - k;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // If we can select only one element, the min and max are the same, so difference is 0
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Create a list of pairs: (value, original index)
    vector<pair<int, int>> indexed_a(n);
    for (int i = 0; i < n; ++i) {
        indexed_a[i] = {a[i], i};
    }

    // Sort by value to find candidates for minimum and maximum in subsequence B
    sort(indexed_a.begin(), indexed_a.end());

    // Sliding window over the sorted values to find the smallest range
    // that allows selecting m elements where all indices can be ordered in original sequence
    multiset<int> indices;
    int result = numeric_limits<int>::max();

    for (int i = 0; i + m - 1 < n; ++i) {
        int j = i + m - 1;
        // We consider the subarray from indexed_a[i] to indexed_a[j]
        // Get the indices of these elements in the original array
        vector<int> selected_indices;
        for (int x = i; x <= j; ++x) {
            selected_indices.push_back(indexed_a[x].second);
        }
        // Sort the indices to verify they can form a valid subsequence in original order
        sort(selected_indices.begin(), selected_indices.end());
        // Count how many elements would be removed between first and last
        int removed = 0;
        for (int x = 1; x < m; ++x) {
            if (selected_indices[x] - selected_indices[x - 1] > 1) {
                removed += selected_indices[x] - selected_indices[x - 1] - 1;
            }
        }
        // Total removed should be <= K to be valid
        if ((selected_indices.back() - selected_indices.front() + 1 - m) <= k) {
            result = min(result, indexed_a[j].first - indexed_a[i].first);
        }
    }

    cout << result << endl;
}