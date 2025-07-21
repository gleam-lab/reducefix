#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // The maximum value that can be achieved by removing K elements from both ends
    int max_min_diff = a[n - k] - a[k - 1];

    // Consider the case where we need to remove more than K elements from one end
    for (int i = 1; n - k - i >= 0; ++i) {
        int left_min = a[i - 1]; // Minimum value if we take i elements from the left end
        int right_max = a[n - k - i]; // Maximum value if we take n-k-i elements from the right end
        max_min_diff = min(max_min_diff, right_max - left_min);
    }

    cout << max_min_diff << endl;
    return 0;
}