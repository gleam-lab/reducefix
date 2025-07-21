#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // First, sort the vector to easily find the range of elements to consider removing
    sort(v.begin(), v.end());

    // We need to consider removing at most k elements, so we should look at the elements in the middle
    // of the sorted array first, as removing extreme values (smallest or largest) will likely not minimize
    // the maximum value of B minus the minimum value of B.
    vector<int> left(n), right(n);

    // Calculate the minimum possible max value of the subsequence from left to current index
    left[0] = v[0];
    for (int i = 1; i < n; ++i) {
        left[i] = min(left[i - 1], v[i]);
    }

    // Calculate the maximum possible min value of the subsequence from current index to right
    right[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        right[i] = max(right[i + 1], v[i]);
    }

    // Now we traverse the array and try to find the minimum possible value of
    // max value of B minus the minimum value of B by potentially removing k elements.
    int min_diff = INT_MAX;
    for (int i = 0; i <= n - k; ++i) {
        int j = i + k - 1;
        int max_val = max(v[j], right[i]);
        int min_val = min(left[j], v[i]);
        min_diff = min(min_diff, max_val - min_val);
    }

    cout << min_diff << endl;
    return 0;
}