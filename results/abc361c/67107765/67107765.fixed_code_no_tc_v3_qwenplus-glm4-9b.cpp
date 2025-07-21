#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // If removing all elements, the answer is 0 as there will be no remaining elements.
    if (k == n) {
        cout << 0 << endl;
        return 0;
    }

    // Calculate the minimum difference by removing the first k elements.
    int min_diff = a[k - 1] - a[0];

    // Try to remove different elements to find the minimum possible difference.
    for (int i = 0; i <= k; i++) {
        // We are considering removing the first i elements.
        int max_val = a[k - 1]; // The maximum value will be the last remaining element.
        int min_val = a[i]; // The minimum value will be the element after the first i elements.
        int diff = max_val - min_val;
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;
    return 0;
}