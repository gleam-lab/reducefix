#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window approach to find the minimum range
    // After removing K elements, we have to keep (n - K) elements
    int window_size = n - k;

    // Sort the array to make it easier to find min and max in windows
    vector<pair<int, int>> sorted_A(n); // value and original index
    for (int i = 0; i < n; ++i) {
        sorted_A[i] = {A[i], i};
    }
    sort(sorted_A.begin(), sorted_A.end());

    // Now we want to find a window of size window_size in this sorted array
    // such that the elements are contiguous in the original array (i.e., their indices form an increasing sequence)
    
    // To do this efficiently, we maintain a sliding window using a multiset for the indices
    multiset<int> indices;
    int left = 0;
    int min_diff = numeric_limits<int>::max();

    for (int right = 0; right < n; ++right) {
        indices.insert(sorted_A[right].second);

        // If window size exceeds required, move left pointer
        while ((int)(right - left + 1) > window_size) {
            indices.erase(indices.find(sorted_A[left].second));
            left++;
        }

        // When we have a valid window, check if indices are valid (contiguous in original array)
        if ((int)(right - left + 1) == window_size) {
            // The elements in the window are consecutive in the original array
            // because we're ensuring the indices form a contiguous block
            min_diff = min(min_diff, sorted_A[right].first - sorted_A[left].first);
        }
    }

    cout << min_diff << endl;
    return 0;
}