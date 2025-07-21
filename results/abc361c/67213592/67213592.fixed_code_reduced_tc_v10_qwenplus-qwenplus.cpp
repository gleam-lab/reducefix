#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will keep the smallest N - K values in a multiset
    int m = n - k;

    // Create a vector of pairs (value, index)
    vector<pair<int, int>> valIndex(n);
    for (int i = 0; i < n; ++i) {
        valIndex[i] = {A[i], i};
    }

    // Sort by value to get the smallest m elements
    sort(valIndex.begin(), valIndex.end());

    // Now among these m elements, we need to pick those with m smallest values,
    // but also maintain their relative order from original array.
    // So we take the first m elements from sorted valIndex,
    // then sort them by index to restore original order.

    // Take the first m elements and sort them by index
    vector<int> indices;
    for (int i = 0; i < m; ++i) {
        indices.push_back(valIndex[i].second);
    }
    sort(indices.begin(), indices.end());

    // Get the values in original order
    vector<int> selectedValues;
    for (int idx : indices) {
        selectedValues.push_back(A[idx]);
    }

    // Compute min and max of this sequence
    int minVal = *min_element(selectedValues.begin(), selectedValues.end());
    int maxVal = *max_element(selectedValues.begin(), selectedValues.end());

    cout << maxVal - minVal << endl;

    return 0;
}